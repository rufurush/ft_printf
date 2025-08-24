/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:01:23 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/09 18:11:52 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_count(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_utoa(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ft_digit_count(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		--len;
		str[len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

int	ft_print_u(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
