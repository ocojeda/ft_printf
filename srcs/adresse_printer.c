/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   adresse_printer.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ocojeda- <ocojeda-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/05/17 15:27:11 by myernaux		  #+#	#+#			 */
/*   Updated: 2017/05/21 11:35:33 by ocojeda-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

# include "ft_printf.h"
int	set_presschar_forprev(t_type *temp, int total)
{
	int i;
	int all;

	all = 0;
	i = 0;
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->pres_left > temp->pres_right)
			i = temp->pres_left - (temp->pres_right + temp->hash_tag);
		all += i;
		while (i > 0)
		{
			ft_putchar(' ');
			i--;
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
int	set_presschar_forp(t_type *temp, int total)
{
	int i;
	int all;

	all = 0;
	i = 0;
	if (temp->pres_left < total && temp->pres_right < total && 
			temp->hash_tag == 2)
	{
		ft_putstr("0x");
		all += 2;
	}
	if (temp->pres_left > total || temp->pres_right > total)
	{
		if (temp->pres_right < total)
			temp->pres_right = total;
		if (temp->pres_left > temp->pres_right)
			i = temp->pres_left - (temp->pres_right + temp->hash_tag);
		all += i;
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
	}
	return (all + total);
}
static	int	switch_hexa(int x)
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
int	adresse_printer(t_type *temp)
{
	char			*str;
	unsigned long	nb;
	int i;
	int total;

	i = 0;
    total = 2;
	nb = temp->pointer;
	if(nb == 0 && temp->nopoint && temp->pres_right == 0)
		{
			ft_putstr("0x");
			return 2;
		}
	if((str = ft_hexa_itoa(nb)))
	{
		total = ft_strlen(str);
		if(temp->pres_left > total && temp->pres_right == 0 && temp->negative)
		{
			if(str[0] == '\0')
			{
				ft_putchar('0');
				i++;
			}
			ft_putstr("0x");
            total += 2;
			ft_putstr(str);
			total = set_presschar_forprev(temp, total);
		}
		else if (str)
		{
			temp->hash_tag =  HASH_TAG;
			total = set_presschar_forp(temp, total);
            if(str[0] == '\0')
			{
				ft_putchar('0');
				i++;
			}
            ft_putstr(str);
        }
	}
	free(str);
	return (total);
}