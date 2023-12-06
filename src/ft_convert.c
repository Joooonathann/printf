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

Node	*ft_convert(unsigned long long n, Node *stock, type type, int *p)
{
	int		c;
	char	*hex;

	hex = "0123456789abcdef";
	if (type == pointer && *p == 0)
	{
		stock = ft_pushstr("0x", stock);
		*p = 1;
	}
	if (n >= 16)
		stock = ft_convert(n / 16, stock, type, p);
	c = hex[n % 16];
	if (c >= 'a' && c <= 'z' && type == hexa_max)
		c -= 32;
	return (createNode(c, stock));
}
