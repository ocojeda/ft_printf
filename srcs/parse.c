/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/26 11:20:48 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      sux_cases(t_type *temp, char *str, int i, va_list args)
{
    if (str[i] == 's' && !temp->type)
    {
        if(temp->cast == LONG)
        {
            temp->type = WCHAR;
            temp->wc = va_arg(args, wchar_t);
        }
        else
        {
            temp->type = STR;
            char *str1 = va_arg(args, char *);
            if(str1 == NULL)
                ft_strcpy(temp->str1, "(null)");
            else
                ft_strcpy(temp->str1, str1);
        }
    }
    if (str[i] == 'u' && !temp->type)
        u_option_parser(temp, args);
    if (str[i] == 'x' && !temp->type)
    {
        temp->type = HEXA;
        if(temp->cast == LONG_LONG || temp->cast == LONG)
            temp->hexa = va_arg(args, unsigned long long);
        else if(temp->cast == J_CAST)
            temp->hexa = va_arg(args, uintmax_t);
        else
            temp->hexa = va_arg(args, unsigned int);
    }
    return (i+1);
}
static int      capital_cdo_cases(t_type *temp, char *str, int i, va_list args)
{
    if (str[i] == 'C')
    {
        temp->type = WCHAR;
        temp->wc = va_arg(args, wchar_t);
    }
    if (str[i] == 'D' && !temp->type)
    {
        temp->type = INTI;
        temp->cast = LONG_LONG;
        temp->number = va_arg(args, long long);
    }
    if (str[i] == 'O' && !temp->type)
    {
        temp->type = OCTALM;
        temp->number = va_arg(args, unsigned long long);
    }
    return (i + 1);
}
static int      capital_sux_mod(t_type *temp, char *str, int i, va_list args)
{
    if (str[i] == 'X' && !temp->type)
    {
        temp->type = HEXAM;
        if(temp->cast == LONG || temp->cast == LONG_LONG)
            temp->hexa = va_arg(args, unsigned long long);
        else
            temp->hexa = va_arg(args, unsigned int);
    }
    if (str[i] == 'U' && !temp->type)
    {
        temp->type = INTLU;
        temp->lunbr = va_arg(args, long unsigned int);
    }
    if (str[i] == 'S' && !temp->type)
    {
        temp->type = WSTR;
        temp->wstr = va_arg(args, wchar_t *);
        if (temp->wstr == 0 || temp->wstr == NULL)
        {
            temp->type = STR;
            ft_strcpy(temp->str1, "(null)");
        }
    }
    if (str[i] == '%' && !temp->type)
        temp->type = D_MOD;
    return (i +1);
}
int   parse_the_values(va_list args, t_type *temp, char *str, int i)
{
    i = option_handler(str, i, temp);
    if(str[i] == 'd' || str[i] == 'i' || str[i] == 'c'
    || str[i] == 'p' || str[i] == 'o')
        return cdiop_cases(temp, str, i, args);
    if(str[i] == 's' || str[i] == 'u' || str[i] == 'x')
        return sux_cases(temp, str, i, args);
    if(str[i] == 'C' || str[i] == 'D' || str[i] == 'O' ||
        str[i] == 'S')
        return capital_cdo_cases(temp, str, i, args);
    if(str[i] == 'X' || str[i] == 'U' || str[i] == '%')
        return capital_sux_mod(temp, str, i, args);
    temp->type = CHAR;
    temp->c = str[i];
    return i+1;
}
int     parse_all(char *str, va_list args)
{
    int     i;
    int     e;
    int everything;
    t_type  *all;

    i = 0;
    if(!(all = (t_type *)malloc(sizeof(t_type))))
            return -1;
    everything = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            i = parse_the_values(args, all, str, i);
        }
        else if
            (str[i])
            {
                e = 0;
                while (str[i] != '%' && str[i])
                {
                    e++;
                    i++;
                }
                all->type = STR;
                if(!(all->str = ft_strsub(str, i - e, e)))
                    return -1;
                ft_strncpy(all->str1, all->str, e);
                free(all->str);
            }
        everything += printer(all);
        reset_type(all);
    }
    free(all);
    all = NULL;
    return (everything);
}