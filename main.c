/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:05:50 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 16:12:55 by ocojeda-         ###   ########.fr       */
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
  /*  total = ft_printf("%%");
    printf("\nour total = %d\n", total);
    total = printf("%%");
    printf("\nprintf total = %d\n", total);*/
    //printf("%o%o%o%o%o", 1, 100, 999, 42, 999988888);
    //ft_printf("%o", 1);
    printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
    //printf("%o %o %o %o %o\n", 1, 100, 999, 42, 999988888);
    ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
    //printf("% Zoooo");
    return 0;
}
