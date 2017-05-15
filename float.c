/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/15 10:08:38 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putfloat(t_type *temp)
{
    double i;
    
    i = temp->fnumber;
    if (i < 0)
    {
        ft_putchar('-');
        i = i * -1;
    }
    while (i > 1)
    {

    }
    //to do a fonction that prints a float
    // with precission 
}