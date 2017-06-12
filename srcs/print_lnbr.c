#include "../includes/ft_printf.h"

void			ft_printlongnbr(long long ll)
{
	if (ll == LONG_LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (ll < 0)
	{
		ft_putchar('-');
		ll = -ll;
	}
	if (ll >= 10)
	{
		ft_printlongnbr(ll / 10);
		ft_printlongnbr(ll % 10);
	}
	else
		ft_putchar(ll + '0');
}

int	 set_presschar_for_long2(t_type *temp, int total, int i, int a)
{
	long long t;

	t = temp->lnbr;
	if (temp->plus && temp->lnbr >= 0)
	{
		ft_putchar('+');
		a++;
		if (temp->lnbr == 0)
			a++;
	}
	if (t < 0)
	{
		ft_putchar('-');
		temp->lnbr *= -1;
	}
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i > 0)
	{
		i--;
		ft_putchar('0');
		a++;
	}
	return (a);
}

int	 set_presschar_for_long(t_type *temp, int total)
{
	int i;
	int a;
	long long t;

	t = temp->lnbr;
	i = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces && 
	t > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
		{
			ft_putchar(' ');
			a--;
		}
	}
	a = i;
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
	a += i;
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	return (set_presschar_for_long2(temp, total, i , a) + total);
}
int	 set_presschar_for_long_inverse(t_type *temp, int total)
{
	int i;
	int a;
	long long t;

	t = temp->lnbr;
	i = 0;
	if ((temp->pres_left < total + temp->spaces) && temp->spaces && t > 0)
	{
		i = temp->spaces;
		a = temp->spaces;
		while (a)
		{
			ft_putchar(' ');
			a--;
		}
	}
	a = i;
	i = 0;
	if (temp->pres_right < total)
		temp->pres_right = total - temp->negative;
	if (temp->pres_left > temp->pres_right)
	{
		i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
		a += i;
	}
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (temp->pres_right > total - temp->negative)
		i = temp->pres_right - total + temp->negative;
	while (i > 0)
	{
		i--;
		ft_putchar('0');
		a++;
	}
	return (a + total);
}
int		cast_mng_forlong(t_type *temp, long long t, int total)
{
	if (temp->cast == HH_CAST)
	{
		if (temp->lnbr < -128)
		{
			while (temp->lnbr <= -128)
			temp->lnbr += 256;
			t = temp->lnbr;
			//temp->number = t;
		}
		else if (temp->lnbr >= 128)
			{
				while (temp->lnbr >= 128)
					temp->lnbr -= 256;
				t = temp->lnbr;
			}
		//else if(t >= 128)
		//{
			//a faire une fonction que transforme le n dans une echelle de -128 a 128
		//	temp->number = temp->number * -1;
			//t = temp->number;
		//}
	}
	if (temp->cast == H_CAST && temp->lnbr > 32767)
	{
		while(temp->lnbr > 32767)
			temp->lnbr -= 32768*2;
		t = temp->lnbr;
	}
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	return (total);
}
int	 ft_putllnbr(t_type *temp)
{
	long long t;
	int total;
	int i;

	i = 0;
	total = 0;
	t = temp->lnbr;
		if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
	 && temp->lnbr == 0)
		return (0);
	while (t != 0)
	{
		total++;
		t /= 10;
	}
    t = temp->lnbr;
	//total = cast_mng_forlong(temp, t, 0);
    if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right && temp->plus)
			temp->pres_right = temp->pres_left -1;
		else if (temp->pres_left && !temp->pres_right)
			temp->pres_right = temp->pres_left;
	}
	if (temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
	{
		if (temp->spaces)
		{
			i = temp->spaces;
			total += temp->spaces;
			if (t < 0)
			{
				total--;
				i--;
			}
			while (i--)
				ft_putchar(' ');
		}
		ft_printlongnbr(t);
		if (t < 0)
			return total +1;
		else if (t == 0)
			return 1;
		else
			return (total);
	}
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
	 && t == 0)
			return (0);
	
	if (temp->pres_left > temp->pres_right + total && temp->negative)	
	{
		int temp1;
		if (temp->pres_right > total)
		{
			temp1 = temp->pres_right - total;
			if (temp->number > 0 && temp->plus)
			{
				ft_putchar('+');
				total++;
				temp->plus = 0;
			}
			while (temp1--)
			{
				temp->pres_right--;
				ft_putchar('0');
				total++;
			}
		}
		ft_printlongnbr(t);
		if (t < 0)
		{
			temp->lnbr *= -1;
			total++;
		}
		i = set_presschar_for_long_inverse(temp, total);
	}
	else 
	{
		if(temp->lnbr < 0)
		{
			total++;
			temp->negative = NEGATIVE;
			t *= -1;
		}
		i = set_presschar_for_long(temp, total);
		ft_printlongnbr(temp->lnbr);
		if (t == 0 && temp->pres_right)
			i++;
	}
	return (i);
}