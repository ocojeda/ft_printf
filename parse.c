/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/15 16:04:08 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type *new_type(void)
{
    t_type *temp;

    if ((temp = (t_type *)malloc(sizeof(t_type))))
        return (temp);
    else 
        return (NULL);
}
t_type *parse_all(char *str, va_list args, char *format)
{
    int     i;
    int     e;
    int     j;
    t_type  *all;
    t_type  *temp;

    i = 0;
    all = new_type();
    temp = all;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == '%')
            {
                temp->type = D_MOD;
                i++;
            }
            else
            {
                i = option_handler(str, i, temp);
                if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
                {
                    temp->type = INTI;
                    temp->number = va_arg(args, int);
                }
                if (str[i] == 's' && !temp->type)
                {
                    temp->type = STR;
                    temp->str = va_arg(args, char *);
                }
                if (str[i] == 'x' && !temp->type)
                {
                    temp->type = HEXA;
                    temp->hexa = va_arg(args, long long);
                }
                if (str[i] == 'X' && !temp->type)
                {
                    temp->type = HEXAM;
                    temp->hexa = va_arg(args, unsigned int);
                }
                if (str[i] == 'f' && !temp->type)
                {
                    temp->type = FLOAT;
                    temp->fnumber = va_arg(args, double);
                }
                if (str[i] == 'c' && !temp->type)
                {
                    temp->type = CHAR;
                    temp->c = va_arg(args, int);
                }
                if (str[i] == 'u' && !temp->type)
                {
                    temp->type = INTU;
                    temp->nbr = va_arg(args, unsigned int);
                }
                i++;
            }
            if(str[i])
            {
                temp->next = new_type();
                temp = temp->next;
            }
        }
        else if
            (str[i])
            {
                e = 0;
                while (str[i] != '%' && str[i])
                {
                    i++;
                    e++;
                }
                temp->type = STR;
                temp->str = ft_strsub(str, i - e, e);
                temp->next = new_type();
                temp = temp->next;
            }
    }
    temp->next = NULL;
    temp = all;
    return (all);
}