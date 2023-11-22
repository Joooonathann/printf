/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:33 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 15:30:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static unsigned int	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

static int	ft_count(long i)
{
	unsigned int	a;

	a = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		a++;
	}
	return (a);
}

int	ft_printunsigned(int i)
{
	ft_putnbr_unsigned(i);
	return (ft_count(i));
}
