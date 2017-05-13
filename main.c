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

int main(void)
{
    char a = 'b';
    unsigned short x = 0x0ff;
    void *y = &x;
    //wchar_t example[] = L"Latin text на кирилица and more latin";
    ft_printf("\n%#5.1X %s\n", 0xfff, "not bad");
    printf("\n%#5.1X %s\n", 0xfff, "not bad"); 
    printf("\n%p %s\n", &x, "bye"); 
    return 0;
}