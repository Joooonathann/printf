/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:18:40 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:20:40 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_pushstr(char *str, Node *stock)
{
	if (!str)
		str = "(NULL)";
	while (*str)
	{
		stock = createNode(*str, stock);
		str++;
	}
	return (stock);
}
