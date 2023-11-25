/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:33 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 15:30:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_printstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_printchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_printchar(n % 10 + '0');
}

static int	ft_count(long i)
{
	int	a;

	a = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		a++;
		i = -i;
	}
	while (i > 0)
	{
		i /= 10;
		a++;
	}
	return (a);
}

int	ft_printint(int i)
{
	ft_putnbr(i);
	return (ft_count(i));
}
