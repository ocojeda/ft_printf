/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/24 09:04:52 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    printer2(t_type *temp, int everything)
{
    if (temp->type == CHAR)
       {
           ft_putchar(temp->c);
           everything++;
       }
    if (temp->type == INTU)
            everything += print_unumber(temp);
    if (temp->type == INTLU)
            everything += print_lunumber(temp);
    if (temp->type == INTL)
            everything += print_lnumber(temp);
    if (temp->type == POINTER_ADRESSE)
           everything += adresse_printer(temp);
    if (temp->type == OCTAL)
        everything += ft_putoctal(temp);
    if (temp->type == OCTALM)
         everything += ft_putoctal(temp);
    if (temp->type == WCHAR)
            ft_putwchar(temp->wc);
    if (temp->type == WSTR)
            ft_putwstr(temp->wstr);
    return (everything);
}
int    printer(t_type *all)
{
    t_type *temp;
    int everything;

    everything = 0;
    temp = all;
    while(temp)
    {
        if(temp->type == -1)
            return -1;
        temp = temp->next;
    }
    temp = all;
    while (temp)
    {
        if (temp->type == STR)
            {
                ft_putstr(temp->str);
                everything += ft_strlen(temp->str);
            }
        if (temp->type == INTI)
            everything += print_number(temp);
        if (temp->type == HEXA)
            everything += ft_puthexa(temp);
        if (temp->type == HEXAM)
            everything += ft_puthexa(temp);
        if (temp->type == D_MOD)
            everything += ft_double_modulo_handler(temp);
        everything = printer2(temp, everything);
        temp = temp->next;
    }
    return everything;
}