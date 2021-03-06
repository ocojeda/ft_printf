/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 13:26:16 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 00:53:12 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_hexa(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (97 + x);
	}
	return (0);
}

char		*ft_hexa_itoa(unsigned long long n)
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
			str[size] = switch_hexa(x);
			n /= 16;
			size--;
		}
	}
	return (str);
}

int			adresse_printer3(t_type *temp, int i, char *str, int total)
{
	temp->hash_tag = HASH_TAG;
	total = set_presschar_forp(temp, total);
	if (str[0] == '\0')
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(str);
	return (total);
}

int			adresse_printer2(t_type *temp, int i, char *str, int total)
{
	if (str[0] == '\0')
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr("0x");
	total += 2;
	ft_putstr(str);
	total = set_presschar_forprev(temp, total);
	return (total);
}

int			adresse_printer(t_type *temp)
{
	char			*str;
	int				total;

	total = 2;
	if (!temp->pointer && !temp->pres_left)
		return (cero_manager_forptr(temp, total));
	else
	{
		if ((str = ft_hexa_itoa(temp->pointer)))
		{
			total = ft_strlen(str);
			if (temp->pres_left < temp->pres_right + total)
			{
				temp->pres_left = 0;
				temp->pres_right++;
			}
			if (temp->pres_left >= total && temp->pres_right == 0
					&& temp->negative)
				total = adresse_printer2(temp, 0, str, total);
			else if (str)
				total = adresse_printer3(temp, 0, str, total);
			free(str);
		}
	}
	return (total);
}
