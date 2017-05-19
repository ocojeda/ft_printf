/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/19 14:20:52 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int     cast_handler(char *str, int i, t_type *temp)
{
    while (str[i] == 'h' || str[i] == 'l' || 
    str[i] == 'j' || str[i] == 'z')
    {
        if (str[i] == 'l')
        {
            if (str[i + 1] == 'l')
            {
                temp->cast = LONG_LONG;
                i++;
            }
            else
                temp->cast = LONG;
        }
        if (str[i] == 'h')
        {
            if (str[i + 1] == 'h')
            {
                temp->cast = UNSIGNED_CHAR;
                i++;
            }
            else
                temp->cast = UNSIGNED_SHORT_INT;
        }
        i++;    
    }
    return (i);
}

int     precission_handler(char *str, int i, t_type *temp)
{
    int     j;
    int     e;
    char    *str1;

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
        if (str[i] == '.')
        {
            i++;
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
    return (cast_handler(str, i, temp));
}

int     option_handler(char *str, int i, t_type *temp)
{
    temp->hash_tag = 0;
    temp->currency = 0;
    temp->plus = 0;
    temp->negative = 0;
    while (str [i] == '#' || str[i] == '$' || str[i] == '+' 
    || str[i] == '-' || str[i] == ' ')
    {
        if (str[i] == '#')
           temp->hash_tag = HASH_TAG;
        if (str[i] == '$')
            temp->currency = CURRENCY;
        if (str[i] == '+')
            temp->plus = POSITIVE;
        if (str[i] == '-')
            temp->negative = NEGATIVE;
        i++;
    }
    return (precission_handler(str, i, temp));
}