/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:26:32 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/21 13:26:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int     i;

    i = 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
            ft_flags(*++str, args, &i);
        else
            i += ft_printchar(*str);
        *str++;
    }
    va_end(args);
    return (i);
}

int main(void)
{
    int i = ft_printf("dfdd sddssd sdsdsds %i", 458794);
}