/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:22:32 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/07 14:57:03 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void	cero_manager(t_type *temp)
{
	if (temp->cero)
	{
		if (temp->pres_left && !temp->pres_right && temp->plus)
			temp->pres_right = temp->pres_left -1;
		else if (temp->pres_left && !temp->pres_right)
			temp->pres_right = temp->pres_left;
	}
}

int		cast_for_number(t_type *temp, int i)
{
	int t;
	int total;

	total = 0;
	t = temp->number;
	i = temp->number;
	if (temp->cast == HH_CAST)
	{
		if (t < -128)
		{
			while (t <= -128)
				t += 256;
			temp->number = t;
		}
		else if (t >= 256)
		{
			while (t > 128)
			{
				temp->number -= 256;
			}
		}
		else if (t >= 128)
		{
			//a faire une fonction que transforme le n dans une echelle de -128 a 128
			temp->number = temp->number * -1;
		}
	}
	while (i)
	{
		total++;
		i /= 10;
	}
	return total;
}
