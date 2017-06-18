/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:29:48 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 05:46:48 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			parse_the_values(va_list args, t_type *temp, char *str, int i)
{
	i++;
	i = option_handler(str, i, temp);
	i = parse_the_values2(args, temp, str, i);
	if (i == -1)
		return (i);
	parse_the_values3(args, temp, str, i);
	parse_the_values4(args, temp, str, i);
	if (!temp->type && str[i])
	{
		temp->type = CHAR;
		temp->c = str[i];
	}
	if(str[i])
		i++;
	return (i);
}

int			parse_checker(char *str, va_list args, t_type *all, int i)
{
	va_list		list2;

	va_copy(list2, args);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = parse_the_values(list2, all, str, i);
			if (i == -1)
			{
				reset_type(all);
				return (1);
			}
			reset_type(all);
		}
		if (str[i])
			while (str[i] != '%' && str[i])
				i++;
		reset_type(all);
	}
	va_end(list2);
	return (0);
}

int			string_parser(char *str, int *i, int everything)
{
	while (str[(*i)] != '%' && str[(*i)])
		{
			everything += ft_putchar_spe(str[*i]);
			*i = (*i) + 1;
		}
	return (everything);
}

int			parse_all(char *str, va_list args, int i, int everything)
{
	t_type	all;
	int		temp;

	if (parse_checker(str, args, &all, 0))
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = parse_the_values(args, &all, str, i);
			//if (i == -1)
			//	return (0);
			//ft_putnbr(all.type);
			if (all.type >= 1 && all.type <= 14)
				temp = printer(&all);
			if (temp == -1)
				return (0);
			everything += temp;
			reset_type(&all);
		}
		if (str[i])
		{
			everything = string_parser(str, &i, everything);
			//if (everything == -1)
			//	return (0);
		}
		reset_type(&all);
	}
	return (everything);
}