/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:46 by lucavall          #+#    #+#             */
/*   Updated: 2023/12/07 13:51:28 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pointers(va_list args)
{
	void	*ptr;
	int		counter;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		counter = 0;
		counter += write(1, "0x", 2);
		counter += ft_point((unsigned long)ptr, 16);
		return (counter);
	}
}

static int	ft_checkf(char f, va_list args)
{
	if (f == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (f == 'i' || f == 'd')
		return (ft_putnum_base((long)(va_arg(args, int)), 10));
	else if (f == 'u')
		return (ft_putnum_base((long)(va_arg(args, unsigned int)), 10));
	else if (f == 'x')
		return (ft_putnum_base((long)(va_arg(args, unsigned int)), 16));
	else if (f == 'X')
		return (ft_putnum_base_up((long)(va_arg(args, unsigned int)), 16));
	else if (f == 'p')
		return (handle_pointers(args));
	else
		return (write(1, &f, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	va_start(args, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			counter += ft_checkf(*(++format), args);
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (counter);
}

/* #include <stdio.h>
int	main(void)
{
	int	count;
	int	x = 10;
	int *p = &x;

	count = ft_printf("\n");
	count = printf("\n");
	count = ft_printf("Ft_printf %s\n", "test", "extra");
	count = printf("Printf %s\n", "test", "extra");
	count = ft_printf("Ft_printf %%c: %c\n", 'c');
	count = printf("Printf %%c: %c\n", 'c');
	count = ft_printf("Ft_printf %%s: %s\n", "A string.");
	count = printf("Printf %%s: %s\n", "A string.");
	count = ft_printf("Ft_printf %%p: %p\n", p);
	count = printf("Printf %%p: %p\n", p);
	count = ft_printf("Ft_printf %%d: %d\n", -2147483647);
	count = printf("Printf %%d: %d\n", -2147483647);
	count = ft_printf("Ft_printf %%d: %d\n", 2147483647);
	count = printf("Printf %%d: %d\n", 2147483647);
	count = ft_printf("Ft_printf %%i: %i\n", -2147483647);
	count = printf("Printf %%i: %i\n", -2147483647);
	count = ft_printf("Ft_printf %%i: %i\n", 2147483647);
	count = printf("Printf %%i: %i\n", 2147483647);
	count = ft_printf("Ft_printf %%u: %u\n", (unsigned int)-4294967295);
	count = printf("Printf %%u: %u\n", (unsigned int)-4294967295);
	count = ft_printf("Ft_printf %%u: %u\n", (unsigned int)4294967295);
	count = printf("Printf %%u: %u\n", (unsigned int)4294967295);
	count = ft_printf("Ft_printf %%x: %x\n", 2147483647);
	count = printf("Printf %%x: %x\n", 2147483647);
	count = ft_printf("Ft_printf %%X: %X\n", 2147483647);
	count = printf("Printf %%X: %X\n", 2147483647);
	count = ft_printf("Ft_printf %%%%: stampa il simbolo %%\n");
	count = printf("Printf %%%%: stampa il simbolo %%\n");
} */
