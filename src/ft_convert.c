/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:05:58 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:11:07 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_convert(unsigned int n, Node *stock, type type)
{
	int		c;
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		stock = ft_convert(n / 16, stock, type);
	c = hex[n % 16];
	if (c >= 'a' && c <= 'z' && type == hexa_max)
		c -= 32;
	return (createNode(c, stock));
}
