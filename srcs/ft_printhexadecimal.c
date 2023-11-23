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
#include "../includes/ft_printf.h"

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

unsigned int ft_printhexadecimal(unsigned int n)
{
	char			hex[16] = "0123456789abcdef";
	unsigned int	len = ft_count(n);

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_recu(n, hex);
	return (len);
}
