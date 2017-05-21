/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:17 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/19 14:18:36 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MASK1 "0xxxxxxx"
#define MASK2 "110xxxxx 10xxxxxx"
#define MASK3 "1110xxxx 10xxxxxx 10xxxxxx"
#define MASK4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

char    **putmask(char *bin, char *mask)
{
    int     len_b;
    int     len_m;
    char    *m;
    size_t  i;

    m = ft_strdup(mask);
    len_b = ft_strlen(bin) - 1;
    len_m = ft_strlen(m) - 1;
    while (len_m >= 0 && len_b >= 0)
    {
        if (m[len_m] == 'x')
        {
            m[len_m] = bin[len_b];
            len_b--;
        }
        len_m--;
    }
    i = -1;
    while (++i < ft_strlen(m))
    {
        if (m[i] == 'x')
            m[i] = '0';
    }
    return (ft_strsplit(m, ' '));
}

int     ft_putwchar(wchar_t wc)
{
    char    *bin;
    char    **mask;
    int     w;
    int     c;
    int     i;

    c = (int)wc;
    bin = ft_itoa_base(c, 2);
    if (ft_strlen(bin) <= 7)
        mask = putmask(bin, MASK1);
    else if (ft_strlen(bin) <= 11)
        mask = putmask(bin, MASK2);
    else if (ft_strlen(bin) <= 16)
        mask = putmask(bin, MASK3);
    else
        mask = putmask(bin, MASK4);
    ft_memdel((void **)&bin);
    i = -1;
    while (++mask[i])
    {
        w = ft_atoi_base(mask[i], 2);
        write(1, &w, 1);
    }
    ft_memdel((void **)mask);
    return (1);
}