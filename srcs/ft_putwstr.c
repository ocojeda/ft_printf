/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:21:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/24 10:44:05 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_putwstr(wchar_t *wstr)
{
    int i;
    int j;

    j = -1;
    i = 0;
    while (wstr[++j])
    {
        ft_putwchar(wstr[j]);
        wstr++;
        i++;
    }
    return (i);
}