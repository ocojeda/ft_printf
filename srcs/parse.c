/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:25:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/05/23 17:28:50 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type *new_type(t_type *temp)
{
	if ((temp->next = (t_type *)malloc(sizeof(t_type))))
	{
		temp = temp->next;
		temp->type = 0;
		temp->octal = 0;
		temp->hash_tag =0;
		temp->plus = 0;
		temp->negative = 0;
		temp->pres_left = 0;
		temp->pres_right = 0;
		temp->hash_tag = 0;
		temp->no_pres_left = 0;
		temp->no_pres_right = 0;
		temp->cast = 0;
		temp->octal = 0;
		temp->next = NULL;
		return (temp);
	}
	else 
		return (NULL);
}
void  parse_the_values2(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == '%')
		temp->type = D_MOD;

	if ((str[i] == 'd' || str[i] == 'i') && !temp->type)
	{
		temp->type = INTI;
		temp->number = va_arg(args, long long);
	}
	if (str[i] == 'D' && !temp->type)
	{
		temp->type = INTL;
		temp->lnbr = va_arg(args, long int);
	}
	if (str[i] == 's' && !temp->type)
	{
		temp->type = STR;
		temp->str = va_arg(args, char *);
		if(temp->str == 0 || temp->str == NULL)
			temp->str = "(null)";
	}
	if (str[i] == 'S' && !temp->type)
	{
		temp->type = WSTR;
		temp->wstr = va_arg(args, wchar_t *);
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
		temp->c = va_arg(args, int);
	}
	if (str[i] == 'C' && !temp->type)
	{
		temp->type = WCHAR;
		temp->wc = va_arg(args, wchar_t);
	}
	if (str[i] == 'u' && !temp->type)
	{
		temp->type = INTU;
		temp->unbr = va_arg(args, unsigned int);
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
		temp->octal = va_arg(args, long long);
	}
	if (str[i] == 'O' && !temp->type)
	{
		temp->type = OCTALM;
		temp->octal = va_arg(args, unsigned int);
	}
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
		if (str[i] == '%')
		{
			i = parse_the_values(args, temp, str, ++i);
			if (str[i])
				temp= new_type(temp);
		}
		else if
			(str[i])
			{
				e = 0;
				while (str[i] != '%' && str[i++])
					e++;
				temp->type = STR;
				temp->str = ft_strsub(str, i - e, e);
				temp = new_type(temp);
			}
	}
	return (all);
}
