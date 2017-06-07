/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:36:55 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/07 14:37:00 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printer2(t_type *temp, int everything)
{
	if (temp->type == CHAR)
		everything += print_chars(temp);
	if (temp->type == INTU)
		everything += print_unumber(temp);
	if (temp->type == INTLU)
		everything += print_lunumber(temp);
	if (temp->type == INTL)
		everything += print_lnumber(temp);
	if (temp->type == POINTER_ADRESSE)
		everything += adresse_printer(temp);
	if (temp->type == OCTAL)
		everything += ft_putoctal(temp);
	if (temp->type == OCTALM)
		everything += ft_putoctalm(temp);
	if (temp->type == WCHAR)
		everything += ft_putwchar(temp->wc);
	if (temp->type == WSTR)
		everything = ft_putwstr(temp, temp->wstr, everything);
	return (everything);
}

int		printer(t_type *all)
{
	t_type	*temp;
	int		everything;

	everything = 0;
	temp = all;
	if (temp)
	{
		if (temp->type == STR)
			everything = print_string(temp, everything);
		if (temp->type == INTI)
			everything += print_number(temp);
		if (temp->type == HEXA)
			everything += ft_puthexa(temp);
		if (temp->type == HEXAM)
			everything += ft_puthexa(temp);
		if (temp->type == D_MOD)
			everything += ft_double_modulo_handler(temp);
		everything = printer2(temp, everything);
	}
	return (everything);
}
