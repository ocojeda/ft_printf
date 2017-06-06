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

void	reset_type2(t_type *temp)
{
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
	reset_type2(temp);
}

int   parse_the_values(va_list args, t_type *temp, char *str, int i)
{
	i = option_handler(str, i, temp);
	parse_the_values2(args, temp, str, i);
	parse_the_values3(args, temp, str, i);
	parse_the_values4(args, temp, str, i);
	if (!temp->type)
	{
		temp->type = CHAR;
		temp->c = str[i];
	}
	return (i + 1);
}

int	 parse_all(char *str, va_list args)
{
	int	 i;
	int	 e;
	int everything;
	t_type  *all;

	i = 0;
	if (!(all = (t_type *)malloc(sizeof(t_type))))
			return (-1);
	everything = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = parse_the_values(args, all, str, i);
		}
		else if (str[i])
		{
			e = 0;
			while (str[i] != '%' && str[i])
			{
				e++;
				i++;
			}
			all->type = STR;
			if (!(all->str = ft_strsub(str, i - e, e)))
				return (-1);
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
