/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:53 by ikayacio          #+#    #+#             */
/*   Updated: 2022/10/28 11:57:42 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_format(const char *format, int i, va_list args, int *count)
{
	int	c;

	if (format[i] == '%')
		*count += write(1, "%", 1);
	else if (format[i] == 'c')
	{
		c = va_arg(args, int);
		*count += write(1, &c, 1);
	}
	else if (format[i] == 's')
		*count += write_str(args);
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		write_nbr(va_arg(args, int), count, format[i]);
	else if (format[i] == 'x')
		write_hex(va_arg(args, int), 'x', count);
	else if (format[i] == 'X')
		write_hex(va_arg(args, int), 'X', count);
	else if (format[i] == 'p')
	{
		*count += write(1, "0x", 2);
		write_address(va_arg(args, unsigned long long), count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = i + 1;
			check_format(format, i, args, &count);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
