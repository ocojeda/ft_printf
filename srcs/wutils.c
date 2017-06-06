/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:34:38 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/31 15:37:42 by myernaux         ###   ########.fr       */
/*                                                                            */
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