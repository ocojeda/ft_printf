/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:05:50 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 21:31:26 by ocojeda-         ###   ########.fr       */
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
    //ft_putnbr(ft_printf("%s %s\n", NULL, NULL));
    //ft_putnbr(printf("%s\n", NULL));
    //ft_putnbr(ft_printf("%s\n", NULL));
   // ft_putnbr(printf("->%lD\n", 0L));
   //ft_putnbr(printf("->%i\n", 0LL));
   //total = printf("%ld%ld", 0L, 42L);
   //ft_printf("--->%d\n", total);
   total = ft_printf("%+d", -42);
   printf("--->total = %d\n", total);
   total = printf("%+d", -42);
   printf("--->total = %d\n", total);
   
   //total = ft_printf("% 3.0d", 9999);
   //printf("--->total = %d\n", total);
    //ft_putchar('\n');
    //ft_putnbr(ft_printf("->%D", 0L));
    //ft_putnbr(printf("the real %d\n", INT_MIN));
    //printf("the real %d\n", INT_MIN);
    //ft_putnbr(printf("%s %s\n", NULL, NULL));
    //printf("%o %o %o %o %o\n", 1, 100, 999, 42, 999988888);
    //ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
    //printf("% Zoooo");
    return 0;
}
