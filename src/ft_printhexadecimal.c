/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexadecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:33 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 15:30:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

static unsigned int	ft_count(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	ft_recu(unsigned int n, char hex[16])
{
	if (n != 0)
	{
		ft_recu((n / 16), hex);
		ft_putchar_fd(hex[n % 16], 1);
	}
}

unsigned int	ft_printhexadecimal(unsigned int n, int size)
{
	char			hex_min[16];
	char			hex_max[16];
	unsigned int	len;

	hex_min[16] = "0123456789abcdef";
	hex_max[16] = "0123456789ABCDEF";
	len = ft_count(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (size == 0)
		ft_recu(n, hex_min);
	else
		ft_recu(n, hex_max);
	return (len);
}
