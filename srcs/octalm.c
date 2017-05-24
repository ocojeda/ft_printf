/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octalm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 09:30:09 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/24 10:33:15 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static    int    switch_octalm(int x)
{
    if (0 <= x && x <= 9)
        return (48 + x);
    return (0);
}

char        *ft_itoa_octal_capital(unsigned long long n)
{
    char                *str;
    int                    size;
    unsigned long long    x;

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
int    ft_putoctalm(t_type *temp)
{
    char            *str;
    int i;

    str = NULL;
    if (temp->type == OCTALM)
        str = ft_itoa_octal_capital(temp->number);
    i = set_presschar(temp, ft_strlen(str));
    ft_putstr(str);
    free(str);
    return (i);
}