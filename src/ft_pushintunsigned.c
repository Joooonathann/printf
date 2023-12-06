/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushintunsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:11:53 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:14:48 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_pushintunsigned(unsigned int i, Node *stock)
{
	if (i > 9)
	{
		stock = ft_pushintunsigned(i / 10, stock);
		stock = createNode(i % 10 + '0', stock);
	}
	else
		stock = createNode(i % 10 + '0', stock);
	return (stock);
}
