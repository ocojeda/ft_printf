/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:56:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/13 05:56:09 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_octal(unsigned long long n)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x >= 8)
	{
		x /= 8;
		size++;
	}
	if ((str = (char *)malloc(sizeof(str) * (size + 1))))
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			if (x <= 9)
				str[size--] = 48 + x;
			else
				str[size--] = 0;
			n /= 8;
		}
	}
	return (str);
}

int			ft_putoctal3(t_type *temp, int i, int total, char *str)
{
	if (temp->hash_tag && temp->pres_right < total)
	{
		ft_putnbr(0);
		i++;
	}
	if (temp->pres_right > total)
	{
		while (temp->pres_right > total)
		{
			temp->pres_right--;
			ft_putchar('0');
			total++;
		}
	}
	ft_putstr(str);
	i += set_presschar_octal(temp, total);
	return (i);
}

void		ft_putocal2(t_type *temp)
{
	if (temp->nopoint && !temp->pres_left &&
			temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right;
		temp->pres_right = 0;
	}
	if (temp->cast == HH_CAST)
	{
		while (temp->octal > 256)
			temp->octal -= 256;
	}
	if (temp->pres_left && !temp->pres_right && temp->cero)
	{
		temp->pres_right = temp->pres_left;
		temp->pres_left = 0;
	}
}

int			ft_putoctal4(t_type *temp, char *str, int *i, int total)
{
	if (temp->hash_tag && !temp->pres_left &&
			!temp->pres_right && !temp->octal)
		*i = ft_putchar_spe('0');
	else
	{
		if ((!temp->pres_right && !temp->octal && temp->pres_left))
		{
			free(str);
			temp->pres_left++;
			*i = set_presschar_octal(temp, total);
			return (1);
		}
		if (temp->pres_right == 0 && temp->octal == 0 && temp->pres_left)
		{
			temp->pres_left++;
			*i = (*i) - 1;
		}
		*i = (*i) + set_presschar_octal(temp, total);
		ft_putstr(str);
	}
	return (0);
}

int			ft_putoctal(t_type *temp)
{
	char	*str;
	int		i;
	int		total;

	i = 0;
	total = temp->octal;
	if (total < 0 && temp->cast == H_CAST)
		temp->octal = 65494;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
				!temp->no_pres_right) && !temp->octal &&
			!temp->pres_left && !temp->hash_tag)
		return (0);
	if (temp->no_pres_left && temp->no_pres_right && !temp->octal
			&& !temp->nopoint)
		return (ft_putchar_spe('0'));
	ft_putocal2(temp);
	str = ft_itoa_octal(temp->octal);
	total = ft_strlen(str);
	if (temp->negative == NEGATIVE && temp->pres_left > temp->pres_right)
		i = ft_putoctal3(temp, i, total, str);
	else if (ft_putoctal4(temp, str, &i, total))
		return (temp->pres_left - 1);
	free(str);
	return (i);
}
