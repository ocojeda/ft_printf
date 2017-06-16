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
	i = option_handler(str, i + 1, temp);
	i = parse_the_values2(args, temp, str, i);
	if (i == -1)
		return (i);
	parse_the_values3(args, temp, str, i);
	parse_the_values4(args, temp, str, i);
	if (!temp->type)
	{
		temp->type = CHAR;
		temp->c = str[i];
	}
	return (i + 1);
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
				free(all);
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

int			string_parser(t_type *all, char *str, int *i, int everything)
{
	int e;

	e = 0;
	while (str[(*i)] != '%' && str[(*i)])
		increase_one(&e, i);
	if (!(all->str = ft_strsub(str, (*i) - e, e)))
		return (-1);
	ft_putstr(all->str);
	everything += ft_strlen(all->str);
	free(all->str);
	return (everything);
}

int			parse_all(char *str, va_list args, int i, int everything)
{
	t_type	*all;

	if (!(all = (t_type *)malloc(sizeof(t_type))))
		return (-1);
	//if (parse_checker(str, args, all, 0))
	//	return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i = parse_the_values(args, all, str, i);
			if (all->type >= 1 && all->type <= 14)
				everything += printer(all);
			reset_type(all);
		}
		if (str[i])
		{
			everything = string_parser(all, str, &i, everything);
			if (everything == -1)
				return (0);
		}
		reset_type(all);
	}
	free(all);
	return (everything);
}