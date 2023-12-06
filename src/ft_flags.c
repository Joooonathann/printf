/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:52:53 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 10:11:37 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_flags(char c, Node *stock, va_list args)
{
	int	p;

	p = 0;
	if (c == 'c')
		stock = createNode(va_arg(args, int), stock);
	else if (c == 's')
		stock = ft_pushstr(va_arg(args, char *), stock);
	else if (c == 'p')
		stock = ft_convert(va_arg(args, unsigned long long), stock, pointer, &p);
	else if (c == 'd' || c == 'i')
		stock = ft_pushint(va_arg(args, int), stock);
	else if (c == 'u')
		stock = ft_pushintunsigned(va_arg(args, unsigned int), stock);
	else if (c == 'x')
		stock = ft_convert(va_arg(args, unsigned long long), stock, hexa_min, &p);
	else if (c == 'X')
		stock = ft_convert(va_arg(args, unsigned long long), stock, hexa_max, &p);
	else if (c == '%')
		stock = createNode('%', stock);
	else
	{
		stock = createNode('%', stock);
		stock = createNode(c, stock);
	}
	return (stock);
}
