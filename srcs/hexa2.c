/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:46:59 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 12:36:11 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	switch_hexam(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (65 + x);
	}
	return (0);
}

char		*ft_hexa_itoa_capital(unsigned long long n)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x >= 16)
	{
		x /= 16;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			str[size] = switch_hexam(x);
			n /= 16;
			size--;
		}
	}
	return (str);
}

int		ft_putx(t_type *temp, int all)
{
	if (temp->type == HEXAM)
		ft_putstr("0X");
	else
		ft_putstr("0x");
	return (all += 2);
}

int	set_presschar2(t_type *temp, int i, int total, int all)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
	if (temp->hash_tag)
	{
		if (temp->type == HEXAM)
			ft_putstr("0X");
		else
			ft_putstr("0x");
		all += 2;
	}
	if (temp->pres_right > total)
		i = temp->pres_right - total;
	all += i;
	while (i > 0)
	{
		i--;
		ft_putchar('0');
	}
	return (all);
}

int	set_presschar(t_type *temp, int total)
{
	int i;
	int all;

	all = 0;
	i = 0;
	if (temp->pres_left < total && temp->pres_right < total && 
		temp->hash_tag == 2)
		all = ft_putx(temp, all);
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->type == HEXA && temp->nopoint && temp->hash_tag && 
		temp->pres_right > total + 2 && !temp->pres_left)
			temp->pres_right -= 2;
		if (temp->pres_left > temp->pres_right)
			i = temp->pres_left - (temp->pres_right + temp->hash_tag);
		all += i;
		all = set_presschar2(temp, i, total, all);
	}
	return (all + total);
}