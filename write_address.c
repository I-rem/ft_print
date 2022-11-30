/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:21:45 by ikayacio          #+#    #+#             */
/*   Updated: 2022/10/28 12:44:37 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_address(unsigned long long p, int *count)
{
	char	temp;

	if (p < 16)
	{
		temp = "0123456789abcdef"[p];
		*count += write(1, &temp, 1);
	}
	else
	{
		write_address(p / 16, count);
		write_address(p % 16, count);
	}
}
