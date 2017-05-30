#include "ft_printf.h"
int	 negative_case(t_type *temp, int i)
{
	ft_putchar('%');	
	if(temp->pres_left)
	    temp->pres_left--;
	i = temp->pres_left;
	while(temp->pres_left)
	{
	    ft_putchar(' ');
		temp->pres_left--;
	}
    return (i);
}
int	 ft_double_modulo_handler(t_type *temp)
{
	int i = 1;
	if(temp->negative)
        i = negative_case(temp, i);
	else
	{
	if(temp->pres_left)
		temp->pres_left--;
	i = temp->pres_left;
	while(temp->pres_left)
		{
			ft_putchar(' ');
			temp->pres_left--;
		}
	ft_putchar('%'); 
	}
	return (i + 1);
}
