/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:38:54 by ikayacio          #+#    #+#             */
/*   Updated: 2022/10/28 12:43:25 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_hex(long nbr, char format, int *count)
{
	int	temp;

	if (nbr < 0)
		nbr += 4294967296;
	if (nbr < 16)
	{
		if (format == 'x')
			temp = "0123456789abcdef"[nbr];
		else
			temp = "0123456789ABCDEF"[nbr];
		*count += write(1, &temp, 1);
	}
	else
	{
		write_hex(nbr / 16, format, count);
		write_hex(nbr % 16, format, count);
	}
}
