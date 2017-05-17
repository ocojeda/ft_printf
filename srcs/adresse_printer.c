/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:27:11 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/17 15:27:13 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "ft_printf.h"

void    adresse_printer(t_type *temp)
{
    long long adresse;

    adresse = (long long)&(temp->pointer);
    
}