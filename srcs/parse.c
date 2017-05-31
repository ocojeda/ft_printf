/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parse.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: myernaux <myernaux@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2017/01/07 16:25:14 by ocojeda-		  #+#	#+#			 */
/*   Updated: 2017/05/26 11:20:48 by myernaux		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_type(t_type *temp)
{
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
	ft_bzero(temp->str1, 1000);

	temp->plus = 0;
	temp->negative = 0;
	temp->hash_tag =0;
	temp->pres_left = 0;
	temp->pres_right = 0;
	temp->no_pres_left = 0;
	temp->no_pres_right = 0;
	temp->spaces = 0;
	temp->currency = 0;
	temp->nopoint = 0;
	temp->cast = 0;
	temp->cero = 0;
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
		if(temp->cast == LONG)
		{
			temp->type = WCHAR;
			temp->wc = va_arg(args, wchar_t);
		}
		else
		{
			temp->type = STR;
			char *str1 = va_arg(args, char *);
			if(str1 == NULL)
				ft_strcpy(temp->str1, "(null)");
			else
				ft_strcpy(temp->str1, str1);
		}
	}
	if (str[i] == 'S' && !temp->type)
	{
		temp->type = WSTR;
		temp->wstr = va_arg(args, wchar_t *);
		if (temp->wstr == 0 || temp->wstr == NULL)
			{
				temp->type = STR;
				ft_strcpy(temp->str1, "(null)");
			}
	}
	if (str[i] == 'x' && !temp->type)
	{
		temp->type = HEXA;
		if(temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else if(temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		else
			temp->hexa = va_arg(args, unsigned int);
	}
}
void   parse_the_values3(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'X' && !temp->type)
	{
		temp->type = HEXAM;
		if(temp->cast == LONG || temp->cast == LONG_LONG)
			temp->hexa = va_arg(args, unsigned long long);
		else
			temp->hexa = va_arg(args, unsigned int); 

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
		if(temp->cast == HH_CAST)
		{
			temp->type = INTI;
			
			temp->number = va_arg(args, long long);
			while(temp->number > 256)
				temp->number -= 256;
			temp->cast = 0;
		}
		else if(temp->cast == H_CAST)
		{
			temp->type = INTI;
			
			temp->number = va_arg(args, long long);
			while(temp->number > 65535)
				temp->number -= 65535;
			temp->cast = 0;
		} 
		else if(temp->cast == LONG_LONG || temp->cast == LONG || temp->cast == J_CAST || temp->cast == Z_CAST)
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
		temp->spaces = 0;
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
		if(temp->cast == LONG_LONG || temp->cast == LONG)
			temp->octal = va_arg(args, unsigned long long);
		else if(temp->cast == J_CAST)
			temp->octal = va_arg(args, uintmax_t);
		else
			temp->octal = va_arg(args, unsigned int);
	}
	if (str[i] == 'O' && !temp->type)
	{
		temp->type = OCTALM;
		temp->number = va_arg(args, unsigned long long);
	}
	if(!temp->type)
		{
			temp->type = CHAR;
			temp->c = str[i];
		}
	return i+1;
}
int	 parse_all(char *str, va_list args)
{
	int	 i;
	int	 e;
	int everything;
	t_type  *all;

	i = 0;
	if(!(all = (t_type *)malloc(sizeof(t_type))))
			return -1;
	everything = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = parse_the_values(args, all, str, i);
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
				all->type = STR;
				if(!(all->str = ft_strsub(str, i - e, e)))
					return -1;
				ft_strncpy(all->str1, all->str, e);
				free(all->str);
			}
		everything += printer(all);
		reset_type(all);
	}
	free(all);
	all = NULL;
	return (everything);
}
