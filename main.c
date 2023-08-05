/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:39:52 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/05 13:45:58 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    char c = 'A';
    char *str = "Hello";
    void *ptr = (void *)0x12345678;
    int num = (double)42.5;
    unsigned int uns_num = 123456;
    int hex_num = 255;


    printf("%%c: %c\n", c);
    printf("%%s: %s\n", str);
    printf("%%p: %p\n", ptr);
    printf("%%d: %d\n", num);
    printf("%%i: %i\n", num);
    printf("%%u: %u\n", uns_num);
    printf("%%x: %x\n", hex_num);
    printf("%%X: %X\n", hex_num);
    printf("%%%%: %%\n");

    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", str);
    ft_printf("%%p: %p\n", ptr);
    ft_printf("%%d: %d\n", num);
    ft_printf("%%i: %i\n", num);
    ft_printf("%%u: %u\n", uns_num);
    ft_printf("%%x: %x\n", hex_num);
    ft_printf("%%X: %X\n", hex_num);
    ft_printf("%%%%: %%\n");


	return 0;
}
