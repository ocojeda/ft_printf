/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:37:00 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/08 15:28:46 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			increase_one(int *a, int *b)
{
	*a = (*a) + 1;
	*b = (*b) + 1;
}

int				precission_handler2(char *str, int i, t_type *temp)
{
	int		e;
	int		j;
	char	*str1;

	if (str[i] == '.')
	{
		temp->nopoint = 0;
		temp->point = 1;
		if (ft_isdigit(str[i - 1]) == 0)
			temp->no_pres_left = 2;
		j = ++i;
		e = 0;
		if (ft_isdigit(str[i]) == 0 || !str[i])
			temp->no_pres_right = 2;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				increase_one(&i, &e);
			str1 = ft_strsub(str, j, e);
			temp->pres_right = ft_atoi(str1);
			free(str1);
		}
	}
	return (i);
}

int				precission_handler1(char *str, int i, t_type *temp, int e)
{
	int		j;
	char	*str1;

	j = i;
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9' && str[i])
	{
		//if(str[i] == '0')
		//	temp->cero = 1;
		temp->pres_left = 0;
		while (str[i] >= '0' && str[i] <= '9')
			increase_one(&i, &e);
		str1 = ft_strsub(str, j, e);
		temp->pres_right = ft_atoi(str1);
		free(str1);
		temp->nopoint = 1;
	}
	else if (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		//if(str[i] == '0')
		//	temp->cero = 1;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			increase_one(&i, &e);
		str1 = ft_strsub(str, j, e);
		temp->pres_left = ft_atoi(str1);
		free(str1);
		temp->nopoint = 0;
	}
	return (i);
}

int				precission_handler(char *str, int i, t_type *temp)
{
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		//ft_putchar(str[i]);
		i = precission_handler1(str, i, temp, 0);
		
		if (str[i] == '.')
			i = precission_handler2(str, i, temp);
		//ft_putnbr(temp->point);
		//else if (!temp->pres_right)
		//	temp->pres_right = 0;
	}
	else
	{
		temp->no_pres_left = 1;
		temp->no_pres_right = 1;
	}
	return (cast_handler(str, i, temp));
}