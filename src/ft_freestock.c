/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:35:18 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:37:29 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_freeStock(Node *stock)
{
    Node    *current;
    Node    *tmp;

    current = stock;
    while (current != NULL)
    {
        tmp = current;
        current = current->next;
        free(current);    
    }
}
