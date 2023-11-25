/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:55:25 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 16:41:36 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

static unsigned long long	ft_count(unsigned long long ptr)
{
	unsigned long long	count;

	count = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

static void	ft_recu(unsigned long long ptr, char *hex)
{
	if (ptr != 0)
	{
		ft_recu((ptr / 16), hex);
		ft_putchar_fd(hex[ptr % 16], 1);
	}
}

unsigned long long	ft_printptr(unsigned long long ptr)
{
	unsigned long long 	len;
	char			*hex;

	hex = "0123456789abcdef";
	len = ft_count(ptr);
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_recu(ptr, hex);
	return (len + 2);
}
