/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:38 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 14:59:51 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

void	ft_flags(char c, va_list args, int *i)
{
	if (c == 'c')
		*i += ft_printchar(va_arg(args, int));
	else if (c == 's')
		*i += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		*i += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'i' || c == 'd')
		*i += ft_printint(va_arg(args, int));
	else if (c == 'u')
		*i += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		*i += ft_printhexadecimal(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		*i += ft_printhexadecimal(va_arg(args, unsigned int), 1);
	else if (c == '%')
		*i += ft_printchar('%');
	else
		*i += ft_printchar('%') + ft_printchar(c);
}
