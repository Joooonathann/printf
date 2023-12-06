/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:41:25 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 09:47:35 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printlist(Node *list)
{
	Node	*current = list;
	int		i;

	i = 0;
	while (current != NULL)
	{
		if (ft_printchar(current->data) == -1)
			return (-1);
		current = current->next;
		i++;
	}
	return (i);
}
