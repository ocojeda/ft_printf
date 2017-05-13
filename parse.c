/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/10 10:09:32 by myernaux         ###   ########.fr       */
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

int     precission_handler(char *str, int i, t_type *temp)
{
    int j;
    int e;
    char *str1;

    if ((str[i] >= '0' && str[i] <= '9') || 
            str[i] == '.')
    {
        j = i;
        e = 0;
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                i++;
                e++;
            }
            str1 = ft_strsub(str, j, e);
            temp->pres_left = ft_atoi(str1);
            free(str1);
        }
        else
            temp->pres_left = 0;
        if(str[i] == '.')
        {
            i++;
            j = i;
            e = 0;
            if(str[i] >= '0' && str[i] <= '9')
            {
                while (str[i] >= '0' && str[i] <= '9')
                {
                    i++;
                    e++;
                }
                str1 = ft_strsub(str, j, e);
                temp->pres_right = ft_atoi(str1);
                free(str1);            
            }
        }
        else
            temp->pres_right = 0;
    }
    /*
     * if(temp->pres_left > 2147483614 || 
     temp->pres_right )
     in this case we have to stop the program with no segfault
     */
    return (i);
}
int     type_handler(char *str, va_list *args, int i, t_type *temp)
{
    return i;
}
int     option_handler(char *str, int i, t_type *temp)
{
    temp->hash_tag = 0;
    temp->currency = 0;
    while(str [i] == '#' || str[i] == '$')
    {
        if(str[i] == '#')
            temp->hash_tag = HASH_TAG;
        if(str[i] == '$')
            temp->currency = CURRENCY;
        i++;
    }
    return (precission_handler(str, i, temp));
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
            if((str[i] >= '0' || str[i] <= '9' || str[i] == '.') 
                    && !temp->type) 
                i = option_handler(str, i, temp);
            if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
    {
        temp->type = INTI;
        temp->number = va_arg(args, int);
        i++;
    }
    if (str[i] == 's' && !temp->type)
    {
        temp->type = STR;
        temp->str = va_arg(args, char *);
        i++;
    }
    if (str[i] == 'x' && !temp->type)
    {
        temp->type = HEXA;
        temp->hexa = va_arg(args, unsigned int);
        i++;
    }
    if (str[i] == 'X' && !temp->type)
    {
        temp->type = HEXAM;
        temp->hexa = va_arg(args, unsigned int);
        i++;
    }
    if (str[i] == 'f' && !temp->type)
    {
        temp->type = FLOAT;
        temp->fnumber = va_arg(args, double);
        i++;
    }
    if (str[i] == 'c' && !temp->type)
    {
        temp->type = CHAR;
        temp->c = va_arg(args, int);
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
