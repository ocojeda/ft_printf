/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:17 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/24 10:40:57 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putwchar(wchar_t wc)
{
    if (wc <= 127)
        ft_putchar(wc);
    else if (wc <= 2047)
    {
        ft_putchar((wc >> 6) + 0xC0);
        ft_putchar((wc & 0x3F) + 0x80);
    }
    else if (wc <= 65535)
    {
        ft_putchar((wc >> 12) + 0xE0);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80);
        ft_putchar((wc & 0x3F) + 0x80);
    }
    else if (wc <= 1114111)
    {
        ft_putchar((wc >> 18) + 0xF0);
        ft_putchar(((wc >> 12) & 0x3F) + 0x80);
        ft_putchar(((wc >> 6) & 0x3F) + 0x80);
        ft_putchar((wc & 0x3F) + 0x80);
    }
    return (1);
}