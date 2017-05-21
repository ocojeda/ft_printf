/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/19 14:19:41 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putwstr(wchar_t *wstr)
{
    int i;

    i = 0;
    while (*wstr)
    {
        ft_putwchar(*wstr);
        wstr++;
        i++;
    }
    return (i);
}