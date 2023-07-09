#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_printstr(char *str)
{
	int len = 0; // Variable para almacenar la longitud
	int i = 0;   // Variable para iterar sobre la cadena

	if (str == NULL)
	{
		ft_putstr("(null)");
		return 6;
	}

	while (str[i])
	{
		write(1, &str[i], 1);
		len++; // Incrementar la longitud en cada iteración
		i++;
	}

	return len;
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
	write(1, "%", 1);
	return (1);
}
