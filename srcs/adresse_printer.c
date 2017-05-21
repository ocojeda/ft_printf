/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:27:11 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/21 11:35:33 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static    int    switch_hexa(int x)
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

char        *ft_hexa_itoa(unsigned long long n)
{
    char                *str;
    int                    size;
    unsigned long long    x;

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
int    adresse_printer(t_type *temp)
{
    char            *str;
    unsigned long    nb;
    int i;

    nb = temp->pointer;
    str = ft_hexa_itoa(nb);
    ft_putstr("0x");
    ft_putstr(str);
    i = ft_strlen(str);
    free(str);
    return (i + 2);
}