/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:50:11 by ikayacio          #+#    #+#             */
/*   Updated: 2022/10/28 12:44:56 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_str(va_list args)
{
	char	*s;
	int		count;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		count += write(1, "(null)", 6);
	else
	{
		while (*s != '\0')
		{
			count += write(1, s, 1);
			s++;
		}
	}
	return (count);
}
