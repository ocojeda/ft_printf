/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putwstr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: myernaux <myernaux@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/05/17 15:21:14 by myernaux		  #+#	#+#			 */
/*   Updated: 2017/05/24 11:59:49 by myernaux		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	 ft_wstrlen(wchar_t *s)
{
 	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
wchar_t	  *ft_wstrdup(wchar_t *s1)
{
	wchar_t	*s2;
	int		i;

	i = 0;
	s2 = (wchar_t *)malloc(sizeof(wchar_t) * (ft_wstrlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

wchar_t  *ft_wstrsub(wchar_t *s, int start, size_t len)
{
	wchar_t	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start > ft_wstrlen(s))
		return (NULL);
	i = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

int	 ft_wputstr(wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i += ft_putwchar(*str);
		str++;
	}
	return (i);
}

int	 ft_putwstr(t_type *temp, wchar_t *wstr, int everything)
{
	int i;
	int total;
	wchar_t *str_temp;


	total = ft_wstrlen(wstr);
	i = 0;
	if(temp->pres_right && temp->pres_right < total)
	{
		str_temp = ft_wstrsub(wstr, 0, temp->pres_right);
		total = ft_wstrlen(str_temp);
	}
	else if(temp->pres_left && temp->no_pres_right == 2)
	{
		i = temp->pres_left;
		while(i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		return(temp->pres_left);
	}
	else
		str_temp = ft_wstrdup(wstr);
	if(temp->pres_left > total)
	{
		i = temp->pres_left - total;
		while(i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_wputstr(str_temp);
		free(str_temp);
		return (temp->pres_left);
	}
	else if(temp->pres_right)
	{
		if(total < temp->pres_right)
			total -= temp->pres_right;
		if (total < 0)
			total = ft_wstrlen(str_temp);
		if(temp->pres_right > total)
			everything += total;
		else 
			everything += temp->pres_right;
		while(temp->pres_right)
		{
			ft_putwchar(wstr[i]);
			i++;
			temp->pres_right--;
		}
		free(str_temp);
		return everything;
	}
	else
	{
		everything += ft_wstrlen(str_temp);
		ft_wputstr(str_temp);
	}
	free(str_temp);
	return (everything);
}