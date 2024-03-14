/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan    <hkocan@student.42kocaeli.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:47 by hkocan            #+#    #+#             */
/*   Updated: 2024/02/26 15:03:57 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putstr(char *str, int i)
{
	int	result;

	result = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		result = write(1, &str[i], 1);
		if (result < 0)
			return (-1);
		i += result;
	}
	return (i);
}

int	put_digit(long long int number, char *base, int bsize)
{
	int	counter;
	int	tmp;

	counter = 0;
	if (number < 0 && bsize == 10)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		number *= -1;
		counter++;
	}
	if (number >= bsize)
	{
		tmp = put_digit(number / bsize, base, bsize);
		if (tmp < 0)
			return (-1);
		counter += tmp;
	}
	if (write(1, &base[number % bsize], 1) < 0)
		return (-1);
	return (counter + 1);
}

int	put_digit_pointer(void *point, char *base, int bsize)
{
	int					counter;
	int					tmp;
	unsigned long int	number;

	number = (unsigned long int)point;
	counter = 0;
	if (number >= (unsigned long int)bsize)
	{
		tmp = put_digit_pointer((void *)(number / bsize), base, bsize);
		if (tmp < 0)
			return (-1);
		counter += tmp;
	}
	if (write(1, &base[number % bsize], 1) < 0)
		return (-1);
	return (counter + 1);
}

int	ft_formats(va_list args, const char formats)
{
	if (formats == 'c')
		return (write(1, &(char){va_arg(args, int)}, 1));
	else if (formats == 's')
		return (ft_putstr(va_arg(args, char *), 0));
	else if (formats == 'p')
	{
		if (ft_putstr("0x", 0) < 0)
			return (-1);
		return (2 + put_digit_pointer(va_arg(args, void *), "0123456789abcdef",
				16));
	}
	else if (formats == 'd' || formats == 'i')
		return (put_digit(va_arg(args, int), "0123456789", 10));
	else if (formats == 'u')
		return (put_digit(va_arg(args, unsigned int), "0123456789", 10));
	else if (formats == 'x')
		return (put_digit(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (formats == 'X')
		return (put_digit(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (formats == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		result;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			result = ft_formats(args, *(++format));
		else
			result = write(1, format, 1);
		if (result < 0)
			return (-1);
		len += result;
		format++;
	}
	va_end(args);
	return (len);
}
