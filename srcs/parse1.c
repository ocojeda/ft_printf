/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:23:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:45:30 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		capitalxparser(va_list args, t_type *temp)
{
	temp->type = HEXAM;
	if (temp->cast)
	{
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else if (temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		else if (temp->cast == Z_CAST)
			temp->hexa = va_arg(args, size_t);
		else
			temp->hexa = va_arg(args, unsigned int);
		return ;
	}
	else
		temp->hexa = va_arg(args, unsigned int);
}

void		parse_the_values3_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'X')
	{
		capitalxparser(args, temp);
		return ;
	}
	if (str[i] == 'c')
	{
		temp->type = CHAR;
		if (temp->cast == LONG_LONG || temp->cast == LONG)
		{
			temp->type = WCHAR;
			temp->wc = va_arg(args, wchar_t);
		}
		else
			temp->c = va_arg(args, int);
	}
}

void		parse_the_values3_2(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'C')
	{
		temp->type = WCHAR;
		temp->wc = va_arg(args, wchar_t);
		return ;
	}
	if (str[i] == 'U')
	{
		temp->type = INTLU;
		temp->lunbr = va_arg(args, long unsigned int);
	}
}

void		parse_the_values3(va_list args, t_type *temp, char *str, int i)
{
	parse_the_values3_1(args, temp, str, i);
	parse_the_values3_2(args, temp, str, i);
	if (str[i] == 'u' && !temp->type)
	{
		temp->type = INTU;
		if (temp->plus)
			temp->plus = 0;
		if (temp->cast)
		{
			if (temp->cast == HH_CAST)
				temp->unbr = va_arg(args, unsigned int);
			if (temp->cast == H_CAST)
				temp->unbr = va_arg(args, unsigned int);
			if (temp->cast == LONG_LONG || temp->cast == LONG ||
					temp->cast == J_CAST || temp->cast == Z_CAST)
			{
				temp->type = INTLU;
				temp->lunbr = va_arg(args, uintmax_t);
			}
		}
		else
			temp->unbr = va_arg(args, uintmax_t);
	}
}
