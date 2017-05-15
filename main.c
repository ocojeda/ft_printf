/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/15 14:29:05 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    char a = 'b';
    unsigned int x = 0x0ff;
    void *y = &x;
    //wchar_t example[] = L"Latin text на кирилица and more latin";
   // ft_printf("\n%+5.10i %s\n",x,"not bad");
    //ft_putnbr((long)y);
    //printf("\n%+5.10i %s\n",x,"not bad"); 
    
    //printf("\n%p %s\n", y, "bye");
    //printf("\n%p %s\n", &x, "bye"); 
    ft_printf("%u", 65530);
    ft_putchar('\n');
    printf("%u", 65530);
    return 0;
}