/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   print_number.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ocojeda- <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/06/08 14:22:17 by ocojeda-		  #+#	#+#			 */
/*   Updated: 2017/06/08 14:54:06 by ocojeda-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	 set_presschar_for_int2(t_type *temp, int total, int i, int a)
{
	int t;

	t = temp->number;
	
	if (temp->plus && temp->number >= 0)
	{
		ft_putchar('+');
		a++;
		if (temp->number == 0)
			a++;
	}
	if (t < 0)
	{
		ft_putchar('-');
		temp->number *= -1;
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

int	 set_presschar_for_int(t_type *temp, int total)
{
	int i;
	int a;
	short t;

	t = temp->number;
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
	return (set_presschar_for_int2(temp, total, i , a) + total);
}

int	 set_presschar_for_int_inverse(t_type *temp, int total)
{
	int i;
	int a;
	short t;

	t = temp->number;
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
int		cast_mng(t_type *temp, int t, int total)
{
	if (temp->cast == HH_CAST)
	{
		if (temp->number < -128)
		{
			while (temp->number <= -128)
			temp->number += 256;
			t = temp->number;

		}
		else if (temp->number >= 128)
			{
				while (temp->number >= 128)
					temp->number -= 256;
				t = temp->number;
			}
	}
	if (temp->cast == H_CAST && temp->number > 32767)
	{
		while(temp->number > 32767)
			temp->number -= 32768*2;
		t = temp->number;
	}
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	return (total);
}
int		is_left(t_type *temp, int total, int t, int i)
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
	ft_putnbr(t);
	if (t < 0)
	{
		temp->number *= -1;
		total++;
	}
	i = set_presschar_for_int_inverse(temp, total);
	return (i);
}
int		choose_l_o_r(t_type *temp, int total, int t, int i)
{
	if (temp->pres_left > temp->pres_right + total && temp->negative)	
		i = is_left(temp, total, t, i);
	else 
	{
		t = temp->number;
		if (t < 0 && temp->cero && temp->pres_left)
			temp->pres_left--;
		if (temp->number == 0 && temp->pres_left && !temp->pres_right)
		{
			i = set_presschar_for_int(temp, total);
			return (i);
		}
		i = set_presschar_for_int(temp, total);
		if (temp->cero && temp->number == 0)
			i--;
		else
			ft_putnbr(temp->number);
		if (t < 0)
			  i++;
	}
	if (t == 0 && temp->pres_right)
		i++;
	return (i);
}

int		negative_press_right(t_type *temp, int total, int i)
{
	if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right)
		{
			temp->pres_right = temp->pres_left - 1;
			temp->pres_left = 0;
		}
	}
	temp->pres_left--;
	i = set_presschar_for_int(temp, total);
	if (temp->number < 0)
		ft_putnbr(-temp->number);
	else 
		ft_putnbr(temp->number);
	return (i + 1);
}

int		cero_manager_int(t_type *temp, int total, int t, int i)
{
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
		ft_putnbr(temp->number);
		if (t < 0)
			return (total + 1);
		else if (t == 0)
			return (1);
		else
			return (total);
	}
	return(0);
}
int		print_number(t_type *temp)
{
	int t;
	int total;
	int i;

	i = 0;
	total = 0;
	t = temp->number;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
	 && temp->number == 0)
		return (0);
	if (temp->cast == LONG_LONG || temp->cast == LONG 
	|| temp->cast == Z_CAST || temp->cast == J_CAST)
		return (ft_putllnbr(temp));
	//ft_putnbr(temp->pres_left);
	//ft_putnbr(temp->pres_right);
	//ft_putnbr(temp->cero);

	total = cast_mng(temp, t, 0);
	t = temp->number;
	cast_manager3(temp, t);
	if (t < 0 && (temp->pres_left > temp->pres_right + total) && !temp->negative)
		return (negative_press_right(temp, total, i));
	if (temp->nopoint && temp->pres_right && !temp->pres_left && t < 0)
		temp->pres_right--;
	if((i = cero_manager_int(temp, total, t , i)))
		return (i);
	return (choose_l_o_r(temp, total, t, i));
}