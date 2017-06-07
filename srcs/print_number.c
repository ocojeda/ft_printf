/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:53:45 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 11:57:40 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_printf.h"

void            ft_printlongnbr(long long ll)
{
    if (ll == LONG_LONG_MIN)
    {
        ft_putstr("-9223372036854775808");
        return ;
    }
    if (ll < 0)
    {
        ft_putchar('-');
        ll = -ll;
    }
    if (ll >= 10)
    {
        ft_printlongnbr(ll / 10);
        ft_printlongnbr(ll % 10);
    }
    else
        ft_putchar(ll + '0');
}

int     set_presschar_for_int2(t_type *temp, int total, int i, int a)
{
    if (temp->plus && temp->number >= 0)
    {
        ft_putchar('+');
        a++;
        if (temp->number == 0)
            a++;
    }
    if (temp->number < 0)
    {
        ft_putchar('-');
        temp->number *= -1;
    }
    if (temp->pres_right > total - temp->negative)
        i = temp->pres_right - total + temp->negative;
    while (i > 0)
    {
        i--;
        ft_putchar('0');
        a++;
    }
    return (a);
}

int     set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int a;
    short t;

    t = temp->number;
    i = 0;
    if ((temp->pres_left < total + temp->spaces) && temp->spaces && 
    t > 0)
    {
        i = temp->spaces;
        a = temp->spaces;
        while (a)
        {
            ft_putchar(' ');
            a--;
        }
    }
    a = i;
    i = 0;
    if (temp->pres_right < total)
        temp->pres_right = total - temp->negative;
    if (temp->pres_left > temp->pres_right)
        i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
    a += i;
    while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }
    return (set_presschar_for_int2(temp, total, i , a) + total);
}

int     set_presschar_for_int_inverse(t_type *temp, int total)
{
    int i;
    int a;
    short t;

    t = temp->number;
    i = 0;
    if ((temp->pres_left < total + temp->spaces) && temp->spaces && t > 0)
    {
        i = temp->spaces;
        a = temp->spaces;
        while (a)
        {
            ft_putchar(' ');
            a--;
        }
    }
    a = i;
    i = 0;
    if (temp->pres_right < total)
        temp->pres_right = total - temp->negative;
    if (temp->pres_left > temp->pres_right)
    {
        i = temp->pres_left - temp->pres_right - temp->plus - temp->negative;
        a += i;
    }
    while (i > 0)
    {
        ft_putchar(' ');
        i--;
    }
    if (temp->pres_right > total - temp->negative)
        i = temp->pres_right - total + temp->negative;
    while (i > 0)
    {
        i--;
        ft_putchar('0');
        a++;
    }
    return (a + total);
}

int     ft_putllnbr(t_type *temp)
{
    long long t;
    int total;
    int i;

    i = 0;
    total = 0;
    t = temp->number;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    t = temp->number;
    if (temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
    {
        if (temp->spaces)
        {
            i = temp->spaces;
            total += temp->spaces;
            if (t < 0)
            {
                total--;
                i--;
            }
            while (i--)
                ft_putchar(' ');
        }
        ft_printlongnbr(t);
        if (t < 0)
            return total +1;
        else if (t == 0)
            return 1;
        else
            return (total);
    }
    if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
     && t == 0)
            return (0);
    if (temp->number < 0)
    {
        total++;
        temp->negative = NEGATIVE;
        t *= -1;
    }
    i = set_presschar_for_int(temp, total);
    ft_printlongnbr(t);
    if (t == 0 && temp->pres_right)
        i++;
    return (i);
}

int    print_number(t_type *temp)
{
    int t;
    int total;
    int i;
    int temp1;

    i = 0;
    total = 0;
    t = temp->number;
    if (temp->cast == H_CAST && temp->number > 32767)
            temp->number = temp->number * -1;
    if (temp->cast == LONG_LONG || temp->cast == LONG 
    || temp->cast == Z_CAST || temp->cast == J_CAST)
        return (ft_putllnbr(temp));
    if (temp->cast == HH_CAST)
    {
        if (t < -128)
        {
            while (t <= -128)
            t += 256;
            temp->number = t;
        }
        else if (t >= 256)
        {
            while (t > 128)
            {
                temp->number -= 256;
                t = temp->number;
            }
        }
        else if (t >= 128)
        {
            temp->number = temp->number * -1;
            t = temp->number;
        }
    }
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    t = temp->number;
    if (temp->nopoint && !temp->pres_left && temp->pres_right && temp->negative)
	{
			temp->pres_left = temp->pres_right;
			temp->pres_right = 0;
			temp->nopoint = 0;
	}
    if (temp->plus && t < 0 && temp->pres_left && !temp->pres_right && temp->cero)
    {
        temp->plus = 0;
        temp->pres_right = temp->pres_left - 1;
        temp->pres_left = 0; 
    }
    if (t < 0 && temp->plus)
        temp->plus = 0;
    if (t < 0 && temp->pres_left > temp->pres_right + total && !temp->negative)
    {
        if (temp->cero)
        {
            if (temp->pres_left && !temp->pres_right)
            {
                temp->pres_right = temp->pres_left - 1;
                temp->pres_left = 0;
            }
        }
        temp->pres_left--;
        i = set_presschar_for_int(temp, total);
        if (t < 0)
            ft_putnbr(-t);
        else 
            ft_putnbr(t);
        return (i + 1);
    }
    if (temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
     && t == 0)
        return (0);
    if (temp->nopoint && temp->pres_right && !temp->pres_left && t < 0)
        temp->pres_right--;
    if (temp->cero)
    {
        if (temp->pres_left && !temp->pres_right && temp->plus)
            temp->pres_right = temp->pres_left -1;
        else if (temp->pres_left && !temp->pres_right)
            temp->pres_right = temp->pres_left;
    }
    if (temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
    {
        if (temp->spaces)
        {
            i = temp->spaces;
            total += temp->spaces;
            if (t < 0)
            {
                total--;
                i--;
            }
            while (i--)
                ft_putchar(' ');
        }
        ft_putnbr(t);
        if (t < 0)
            return (total + 1);
        else if (t == 0)
            return (1);
        else
            return (total);
    }
    if (temp->pres_left > temp->pres_right + total && temp->negative)    
    {
        if (temp->pres_right > total)
        {
            temp1 = temp->pres_right - total;
            if (temp->number > 0 && temp->plus)
            {
                ft_putchar('+');
                total++;
                temp->plus = 0;
            }
            while (temp1--)
            {
                temp->pres_right--;
                ft_putchar('0');
                total++;
            }
        }
        ft_putnbr(t);
        if (t < 0)
        {
            temp->number *= -1;
            total++;
        }
        i = set_presschar_for_int_inverse(temp, total);
    }
    else 
    {
        t = temp->number;
        if (t < 0 && temp->cero && temp->pres_left)
            temp->pres_left--;
        if (temp->number == 0 && temp->pres_left && !temp->pres_right)
        {
            i = set_presschar_for_int(temp, total);
            return (i);
        }
        i = set_presschar_for_int(temp, total);
        if (temp->cero && temp->number == 0)
            i--;
        else
            ft_putnbr(temp->number);
        if (t < 0)
              i++;
    }
    if (t == 0 && temp->pres_right)
        i++;
    return (i);
}