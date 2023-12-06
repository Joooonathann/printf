/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:48:58 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/06 09:52:45 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

Node	*ft_stock(const char *format, va_list args)
{
	Node	*stock;

	stock = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			stock = ft_flags(*format, stock, args);
		}
		else
			stock = createNode(*format, stock);
		format++;
	}
	return (stock);
}
