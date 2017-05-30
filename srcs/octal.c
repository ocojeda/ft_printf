/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   octal.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ocojeda- <ocojeda-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/05/24 10:33:58 by ocojeda-		  #+#	#+#			 */
/*   Updated: 2017/05/24 10:33:59 by ocojeda-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	set_presschar_octal(t_type *temp, int total)
{
	int i;
	int all;

	all = 0;
	i = 0;
	 if (temp->pres_left < total && temp->pres_right < total && 
			temp->hash_tag == 2)
	{
		ft_putstr("0");
		all ++;
	}
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->pres_left > temp->pres_right)
			{
				i = temp->pres_left - (temp->pres_right);
				if(temp->hash_tag)
					i--;
			}
		all += i;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		if (temp->hash_tag && !temp->negative)
		{
			ft_putstr("0");
			total++;
		}
		if (temp->pres_right > total)
			i = temp->pres_right - total;
		all += i;
		while (i > 0)
		{
			i--;
			ft_putchar('0');
		}
	}
	return (all + total);
}

static	int	switch_octal(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	return (0);
}

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
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			str[size] = switch_octal(x);
			n /= 8;
			size--;
		}
	}
	return (str);
}
static int special_cast_handler(t_type *temp)
{
	if(temp->nopoint && temp->pres_left == 0 && temp->pres_right && temp->negative)
	{
		temp->pres_left = temp->pres_right;
		temp->pres_right = 0;
	}
	if(temp->cast == HH_CAST)
	{
		while(temp->octal > 256)
			temp->octal -= 256;
	}
	if (temp->type == OCTALM && temp->number == LONG_MAX)
	{
		ft_putstr("9223372036854775807");
		return (20);
	}
	return(0);
}
static int standar_case_handler(t_type *temp, char *str, int i, int total)
{
	if(temp->hash_tag && !temp->pres_left && !temp->pres_right && temp->octal == 0)
	{
		ft_putchar('0');
		i = 1;
	}
	else
	{
		if((temp->pres_right == 0 && temp->octal == 0 && temp->pres_left))
		{
			free(str);
			temp->pres_left++;
			i = set_presschar_octal(temp, total);
			return temp->pres_left-1;
		}
		if(temp->pres_right == 0 && temp->octal == 0 && temp->pres_left)
	 	{
			 temp->pres_left++;
			 i--;
		 }
		i += set_presschar_octal(temp, total);
		ft_putstr(str);
	}
	free(str);
	return (i);
}
int	ft_putoctal(t_type *temp)
{
	char			*str;
	int i;
	int total;

	i = 0;
	   if(temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
	 && temp->octal == 0 && temp->pres_left == 0 && !temp->hash_tag)
			return 0;
		if(temp->no_pres_left&& temp->no_pres_right && temp->octal == 0 && temp->nopoint == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if(special_cast_handler(temp))
		return (20);
	i = 0;
	str = ft_itoa_octal(temp->octal);
	total = ft_strlen(str);
	if(temp->negative == NEGATIVE && temp->pres_left > temp->pres_right)
	{
		if(temp->hash_tag && temp->pres_right < total)
			{
				ft_putnbr(0);
				i++;
			}
		if(temp->pres_right > total)
		{
			while(temp->pres_right > total)
			{
				temp->pres_right--;
				ft_putchar('0');
				total++;
			}
		}
		ft_putstr(str);
		i += set_presschar_octal(temp, total);
	}
	else
		return(standar_case_handler(temp, str, i, total));
	free(str);
	return (i);
}