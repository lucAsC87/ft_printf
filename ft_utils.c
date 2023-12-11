/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:26:45 by lucavall          #+#    #+#             */
/*   Updated: 2023/12/07 13:25:36 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str != '\0')
	{
		ft_putchar((int)*str);
		counter++;
		str++;
	}
	return (counter);
}

int	ft_putnum_base(long num, int base)
{
	int		counter;
	char	*hexadecimals;

	hexadecimals = "0123456789abcdef";
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_putnum_base(-num, base) + 1);
	}
	else if (num < base)
		return (ft_putchar(hexadecimals[num]));
	else
	{
		counter = ft_putnum_base((num / base), base);
		return (counter + ft_putchar(hexadecimals[num % base]));
	}
}

int	ft_putnum_base_up(long num, int base)
{
	int		counter;
	char	*hexadecimals;

	hexadecimals = "0123456789ABCDEF";
	if (num < 0)
	{
		write(1, "-", 1);
		return (ft_putnum_base_up(-num, base) + 1);
	}
	else if (num < base)
		return (ft_putchar(hexadecimals[num]));
	else
	{
		counter = ft_putnum_base_up((num / base), base);
		return (counter + ft_putchar(hexadecimals[num % base]));
	}
}

int	ft_point(unsigned long num, unsigned int base)
{
	int		counter;
	char	*hexadecimals;

	hexadecimals = "0123456789abcdef";
	if (num < base)
		return (ft_putchar(hexadecimals[num]));
	else
	{
		counter = ft_point((num / base), base);
		return (counter + ft_putchar(hexadecimals[num % base]));
	}
}
