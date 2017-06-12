/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:29:48 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/08 15:42:50 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	reset_type2(t_type *temp)
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

void	reset_type(t_type *temp)
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
	ft_bzero(temp->str1, 1000);
	reset_type2(temp);
}

int		parse_the_values(va_list args, t_type *temp, char *str, int i)
{
	i = option_handler(str, i + 1, temp);
	i = parse_the_values2(args, temp, str, i);
	if(i == -1)
		return (i);
	parse_the_values3(args, temp, str, i);
	parse_the_values4(args, temp, str, i);
	
	if (!temp->type)
	{
		temp->type = CHAR;
		temp->c = str[i];/*
		ft_putnbr(temp->pres_left);
		ft_putnbr(temp->pres_right);
		ft_putnbr(temp->cero);
		ft_putnbr(temp->type);*/
	}
	return (i + 1);
}

int		parse_all(char *str, va_list args, int i, int everything)
{
	int		e;
	t_type	*all;

	if (!(all = (t_type *)malloc(sizeof(t_type))))
		return (0);
	
	va_list	 list2;
	va_copy(list2, args);
	all->type = 0;
	while (str[i])
	{
		if (str[i] == '%')
			{
				i = parse_the_values(list2, all, str, i);
				if(i == -1)
					{
						reset_type(all);
						free(all);
						return (-1);
					}
				reset_type(all);
			}
		if(str[i])
			while (str[i] != '%' && str[i])
				i++;
		reset_type(all);
	}
	va_end(list2);
	i = 0;

	while (str[i])
	{
		if (str[i] == '%')
			{
				i = parse_the_values(args, all, str, i);
				if(i == -1)
					{
						reset_type(all);
						free(all);
						return (-1);
					}
				if(all->type >= 1 && all->type <= 14)
				{
					e = printer(all);
					everything += e;
					if (e < 0)
						return (0);
				}
				reset_type(all);
			}
		if(str[i])
		{
			e = 0;
			while (str[i] != '%' && str[i])
				increase_one(&e, &i);
			all->type = STR;
			if (!(all->str = ft_strsub(str, i - e, e)))
				return(0);
			if(ft_strncpy(all->str1, all->str, e))
				{
					if(all->str)
					{
						free(all->str);
						all->str1[e] = '\0';
						e = printer(all);
						everything += e;
					}
				}
		}
		reset_type(all);
	}
	free(all);
	return (everything);
}
