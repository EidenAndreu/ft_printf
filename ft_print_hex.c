/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:15:05 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/15 14:46:38 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_put_hex_digit(unsigned int num, const char format)
{
	if (num <= 9)
		return (ft_putchar_fd((num + '0'), 1));
	else
	{
		if (format == 'x')
			return (ft_putchar_fd((num - 10 + 'a'), 1));
		else if (format == 'X')
			return (ft_putchar_fd((num - 10 + 'A'), 1));
	}
	return (-1);
}

int	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		if (ft_put_hex(num / 16, format) == -1)
			return (-1);
	}
	return (ft_put_hex_digit(num % 16, format));
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (format != 'x' && format != 'X')
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_put_hex(num, format) == -1)
			return (-1);
		return (ft_hex_len(num));
	}
	return (1);
}
