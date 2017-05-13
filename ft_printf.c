/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/10 09:54:41 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    check_for_prints(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            if (str[i + 1] != '%')
                return 1;
        i++;
    }
    return (0);    
}
int    ft_printf(char *format, ...)
{
    va_list     args;
    t_type      *all;
    t_type      *temp;
    char        *str;

    va_start(args, format);
    str = format;
    if (check_for_prints(str))
    {
        all = parse_all(str, args, format);
        temp = all;
        while (temp)
        {
            if (temp->type == STR)
                ft_putstr(temp->str);
            if (temp->type == FLOAT)
                ft_putfloat(temp);
            if (temp->type == INTI)
                ft_putnbr(temp->number);
            if (temp->type == HEXA)
                ft_puthexa(temp);
            if (temp->type == HEXAM)
                ft_puthexa(temp);
            if (temp->type == D_MOD)
                ft_putchar('%');
            if (temp->type == CHAR)
                ft_putchar(temp->c);
            temp = temp->next;
        }
    }
    else
        ft_putstr(str);
    va_end(args);
    return (1);
}