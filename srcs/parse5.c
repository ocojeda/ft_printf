/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 04:44:29 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 05:27:29 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		smalldparser(va_list args, t_type *temp, int i)
{
	temp->type = INTI;
	if (temp->cast)
	{
		if (temp->cast == HH_CAST || temp->cast == H_CAST)
			temp->number = va_arg(args, int);
		else
		{
			temp->type = INTL;
			if (temp->cast == J_CAST)
				temp->lnbr = va_arg(args, intmax_t);
			else if (temp->cast == Z_CAST)
				temp->lnbr = va_arg(args, size_t);
			else if (temp->cast == LONG)
				temp->lnbr = va_arg(args, long long);
			else
				temp->lnbr = va_arg(args, long long);
			return (i);
		}
	}
	else
		temp->number = va_arg(args, int);
	return (i);
}

int		capitaldparser(va_list args, t_type *temp, int i)
{
	temp->type = INTL;
	if (temp->cast)
	{
		if (temp->cast == HH_CAST || temp->cast == H_CAST)
			temp->lnbr = va_arg(args, long long);
		else if (temp->cast == J_CAST)
			temp->lnbr = va_arg(args, intmax_t);
		else if (temp->cast == Z_CAST)
			temp->lnbr = va_arg(args, size_t);
		else if (temp->cast == LONG)
			temp->lnbr = va_arg(args, long long);
		else
			temp->lnbr = va_arg(args, long long);
		return (i);
	}
	else
		temp->lnbr = va_arg(args, long long);
	return (i);
}

int		o_parser(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'o' && !temp->type)
	{
		temp->type = OCTAL;
		if (temp->cast)
		{
			if (temp->cast == LONG_LONG || temp->cast == LONG)
			{
				temp->type = OCTALM;
				temp->octal = va_arg(args, unsigned long long);
			}
			else if (temp->cast == J_CAST)
				temp->octal = va_arg(args, uintmax_t);
			else if (temp->cast == Z_CAST)
				temp->octal = va_arg(args, size_t);
			else
				temp->octal = va_arg(args, unsigned int);
			return (1);
		}
		else
			temp->octal = va_arg(args, unsigned int);
		return (1);
	}
	return (0);
}