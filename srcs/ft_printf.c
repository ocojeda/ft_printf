/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/24 09:19:58 by ocojeda-         ###   ########.fr       */
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
                return 1;
        i++;
    }
    return (0);    
}

int    ft_printf(char *format, ...)
{
    va_list     args;
    t_type      *all = NULL;
    char        *str;
    int   everything;
    
    all = NULL;
    everything = 0;
    va_start(args, format);
    str = ft_strdup(format);
    if (check_for_prints(str))
    {
        all = parse_all(str, args);
        everything = printer(all);
    }
    else
    {
        ft_putstr(str);
        everything = ft_strlen(str);
    }
    free(str);
    va_end(args);
    return (everything);
}