/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:00:51 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/09 19:39:46 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_count(unsigned int n)
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

static char	*ft_malloc_strings(unsigned int n)
{
	int		len;
	char	*result;

	len = ft_digit_count(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	return (result);
}

int	ft_print_x(unsigned int n)
{
	int		result_len;
	char	*result;
	int		digit;

	result_len = ft_digit_count(n);
	result = ft_malloc_strings(n);
	digit = ft_digit_count(n);
	result[result_len] = '\0';
	while (result_len > 0)
	{
		if ((n % 16) < 10)
			result[--result_len] = '0' + (n % 16);
		else
			result[--result_len] = 'a' + (n % 16) - 10;
		n /= 16;
	}
	write(1, result, digit);
	free(result);
	return (digit);
}
