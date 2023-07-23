/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:10:51 by ereinald          #+#    #+#             */
/*   Updated: 2023/07/23 18:33:48 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printstr(char *str)
{
	int	len;
	int	res;
	int	i;

	len = 0;
	res = 0;
	i = 0;
	if (str == NULL)
	{
		return (ft_putstr("(null)"));
	}
	while (str[i])
	{
		len = write(1, &str[i], 1);
		if (len == -1)
			return (-1);
		res += len;
		i++;
	}
	return (res);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	return (write(1, "%", 1));
}
