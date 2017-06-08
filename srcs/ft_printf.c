/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:38:53 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 15:34:54 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_prints(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_printf(char *format, ...)
{
	va_list	args;
	int		everything;

	everything = 0;
	va_start(args, format);
	if (check_for_prints(format))
		everything = parse_all(format, args, 0, 0);
	else
	{
		ft_putstr(format);
		everything = ft_strlen(format);
	}
	va_end(args);
	return (everything);
}
