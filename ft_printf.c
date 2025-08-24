/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:00:19 by rufurush          #+#    #+#             */
/*   Updated: 2025/06/14 14:30:13 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_format(const char *format, va_list args, size_t *i)
{
	int	count;

	count = 0;
	if (format[*i] == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count = ft_print_d(va_arg(args, int));
	else if (format[*i] == 'c')
		count = ft_print_c(va_arg(args, unsigned int));
	else if (format[*i] == 'p')
		count = ft_print_p(va_arg(args, void *));
	else if (format[*i] == 'u')
		count = ft_print_u(va_arg(args, unsigned int));
	else if (format[*i] == 'x')
		count = ft_print_x(va_arg(args, unsigned int));
	else if (format[*i] == 'X')
		count = ft_print_lx(va_arg(args, unsigned int));
	else if (format[*i] == '%')
		count = write(1, "%", 1);
	(*i)++;
	if (count == -1)
		return (-1);
	return (count);
}

static int	handle_percent(const char *format, va_list args, size_t *i,
		int *count)
{
	int	ret;

	*i += 1;
	ret = ft_parse_format(format, args, i);
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (handle_percent(format, args, &i, &count) == -1)
				return (-1);
		}
		else if (write(1, &format[i++], 1) == -1)
			return (-1);
		else
			count++;
	}
	va_end(args);
	return (count);
}
