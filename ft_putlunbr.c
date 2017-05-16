/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:25:14 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/16 09:25:07 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putlunbr(long unsigned int lunbr)
{
    if (lunbr / 10)
        ft_putlunbr(lunbr / 10);
    ft_putchar('0' + (lunbr % 10));
}
