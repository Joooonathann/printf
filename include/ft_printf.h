/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:27:23 by jalbiser          #+#    #+#             */
/*   Updated: 2023/12/01 05:23:12 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct Node
{
    char            data;
    struct Node    *next;
}   Node;

typedef enum    types
{
    hexa_min,
    hexa_max
}   type;

int ft_printf(const char *format, ...);
Node	*createNode(char data, Node *stock);
Node	*ft_convert(unsigned int n, Node *stock, type type);
Node	*ft_flags(char c, Node *stock, va_list args);
int	ft_printchar(int data);
int	ft_printlist(Node *list);
Node	*ft_pushint(int i, Node *stock);
Node	*ft_pushintunsigned(unsigned int i, Node *stock);
Node	*ft_pushstr(char *str, Node *stock);
Node	*ft_stock(const char *format, va_list args);
void	ft_freeStock(Node *stock);
Node	*ft_convert_ptr(unsigned long long n, Node *stock);

#endif
