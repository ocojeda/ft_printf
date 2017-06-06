/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:37:00 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/06 09:33:50 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	 precission_handler2(char *str, int i, t_type *temp)
{
	int e;
	int j;
	char *str1;
	
	if (str[i] == '.')
	{
		temp->nopoint = 0;  //iciiiiiiiiiiiii
		if (ft_isdigit(str[i - 1]) == 0)
			temp->no_pres_left = 2;
		i++;
		j = i;
		e = 0;
		if (ft_isdigit(str[i]) == 0 || !str[i])
				temp->no_pres_right = 2;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
				e++;
			}
			str1 = ft_strsub(str, j, e);
			temp->pres_right = ft_atoi(str1);
			free(str1);			
		}
	}
	return (i);
}

int	 precission_handler1(char *str, int i, t_type *temp)
{
	int e;
	int j;
	char *str1;

	j = i;
	e = 0;
	if (str[i] == '0' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		temp->pres_left = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			e++;	
		}
		str1 = ft_strsub(str, j, e);
		temp->pres_right = ft_atoi(str1);
		free(str1);
		temp->nopoint = 1;
	}
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			e++;
		}
		str1 = ft_strsub(str, j, e);
		temp->pres_left = ft_atoi(str1);
		free(str1);
		temp->nopoint = 0;
	}
	return (i);
}

int	 precission_handler(char *str, int i, t_type *temp)
{
	if ((str[i] >= '0' && str[i] <= '9') || 
			str[i] == '.')
	{
		i = precission_handler1(str, i ,temp);
		if (str[i] == '.')
			i = precission_handler2(str, i, temp);
		else if (!temp->pres_right)
			temp->pres_right = 0;
	}
	else
	{
		temp->no_pres_left = 1;
		temp->no_pres_right = 1;
	}
	return (cast_handler(str, i, temp));
}