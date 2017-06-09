/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:22:32 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/08 14:59:21 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_putchar_spe(char c)
{
	ft_putchar(c);
	return (1);
}

void		ft_printlongnbr(long long ll)
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

static int	cero_manager1(t_type *temp, int i, int total, long long t)
{
	if (temp->no_pres_left == 1 && temp->no_pres_right == 1
			&& temp->plus == 0)
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
	return (i);
}

int			cero_manager(t_type *temp, int i, int total, long long t)
{
	if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right && temp->plus)
			temp->pres_right = temp->pres_left - 1;
		else if (temp->pres_left && !temp->pres_right)
			temp->pres_right = temp->pres_left;
	}
	return (cero_manager1(temp, i, total, t));
}

int			cast_for_number(t_type *temp, int i, int total, int t)
{
	
	if (temp->cast == H_CAST && temp->number > 32767)
		temp->number = temp->number * -1;
	i = temp->number;
	if (temp->cast == HH_CAST)
	{
		if (temp->number < -128)
		{
			while (temp->number <= -128)
				temp->number += 256;
			//temp->number = t;
		}
		else if (temp->number >= 256)
			while (temp->number > 128)
				temp->number -= 256;
		else if (t >= 128)
			temp->number = temp->number * -1;
	}
	//ft_printlongnbr(t);
	//ft_printlongnbr(temp->number);
	while (i)
	{
		total++;
		i /= 10;
	}
	return (total);
}
