/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:34:38 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/21 13:34:40 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void    ft_flags(char c, va_list args, int *i)
{
    if (c == 'c')
        *i += ft_printchar(va_arg(args, int));
    else if (c == 's')
        *i += ft_printstr(va_arg(args, char *));
    else if (c == 'i' || c == 'd')
        *i += ft_printint(va_arg(args, int));
    else if (c == '%')
        *i += ft_printchar('%');
}