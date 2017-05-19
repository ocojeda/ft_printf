/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:05:50 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 14:25:58 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
    char a = 'b';
    long x = 0xffffffffffff;
    long y = (long)&x;
    int total;
//    printf("\n%p %s\n", y, "bye");
    total = ft_printf("%%");
    ft_printf("\nour total = %d\n", total);
    total = printf("%5%");
    printf("\nprintf total = %d\n", total);

    return 0;
}
