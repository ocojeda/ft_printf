/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:22:32 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/07 15:27:11 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void            ft_printlongnbr(long long ll)
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

int		cero_manager(t_type *temp, int i, int total, long long t)
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
		ft_printlongnbr(t);
		if (t < 0)
			return (total + 1);
		else if (t == 0)
			return (1);
		else
			return (total);
	}
	return i;
}

int		cast_for_number(t_type *temp, int i)
{
	int t;
	int total;

	if (temp->cast == H_CAST && temp->number > 32767)
		temp->number = temp->number * -1;
	total = 0;
	t = temp->number;
	i = temp->number;
	if (temp->cast == HH_CAST)
	{
		if (t < -128)
		{
			while (t <= -128)
				t += 256;
			temp->number = t;
		}
		else if (t >= 256)
			while (t > 128)
				temp->number -= 256;
		else if (t >= 128)
			//a faire une fonction que transforme le n dans une echelle de -128 a 128
			temp->number = temp->number * -1;
	}
	while (i)
	{
		total++;
		i /= 10;
	}
	return (total);
}
