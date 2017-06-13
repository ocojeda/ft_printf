/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 08:30:48 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 04:16:47 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
int		smalldparser(va_list args, t_type *temp, int i)
{
	temp->type = INTI;
	if(temp->cast)
	{
		if(temp->cast == HH_CAST || temp->cast == H_CAST )
			temp->number = va_arg(args, int);
		else 
		{
			temp->type = INTL;
			if(temp->cast == J_CAST)
				temp->lnbr = va_arg(args, intmax_t);
			else if(temp->cast == Z_CAST)
				temp->lnbr = va_arg(args, size_t);
			else if(temp->cast == LONG)
				temp->lnbr = va_arg(args, long long );
			else (temp->cast == LONG_LONG)
				temp->lnbr = va_arg(args, long long );
			return (i);
		}
	}
	else 
		temp->number = va_arg(args, int);
	return (i);
}
int		parse_the_values2_1(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == '%' && !temp->type)
	{
		temp->type = D_MOD;
		return (i);
	}
	if ((str[i] == 'd' || str[i] == 'i'))
		return(smalldparser(args, temp, i));
	if (str[i] == 'D' && !temp->type)
	{
		temp->type = INTL;
		if(temp->cast)
		{
			if(temp->cast == HH_CAST || temp->cast == H_CAST )
				temp->lnbr = va_arg(args, long long);	
			if(temp->cast == J_CAST)
				temp->lnbr = va_arg(args, intmax_t);
			if(temp->cast == Z_CAST)
				temp->lnbr = va_arg(args, size_t);
			if(temp->cast == LONG)
				temp->lnbr = va_arg(args, long long );
				
			if(temp->cast == LONG_LONG)
				temp->lnbr = va_arg(args, long long );
				
		}
		else 
			temp->lnbr = va_arg(args, long long);
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
		else if(temp->negative)
		//	{
				//ft_putnbr(temp->pres_right);
				//temp->wstr = va_arg(args, wchar_t *);
				//int e = ft_wstrlen(temp->wstr);
				//ft_putnbr(e);
				//if(e != 46)
					return (-1);
				//else return i;
		//	}
		//if(temp->point && temp->pres_left == 0 && temp->pres_right == 0)
		//	temp->type = SKIPIT;
		//ft_putnbr(temp->nopoint);
		//ft_putnbr(temp->cero);
	}
	return (i);
}

void	parse_the_values2_2(va_list args, t_type *temp, char *str, int i)
{
	char *str1;

	if (str[i] == 's' && !temp->type)
	{
		if (temp->cast == LONG)
		{
			temp->type = WSTR;
			temp->wstr = va_arg(args, wchar_t *);
			if (temp->wstr == 0 || temp->wstr == NULL)
			{
				temp->type = STR;
				ft_strcpy(temp->str1, "(null)");
			}
		}
		else
		{
			temp->type = STR;
			str1 = va_arg(args, char *);
			if (str1 == NULL)
				ft_strcpy(temp->str1, "(null)");
			else if(str1[0] == 0)
				{
					ft_bzero(temp->str1, 1000);
					//temp->type = INTI;
					//temp->number = 0;
				}
			else
				ft_strcpy(temp->str1, str1);
		}
	}
}

int		parse_the_values2(va_list args, t_type *temp, char *str, int i)
{
	i = parse_the_values2_1(args, temp, str, i);
	parse_the_values2_2(args, temp, str, i);
	if (str[i] == 'x' && !temp->type)
	{
		temp->type = HEXA;
		if(temp->cast)
		{
		if (temp->cast == LONG_LONG || temp->cast == LONG)
			temp->hexa = va_arg(args, unsigned long long);
		if (temp->cast == J_CAST)
			temp->hexa = va_arg(args, uintmax_t);
		if (temp->cast == Z_CAST)
			temp->hexa = va_arg(args, size_t);
		if (temp->cast == H_CAST)
			temp->hexa = va_arg(args, unsigned int);
		if (temp->cast == HH_CAST)
			temp->hexa = va_arg(args, unsigned int);
		}
		else
			temp->hexa = va_arg(args, unsigned int);
	}
	return (i);
}

void	parse_the_values4(va_list args, t_type *temp, char *str, int i)
{
	if (str[i] == 'p' && !temp->type)
	{
		temp->type = POINTER_ADRESSE;
		temp->pointer = va_arg(args, unsigned long);
	}
	if (str[i] == 'o' && !temp->type)
	{
		temp->type = OCTAL;
		if(temp->cast)
		{
			if (temp->cast == LONG_LONG || temp->cast == LONG)
				{
					temp->type = OCTALM;
					temp->octal = va_arg(args, unsigned long long);
				}
			if (temp->cast == J_CAST)
				temp->octal = va_arg(args, uintmax_t);
			if (temp->cast == Z_CAST)
				temp->octal = va_arg(args, size_t);
			if (temp->cast == H_CAST || temp->cast == HH_CAST)
				temp->octal = va_arg(args, unsigned int);
		}
		else
			temp->octal = va_arg(args, unsigned int);
	}
	if (str[i] == 'O' && !temp->type)
	{
		temp->type = OCTALM;
		if(temp->cast)
		{
			if (temp->cast == LONG_LONG || temp->cast == LONG)
				temp->octal = va_arg(args, unsigned long long);
			if (temp->cast == J_CAST)
				temp->octal = va_arg(args, uintmax_t);
			if (temp->cast == Z_CAST)
				temp->octal = va_arg(args, size_t);
			if (temp->cast == H_CAST || temp->cast == HH_CAST)
				temp->octal = va_arg(args, unsigned int);
		}
		else
			temp->octal = va_arg(args, unsigned long long);
	}
}
