/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:23:15 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 10:48:59 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_the_values3_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'X' && !temp->type)
	{
		temp->type = HEXAM;
		if(temp->cast)
		{
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		if (temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		if (temp->cast == Z_CAST)
			temp->hexa = va_arg(args, size_t);
		if (temp->cast == H_CAST)
			temp->hexa = va_arg(args, unsigned int);
		if (temp->cast == HH_CAST)
			temp->hexa = va_arg(args, unsigned int);
		}
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
			temp->c = va_arg(args, uintmax_t);
	}
}

void	parse_the_values3_2(va_list args, t_type *temp, char *str, int i)
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
/*
void	parse_the_values3_3(va_list args, t_type *temp)
{
	temp->type = INTU;
	temp->unbr = va_arg(args, long long);
	//while (temp->number > 65535)
	//	temp->number -= 65535;
	temp->cast = 0;
}*/
/*
void	parse_the_values3_4(va_list args, t_type *temp)
{
	temp->type = INTU;
	temp->unbr = va_arg(args, unsigned int);
	//if (temp->unbr >= 4294967295)
	//	temp->cast = LONG_LONG;
	//temp->spaces = 0;
}*/

void	parse_the_values3(va_list args, t_type *temp, char *str, int i)
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
			//temp->cast = 0;
		}
		else
			temp->unbr = va_arg(args, uintmax_t);
	}
}
