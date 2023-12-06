/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:36:17 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 11:36:18 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_convert_ptr(unsigned long long n, Node *stock)
{
	int		c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		stock = ft_convert_ptr(n / 16, stock);
	c = hex[n % 16];
	return (createNode(c, stock));
}