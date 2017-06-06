/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:23:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/06 08:34:34 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void   parse_the_values3_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'X' && !temp->type)
	{
		temp->type = HEXAM;
		if (temp->cast == LONG || temp->cast == LONG_LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else
			temp->hexa = va_arg(args, unsigned int); 

	}
	if (str[i] == 'c' && !temp->type)
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

void   parse_the_values3_2(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'C' && !temp->type)
	{
		temp->type = WCHAR;
		temp->wc = va_arg(args, wchar_t);
	}
	if (str[i] == 'U' && !temp->type)
	{
		temp->type = INTLU;
		temp->lunbr = va_arg(args, long unsigned int);
	}
}

void   parse_the_values3_3(va_list args, t_type *temp)
{
	temp->type = INTI;	
	temp->number = va_arg(args, long long);
	while (temp->number > 65535)
		temp->number -= 65535;
	temp->cast = 0;
}

void   parse_the_values3_4(va_list args, t_type *temp)
{
	temp->type = INTI;
	temp->number = va_arg(args, long long);
	temp->cast = LONG_LONG;
	if (temp->number < 0)
		temp->number *= -1;
	temp->spaces = 0;
}

void   parse_the_values3(va_list args, t_type *temp, char *str, int i)
{
	parse_the_values3_1(args, temp, str, i);
	parse_the_values3_2(args, temp, str, i);
	if (str[i] == 'u' && !temp->type)
	{
		if (temp->cast == HH_CAST)
		{
			temp->type = INTI;
			temp->number = va_arg(args, long long);
			while (temp->number > 256)
				temp->number -= 256;
			temp->cast = 0;
		}
		else if (temp->cast == H_CAST)
			parse_the_values3_3(args, temp);
		else if (temp->cast == LONG_LONG || temp->cast == LONG || temp->cast == J_CAST || temp->cast == Z_CAST)
		{
			temp->type = INTLU;
			temp->lunbr = va_arg(args, long unsigned int);		
		}
		else
			parse_the_values3_4(args, temp);
	}
}