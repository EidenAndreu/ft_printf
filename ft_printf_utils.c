/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:10:51 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/05 15:32:34 by ereinald         ###   ########.fr       */
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
		if (write(1, &str[i], 1) == -1)
			return (-1);
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
		if (write(1, &str[i], 1) == -1)
			return (-1);
		len++;
		i++;
	}
	return (len);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_printstr(num);
	free(num);
	return (len);
}

int	ft_printpercent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
