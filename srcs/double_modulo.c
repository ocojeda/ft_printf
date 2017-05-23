#include "ft_printf.h"

int     ft_double_modulo_handler(t_type *temp)
{
    int i = 1;
    if(temp->pres_left)
        temp->pres_left--;
    i = temp->pres_left;
    while(temp->pres_left)
        {
            ft_putchar(' ');
            temp->pres_left--;
        }
    ft_putchar('%'); 
    return i + 1;
}
