/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:06:14 by ikayacio          #+#    #+#             */
/*   Updated: 2022/10/28 12:43:36 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_nbr(long nbr, int *count, char format)
{
	long	temp;

	if (format == 'u' && nbr < 0)
		nbr += 4294967295 + 1;
	if (nbr == -2147483648)
		*count += write(1, "-2147483648", 11);
	else if (nbr < 0)
	{
		*count += write(1, "-", 1);
		write_nbr(nbr * -1, count, format);
	}
	else if (nbr < 10)
	{
		temp = nbr + 48;
		*count += write(1, &temp, 1);
	}
	else
	{
		write_nbr(nbr / 10, count, format);
		write_nbr(nbr % 10, count, format);
	}
}
