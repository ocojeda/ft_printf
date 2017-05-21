# include "../includes/ft_printf.h"

void            ft_printlongnbr(long long ll)
{
    size_t    ret;

    ret = 1;
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
int     set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int a;

    i = 0;
    
    if((temp->pres_left < total + temp->spaces) && temp->spaces && 
    temp->number > 0)
        {
            i = temp->spaces;
            a = temp->spaces;
            while(a)
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
             i = temp->pres_left - temp->pres_right 
             - temp->plus - temp->negative;
        a += i;
        while (i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if (temp->plus && temp->number >= 0 && !temp->negative)
            {
                ft_putchar('+');
                a++;
            }
        if(temp->negative)
            {
                ft_putchar('-');
                a++;
            }
        if (temp->pres_right > total - temp->negative)
                i = temp->pres_right - total + temp->negative;
        a += i - temp->negative;
        while (i > 0)
        {
           i--;
           ft_putchar('0');
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
    if(temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
        {
            if(temp->spaces)
                {
                    i = temp->spaces;
                    total += temp->spaces;
                    if(t < 0)
                        {
                            total--;
                            i--;
                        }
                    while(i--)
                        ft_putchar(' ');
                }
                    ft_printlongnbr(t);
            if(t < 0)
                    return total +1;
            else if (t == 0)
                return 1;
            else
                return (total);
        }
    if(temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
     && t == 0)
            return 0;
    if(temp->number < 0)
        {
            total++;
            temp->negative = NEGATIVE;
            t *= -1;
        }
    i = set_presschar_for_int(temp, total);
    ft_printlongnbr(t);
    if(t == 0 && temp->pres_right)
        i++;
    return (i);
}
int    print_number(t_type *temp)
{
    int t;
    int total;
    int i;

    i = 0;
    total = 0;
    if(temp->cast)
      return(ft_putllnbr(temp));
    t = temp->number;
    if(t < 0 && temp->plus)
        temp->plus = 0;
    while (t != 0)
    {
        total++;
        t /= 10;
    }
    t = temp->number;
    if(temp->no_pres_left == 2 && (temp->no_pres_right == 2 || temp->no_pres_right == 0)
     && t == 0)
            return 0;
    if(temp->no_pres_left == 1 && temp->no_pres_right == 1 && temp->plus == 0)
        {
            if(temp->spaces)
                {
                    i = temp->spaces;
                    total += temp->spaces;
                    if(t < 0)
                        {
                            total--;
                            i--;
                        }
                    while(i--)
                        ft_putchar(' ');
                }
                    ft_putnbr(t);
            if(t < 0)
                    return total +1;
            else if (t == 0)
                return 1;
            else
                return (total);
        }
    if(t < 0)
        {
            total++;
            temp->negative = NEGATIVE;
            t *= -1;
        }
    i = set_presschar_for_int(temp, total);
    ft_putnbr(t);
    if(t == 0 && temp->pres_right)
        i++;
    return (i);
}
