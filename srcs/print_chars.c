# include "../includes/ft_printf.h"

int	 print_chars(t_type *temp)
{
	int everything;

	everything = 0;
	if(temp->nopoint && temp->pres_right)
	{
		ft_putnbr(temp->nopoint);
		temp->pres_right--;
		while(temp->pres_right--)
		{
			ft_putchar('0');
			everything++;
		}
		ft_putchar(temp->c);
		everything++;
	}
	else if (temp->negative)
	   {
		   if(temp->c != 0)
			   ft_putchar(temp->c);
			if(temp->pres_left)
			{
				temp->pres_left--;
				while(temp->pres_left--)
					{
						everything++;
						ft_putchar(' ');
					}
			}
		   everything++;
	   }
	else if(temp->type == CHAR && temp->pres_left)
	 {
		   if(temp->pres_left)
			{
				temp->pres_left--;
				while(temp->pres_left--)
					{
						everything++;
						ft_putchar(' ');
					}
			}
		   if(temp->c != 0)
			   ft_putchar(temp->c);
		   everything++;
	   }
	   else if(temp->c == 0)
	   		return (1);
		else
		{
			ft_putchar(temp->c);
			everything = 1;
		}
	   return everything;
}