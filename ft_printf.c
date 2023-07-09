#include "ft_printf.h"

int ft_printchar(char c)
{
	if (c == '\t')
	{
		write(1, "\\t", 2);
		return (2);
	}
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

/* #include <stdio.h>
int main(void)
{
    // Pruebas para ft_uitoa y ft_num_len
    unsigned int num = 12345;
    char *num_str = ft_uitoa(num);
    int len = ft_num_len(num);
    printf("Number: %u\n", num);
    printf("Converted String: %s\n", num_str);
    printf("Length: %d\n", len);

    // Pruebas para ft_hex_len
    unsigned int hex_num = 0xABCD;
    int hex_len = ft_hex_len(hex_num);
    printf("Hex Number: 0x%X\n", hex_num);
    printf("Hex Length: %d\n", hex_len);

    // Pruebas para ft_put_hex
    unsigned int hex_num2 = 255;
    printf("Hex Number: 0x%X\n", hex_num2);
    printf("Hex Representation: ");
    ft_put_hex(hex_num2, 'x');
    printf("\n");

    return 0;
}
*/
