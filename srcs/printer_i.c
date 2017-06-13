/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:36:55 by myernaux          #+#    #+#             */
/*   Updated: 2017/06/13 05:35:03 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		printer2(t_type *temp)
{
	if (temp->type == CHAR)
		return (print_chars(temp));
	if (temp->type == INTU)
		return (print_unumber(temp));
	if (temp->type == INTLU)
		return (print_lunumber(temp));
	if (temp->type == INTL)
		return (ft_putllnbr(temp));
	if (temp->type == POINTER_ADRESSE)
		return (adresse_printer(temp));
	if (temp->type == OCTAL)
		return (ft_putoctal(temp));
	if (temp->type == OCTALM)
		return (ft_putoctalm(temp));
	if (temp->type == WCHAR)
		return (ft_putwchar(temp->wc));
	if (temp->type == WSTR)
		return (ft_putwstr(temp, temp->wstr, 0, 0));
	return (0);
}

int				printer(t_type *all)
{
	if (all->type == STR)
		return (print_string(all, 0));
	if (all->type == INTI)
		return (print_number(all));
	if (all->type == HEXA)
		return (ft_puthexa(all));
	if (all->type == HEXAM)
		return (ft_puthexa(all));
	if (all->type == D_MOD)
		return (ft_double_modulo_handler(all));
	return (printer2(all));
}
