/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:37:00 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:26:04 by ocojeda-         ###   ########.fr       */
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

int				precission_handler1(char *str, int i, t_type *temp, va_list args)
{
	int		j;
	char	*str1;
	int 	e;

	e = 0;
	j = i;
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9' && str[i])
	{
		temp->cero = 1;
		while (str[i] >= '0' && str[i] <= '9')
			increase_one(&i, &e);
		str1 = ft_strsub(str, j, e);
		temp->pres_right = ft_atoi(str1);
		free(str1);
		temp->nopoint = 1;
	}
	else if (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (str[i] == '0')
			temp->cero = 1;
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			increase_one(&i, &e);
		str1 = ft_strsub(str, j, e);
		temp->pres_left = ft_atoi(str1);
		free(str1);
		temp->nopoint = 0;
		if(str[i] == '*')
		{
			temp->pres_left = va_arg(args, int);
				if(temp->pres_left < 0)
					{
						temp->negative = NEGATIVE;
						temp->pres_left *= -1;
					}
				i++;
		}	
	}
	return (i);
}

int				precission_handler(char *str, int i, t_type *temp, va_list args)
{
	if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == '*')
	{
		if(str[i] == '*')
			{
				temp->pres_left = va_arg(args, int);
				if(temp->pres_left < 0)
					{
						temp->negative = NEGATIVE;
						temp->pres_left *= -1;
					}
				i++;
			}
		else
			i = precission_handler1(str, i, temp, args);
		if (str[i] == '.')
			{
				if(str[i + 1] == '*')
				{
					temp->pres_right = va_arg(args, int);
					if(temp->pres_right < 0)
					{
						temp->negative = NEGATIVE;
						temp->pres_right *= -1;
					}
					temp->nopoint = 0;
					temp->point = 1;
					i += 2;
				}
				else
					i = precission_handler2(str, i, temp);
			}
	}
	else
	{
		temp->no_pres_left = 1;
		temp->no_pres_right = 1;
	}
	return (cast_handler(str, i, temp));
}
