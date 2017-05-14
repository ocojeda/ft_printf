# include "ft_printf.h"

void    set_presschar_for_int(t_type *temp, int total)
{
    int i;
    int x;
    int pos_flag;
    pos_flag = 0;

    if(temp->type == INTI && temp->number > 0 || temp->plus)
        pos_flag = 1;

    i = 0;
    if(temp->pres_left > total || temp->pres_right > total)
    {
        if(temp->pres_right < total)
            temp->pres_right = total;
        if(temp->pres_left > temp->pres_right)
             i = temp->pres_left - temp->pres_right - pos_flag;
        while(i > 0)
        {
            ft_putchar(' ');
            i--;
        }
        if(pos_flag)
            ft_putchar('+');
        if(temp->pres_right > total)
            i = temp->pres_right - total;
            while(i > 0)
            {
               i--;
               ft_putchar('0');
            }
    }
}
void    print_number(t_type *temp)
{
    long long t;
    int total;
    total = 0;

    t = temp->number;
    while(t > 1)
    {
        total++;
        t /= 10;
    }
    set_presschar_for_int(temp, total);
    ft_putnbr(temp->number);
}
void    printer(t_type *all)
{
    t_type *temp;

    temp = all;
    while (temp)
        {
            if (temp->type == STR)
                ft_putstr(temp->str);
            if (temp->type == FLOAT)
                ft_putfloat(temp);
            if (temp->type == INTI)
                print_number(temp);
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