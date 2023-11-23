/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:27:23 by jalbiser          #+#    #+#             */
/*   Updated: 2023/11/22 15:04:17 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_flags(char c, va_list args, int *i);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printint(int i);
unsigned long long	ft_printptr(unsigned long long ptr);
int     ft_printunsigned(int i);
unsigned int ft_printhexadecimal(unsigned int n);

#endif