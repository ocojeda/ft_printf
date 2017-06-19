/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:30:48 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:18:56 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_the_values2_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == '%' && !temp->type)
	{
		temp->type = D_MOD;
		return (i);
	}
	if ((str[i] == 'd' || str[i] == 'i'))
		return (smalldparser(args, temp, i));
	if (str[i] == 'D' && !temp->type)
		return (capitaldparser(args, temp, i));
	if (str[i] == 'S' && !temp->type)
	{
		temp->type = WSTR;
		temp->wstr = va_arg(args, wchar_t *);
		if (temp->wstr == 0 || temp->wstr == NULL)
		{
			temp->type = STR;
			temp->str = "(null)\0";
		}
		//ft_putnbr(temp->point);
		if (temp->negative)
			return (-1);
		if(temp->cero && !temp->point)
			return -1;
	}
	return (i);
}

void	parse_the_values_forstr(va_list args, t_type *temp)
{
	char *str1;

	if (temp->cast == LONG || temp->cast == LONG_LONG)
	{
		temp->type = WSTR;
		temp->wstr = va_arg(args, wchar_t *);
		if (temp->wstr == 0 || temp->wstr == NULL)
		{
			temp->type = STR;
			temp->str = "(null)\0";
		}
		return ;
	}
	else
	{
		temp->type = STR;
		str1 = va_arg(args, char *);
		if (str1 == NULL)
			temp->str = "(null)\0";
		else if (str1[0] == 0)
			temp->str = "\0";
		else
			temp->str = str1;
	}
}

int		smallxparser(va_list args, t_type *temp, int i)
{
	temp->type = HEXA;
	if (temp->cast)
	{
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else if (temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		else if (temp->cast == Z_CAST)
			temp->hexa = va_arg(args, size_t);
		else if (temp->cast == H_CAST)
			temp->hexa = va_arg(args, unsigned int);
		else
			temp->hexa = va_arg(args, unsigned int);
		return (i);
	}
	else
		temp->hexa = va_arg(args, unsigned int);
	return (i);
}

int		parse_the_values2(va_list args, t_type *temp, char *str, int i)
{
	i = parse_the_values2_1(args, temp, str, i);
	if (str[i] == 's')
	{
		parse_the_values_forstr(args, temp);
		return (i);
	}
	if (str[i] == 'x')
		return (smallxparser(args, temp, i));
	else
		return (i);
}

void	parse_the_values4(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'p')
	{
		temp->type = POINTER_ADRESSE;
		temp->pointer = va_arg(args, unsigned long);
		return ;
	}
	if (o_parser(args, temp, str, i))
		return ;
	if (str[i] == 'O')
	{
		temp->type = OCTALM;
		if (temp->cast)
		{
			if (temp->cast == LONG_LONG || temp->cast == LONG)
				temp->octal = va_arg(args, unsigned long long);
			else if (temp->cast == J_CAST)
				temp->octal = va_arg(args, uintmax_t);
			else if (temp->cast == Z_CAST)
				temp->octal = va_arg(args, size_t);
			else
				temp->octal = va_arg(args, unsigned int);
		}
		else
			temp->octal = va_arg(args, unsigned long long);
	}
}