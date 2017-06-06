/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:30:48 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/06 08:33:19 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void  parse_the_values2_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == '%' && !temp->type)
		temp->type = D_MOD;
	if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
	{
		temp->type = INTI;
		temp->number = va_arg(args, long long);
	}
	if (str[i] == 'D' && !temp->type)
	{
		temp->type = INTI;
		temp->cast = LONG_LONG;
		temp->number = va_arg(args, long long);
	}
	if (str[i] == 'S' && !temp->type)
	{
		temp->type = WSTR;
		temp->wstr = va_arg(args, wchar_t *);
		if (temp->wstr == 0 || temp->wstr == NULL)
		{
			temp->type = STR;
			ft_strcpy(temp->str1, "(null)");
		}
	}
}

void  parse_the_values2_2(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 's' && !temp->type)
	{
		if (temp->cast == LONG)
		{
			temp->type = WCHAR;
			temp->wc = va_arg(args, wchar_t);
		}
		else
		{
			temp->type = STR;
			char *str1 = va_arg(args, char *);
			if (str1 == NULL)
				ft_strcpy(temp->str1, "(null)");
			else
				ft_strcpy(temp->str1, str1);
		}
	}
}

void  parse_the_values2(va_list args, t_type *temp, char *str, int i)
{
	parse_the_values2_1(args, temp, str, i);
	parse_the_values2_2(args, temp, str, i);
	if (str[i] == 'x' && !temp->type)
	{
		temp->type = HEXA;
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else if (temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		else
			temp->hexa = va_arg(args, unsigned int);
	}
}

void   parse_the_values4(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'p' && !temp->type)
	{
		temp->type = POINTER_ADRESSE;
		temp->pointer = va_arg(args, unsigned long);
	}
	if (str[i] == 'o' && !temp->type)
	{
		temp->type = OCTAL;
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->octal = va_arg(args, unsigned long long);
		else if (temp->cast == J_CAST)
			temp->octal = va_arg(args, uintmax_t);
		else
			temp->octal = va_arg(args, unsigned int);
	}
	if (str[i] == 'O' && !temp->type)
	{
		temp->type = OCTALM;
		temp->number = va_arg(args, unsigned long long);
	}
}