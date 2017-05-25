/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putlunbr.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ocojeda- <ocojeda-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/05/15 15:25:14 by myernaux		  #+#	#+#			 */
/*   Updated: 2017/05/24 11:37:19 by ocojeda-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"
int	 set_presschar_for_ul(t_type *temp, int total)
{
	int i;
	int a;

	i = 0;
	
	if((temp->pres_left < total + temp->spaces) && temp->spaces && 
	temp->lunbr > 0)
		{
			i = temp->spaces;
			a = temp->spaces;
			while(a)
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
			 i = temp->pres_left - temp->pres_right 
			 - temp->plus - temp->negative;
		a += i;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		if (temp->plus && temp->number >= 0 && !temp->negative)
			{
				ft_putchar('+');
				a++;
			}
		if(temp->negative)
			{
				ft_putchar('-');
				a++;
			}
		if (temp->pres_right > total - temp->negative)
				i = temp->pres_right - total + temp->negative;
		a += i - temp->negative;
		while (i > 0)
		{
		   i--;
		   ft_putchar('0');
		}
	return (a + total);
}
int	ft_putlunbr(long unsigned int lunbr, int all)
{
	if (lunbr == ULONG_MAX)
	{
		ft_putstr("18446744073709551615");
		return 20;
	}
	if (lunbr / 10)
		ft_putlunbr(lunbr / 10, all);
	ft_putchar('0' + (lunbr % 10));
	return all;
}

int	print_lunumber(t_type *temp)
{
	long unsigned int t;
	int total;
	int all;

	if(temp->lunbr == 0)
		total = 1;
	else 
		total = 0;
	t = temp->lunbr;
	while (t != 0)
	{
		total++;
		t /= 10;
	}
	all = set_presschar_for_ul(temp, total);
	all = ft_putlunbr(temp->lunbr, all);
	return (all);
}