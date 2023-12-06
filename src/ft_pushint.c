/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:15:05 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:18:23 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_pushint(int i, Node *stock)
{
	long long	n;

	n = i;
	if (n < 0)
	{
		stock = createNode('-', stock);
		n = -n;
	}
	if (n > 9)
	{
		stock = ft_pushint(n / 10, stock);
		stock = createNode(n % 10 + '0', stock);
	}
	else
		stock = createNode(n % 10 + '0', stock);
	return (stock);
}
