/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:33:58 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/24 10:33:59 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static    int    switch_octal(int x)
{
    if (0 <= x && x <= 9)
        return (48 + x);
    return (0);
}

char        *ft_itoa_octal(unsigned long long n)
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
            str[size] = switch_octal(x);
            n /= 8;
            size--;
        }
    }
    return (str);
}

int    ft_putoctal(t_type *temp)
{
    char            *str;
    int i;

    if (temp->type == OCTALM && temp->number == LONG_MAX)
    {
        ft_putstr("9223372036854775807");
        return (20);
    }
    str = ft_itoa_octal(temp->octal);
    i = set_presschar(temp, ft_strlen(str));
    ft_putstr(str);
    free(str);
    return (i);
}