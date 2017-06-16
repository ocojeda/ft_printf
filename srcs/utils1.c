/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:22:32 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 05:28:33 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_putchar_spe(char c)
{
	ft_putchar(c);
	return (1);
}

int			total_int(int t, int total)
{
	while (t)
	{
		total++;
		t /= 10;
	}
	return (total);
}

int			total_long(long long t, int total)
{
	while (t)
	{
		total++;
		t /= 10;
	}
	return (total);
}

void		reset_type2(t_type *temp)
{
	temp->plus = 0;
	temp->negative = 0;
	temp->hash_tag = 0;
	temp->pres_left = 0;
	temp->pres_right = 0;
	temp->no_pres_left = 0;
	temp->no_pres_right = 0;
	temp->spaces = 0;
	temp->nopoint = 0;
	temp->point = 0;
	temp->cast = 0;
	temp->cero = 0;
	temp->number = 0;
	temp->octal = 0;
}

void		reset_type(t_type *temp)
{
	temp->type = 0;
	temp->unbr = 0;
	temp->lunbr = 0;
	temp->lnbr = 0;
	temp->pointer = 0;
	temp->fnumber = 0;
	temp->str = NULL;
	temp->c = 0;
	temp->wstr = NULL;
	temp->wc = 0;
	temp->hexa = 0;
	ft_bzero(temp->str1, BUFF_SIZE);
	reset_type2(temp);
}
