
#include "../includes/ft_printf.h"

int			is_left_for_long(t_type *temp, int total, long long t, int i)
{
	int temp1;

	if (temp->pres_right > total)
	{
		temp1 = temp->pres_right - total;
		if (temp->lnbr > 0 && temp->plus)
		{
			total += ft_putchar_spe('+');
			temp->plus = 0;
		}
		while (temp1--)
		{
			temp->pres_right -= ft_putchar_spe('0');
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
	return (i);
}

int			choose_for_long(t_type *temp, int total, long long t, int i)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)
		i = is_left_for_long(temp, total, t, i);
	else
	{	
		t = temp->lnbr;
		if (t < 0 && temp->cero && temp->pres_left)
			temp->pres_left--;
		if (temp->lnbr == 0 && temp->pres_left && !temp->pres_right)
		{
			i = set_presschar_for_long(temp, total);
			return (i);
		}
		i = set_presschar_for_long(temp, total);
		if (temp->cero && temp->lnbr == 0)
			i--;
		else
			ft_printlongnbr(temp->lnbr);
		if (t < 0)
			i++;
	}
	if (t == 0 && temp->pres_right && !temp->plus)
		i++;
	return (i);
}
