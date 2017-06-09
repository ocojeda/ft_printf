/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octalm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:30:09 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 14:29:29 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_octalm(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	return (0);
}

char		*ft_itoa_octal_capital(unsigned long long n)
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
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			str[size] = switch_octalm(x);
			n /= 8;
			size--;
		}
	}
	return (str);
}

int			ft_putoctalm(t_type *temp)
{
	char	*str;
	int		i;
	int 	total;

	i = 0;
	if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 ||
				!temp->no_pres_right) && !temp->octal &&
			!temp->pres_left && !temp->hash_tag)
		return (0);
	if (temp->no_pres_left && temp->no_pres_right && !temp->octal
			&& !temp->nopoint)
		return (ft_putchar_spe('0'));
	if (temp->nopoint && !temp->pres_left &&
			temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right;
		temp->pres_right = 0;
	}
	str = ft_itoa_octal_capital(temp->octal);
	total = ft_strlen(str);
	if (temp->negative == NEGATIVE && temp->pres_left > temp->pres_right)
		i = ft_putoctal3(temp, i, total, str);
	else if (ft_putoctal4(temp, str, &i, total))
		return (temp->pres_left - 1);
	free(str);
	return (i);
}
