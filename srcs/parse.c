/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/24 11:04:38 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type *new_type(t_type *temp)
{
    if ((temp->next = (t_type *)malloc(sizeof(t_type))))
    {
        temp = temp->next;
        temp->type = 0;
        temp->unbr = 0;
        temp->lunbr = 0;
        temp->lnbr = 0;
        temp->pointer = 0;
        temp->fnumber = 0;
        temp->str = NULL;
        temp->c = 0;
        temp->wstr = NULL;
        temp->wc = 0;
        temp->hexa = 0;

        temp->plus = 0;
        temp->negative = 0;
        temp->hash_tag =0;
        temp->pres_left = 0;
        temp->pres_right = 0;
        temp->no_pres_left = 0;
        temp->no_pres_right = 0;
        temp->spaces = 0;
        temp->currency = 0;
        temp->cast = 0;
        temp->next = NULL;
        return (temp);
    }
    else 
        return (NULL);
}
void  parse_the_values2(va_list args, t_type *temp, char *str, int i)
{
    if (str[i] == '%' && !temp->type)
        temp->type = D_MOD;
    if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
    {
        temp->type = INTI;
        temp->number = va_arg(args, long long);
    }
    if (str[i] == 'D' && !temp->type)
    {
        temp->type = INTI;
        temp->cast = LONG_LONG;
        temp->number = va_arg(args, long long);
    }
    if (str[i] == 's' && !temp->type)
    {
        temp->type = STR;
        char *str1 = va_arg(args, char *); 
        if(str1)
            temp->str = ft_strdup(str1);
        else
            temp->str = ft_strdup("(null)");
    }
    if (str[i] == 'S' && !temp->type)
    {
        temp->type = WSTR;
        temp->wstr = va_arg(args, wchar_t *);
        if (temp->wstr == 0 || temp->wstr == NULL)
            {
                temp->type = STR;
                temp->str = ft_strdup("(null)");
            }
    }
    if (str[i] == 'x' && !temp->type)
    {
        temp->type = HEXA;
        temp->hexa = va_arg(args, unsigned long long);
    }
}
void   parse_the_values3(va_list args, t_type *temp, char *str, int i)
{
    if (str[i] == 'X' && !temp->type)
    {
        temp->type = HEXAM;
        temp->hexa = va_arg(args, unsigned long long);
    }
    if (str[i] == 'c' && !temp->type)
    {
        temp->type = CHAR;
        if(temp->cast == LONG_LONG || temp->cast == LONG)
        {
             temp->type = WCHAR;
             temp->wc = va_arg(args, wchar_t);
        }
        else
            temp->c = va_arg(args, int);
    }
    if (str[i] == 'C' && !temp->type)
    {
        temp->type = WCHAR;
        temp->wc = va_arg(args, wchar_t);
    }
    if (str[i] == 'u' && !temp->type)
    {
        if(temp->cast == HH_CAST || temp->cast == H_CAST)
        {
            temp->type = INTI;
            
            temp->number = va_arg(args, long long);
            while(temp->number > 256)
                temp->number -= 256;
            temp->cast = 0;
        }
		else if(temp->cast == LONG_LONG || temp->cast == LONG || temp->cast == J_CAST)
		{
			temp->type = INTLU;
        	temp->lunbr = va_arg(args, long unsigned int);		
		}
		else
		{
        temp->type = INTI;
        temp->number = va_arg(args, long long);
        temp->cast = LONG_LONG;
        if(temp->number < 0)
            temp->number *= -1;
		}
    }
    if (str[i] == 'U' && !temp->type)
    {
        temp->type = INTLU;
        temp->lunbr = va_arg(args, long unsigned int);
    }
}
int   parse_the_values(va_list args, t_type *temp, char *str, int i)
{
    i = option_handler(str, i, temp);
    parse_the_values2(args, temp, str, i);
    parse_the_values3(args, temp, str, i);
    if (str[i] == 'p' && !temp->type)
    {
        temp->type = POINTER_ADRESSE;
        temp->pointer = va_arg(args, unsigned long);
    }
    if (str[i] == 'o' && !temp->type)
    {
        temp->type = OCTAL;
        //if(temp->cast == HH_CAST)
        //    temp->number = va_arg(args, int);
        //else 
            temp->octal = va_arg(args, long long);
    }
    if (str[i] == 'O' && !temp->type)
    {
        temp->type = OCTALM;
        temp->number = va_arg(args, unsigned long long);
    }
    if(!temp->type)
        temp->type = -1;
    return i+1;
}
t_type  *make_new_string(char *str, int i, t_type *temp)
{
    int e = 0;
    while (str[i] != '%' && str[i])
    {
        i++;
        e++;
    }
    temp->type = STR;
    temp->str = ft_strsub(str, i - e, e);
    temp = new_type(temp);
    return temp;
}
t_type *parse_all(char *str, va_list args)
{
    int     i;
    int     e;
    t_type  *all;
    t_type  *temp;

    i = 0;
    all = (t_type *)malloc(sizeof(t_type));
    temp = all;
    while (str[i])
    {
        /*ft_putnbr(i);
        ft_putchar('\n');*/
        if (str[i] == '%')
        {
            i++;
            i = parse_the_values(args, temp, str, i);
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
                temp->type = STR;
                temp->str = ft_strsub(str, i - e, e);
            }
        if (str[i])
        {
                temp= new_type(temp);
            //ft_putnbr(i);
              //  ft_putchar('\n');
        }
        else
        {
            //temp->next = NULL;
            return all;
        }
    }
    return (all);
}
