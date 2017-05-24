/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/24 11:59:49 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putwstr(wchar_t *wstr)
{
    int i;

    i = 0;
    while (*wstr)
    {
        i += ft_putwchar(*wstr);
        wstr++;
    }
    return (i);
}