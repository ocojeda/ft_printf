/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/17 10:09:22 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    char a = 'b';
    long x = 0xffffffffffff;
    long y = (long)&x;
    //wchar_t example[] = L"Latin text на кирилица and more latin";
   // ft_printf("\n%+5.10i %s\n",x,"not bad");
    //ft_putnbr((long)y);
    //printf("\n%+5.10i %s\n",x,"not bad"); 
   ft_printf("%o\n", 989);
   printf("%o\n", 989);

   // printf("\n%p %s\n", y, "bye");
    //ft_printf("\n%p %s\n", y, "bye");
    //printf("\n%p %s\n", &x, "bye"); 
    //ft_printf("%12.8i\n", -256);
    //printf("%12.8i\n", -256);
    return 0;
}
