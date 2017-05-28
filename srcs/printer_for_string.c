# include "../includes/ft_printf.h"


int	print_string(t_type *temp, int everything)
{
	int i;
	int total;
	char *str_temp;

	total = ft_strlen(temp->str1);
	i = 0;
	if(temp->pres_right && temp->pres_right < total)
	{
		str_temp = ft_strsub(temp->str1, 0, temp->pres_right);
		total = ft_strlen(str_temp);
	}
	else if(temp->pres_left && temp->no_pres_right == 2)
	{
		i = temp->pres_left;
		while(i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		return(temp->pres_left);
	}
	else
		str_temp = ft_strdup(temp->str1);
	if(temp->pres_left > total)
	{
		i = temp->pres_left - total;
		while(i > 0)
		{
			ft_putchar(' ');
			i--;
		}
		ft_putstr(str_temp);
		free(str_temp);
		return (temp->pres_left);
	}
	else if(temp->pres_right)
	{
		if(total < temp->pres_right)
			total -= temp->pres_right;
		if (total < 0)
			total = ft_strlen(str_temp);
		if(temp->pres_right > total)
			everything += total;
		else 
			everything += temp->pres_right;
		while(temp->pres_right)
		{
			ft_putchar(temp->str1[i]);
			i++;
			temp->pres_right--;
		}
		free(str_temp);
		return everything;
	}
	else
	{
		everything += ft_strlen(str_temp);
		ft_putstr(str_temp);
	}
	free(str_temp);
	return (everything);
}