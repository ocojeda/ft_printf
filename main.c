/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/10 09:43:22 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(int argc, char **argv)
{
    unsigned int x = 1200;
    char a = 'b';
    ft_printf("%%#12.8X %s\n", 26, "Timothee pauvrete");
   printf("\n%#12.8X %s\n", 26, "Timothee pauvrete"); 
    return 0;
}