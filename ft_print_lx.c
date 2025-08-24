/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:03:35 by rufurush          #+#    #+#             */
/*   Updated: 2025/06/15 16:41:55 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*ft_malloc_string(unsigned int n)
{
	char	*result;
	int		malloc_len;

	malloc_len = ft_digit_len(n);
	result = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (!result)
		return (NULL);
	return (result);
}

int	ft_print_lx(unsigned int n)
{
	int		result_len;
	int		digit;
	char	*result;

	result_len = ft_digit_len(n);
	digit = ft_digit_len(n);
	result = ft_malloc_string(n);
	while (result_len > 0)
	{
		if ((n % 16) < 10)
			result[--result_len] = '0' + (n % 16);
		else
			result[--result_len] = 'A' + (n % 16) - 10;
		n /= 16;
	}
	write(1, result, digit);
	free(result);
	return (digit);
}
