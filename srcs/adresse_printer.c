/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adresse_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:27:11 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/19 13:26:06 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "ft_printf.h"

int    adresse_printer(t_type *temp)
{
    long long adresse;

    adresse = (long long)&(temp->pointer);
    return 1;
    
}