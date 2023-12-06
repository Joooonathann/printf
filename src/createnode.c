/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:22:34 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:26:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*createNode(char data, Node *stock)
{
	Node	*new;
	Node	*current;

	new = malloc(sizeof(Node));
	if (!new)
	{
		ft_freeStock(stock);
		return (NULL);
	}
	new->data = data;
	new->next = NULL;
	if (stock == NULL)
		return (new);
	current = stock;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	return (stock);
}
