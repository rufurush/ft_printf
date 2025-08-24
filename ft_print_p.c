/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:03:00 by rufurush          #+#    #+#             */
/*   Updated: 2025/08/21 18:12:53 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_len(unsigned long nbr, char *base)
{
	int				len;
	int				base_len;
	unsigned long	unbr;

	if (nbr == 0)
		return (1);
	len = 0;
	base_len = ft_strlen(base);
	unbr = nbr;
	while (unbr != 0)
	{
		unbr /= base_len;
		len++;
	}
	return (len);
}

static char	*ft_malloc_strings(unsigned long nbr, char *base)
{
	int		malloc_len;
	char	*word;

	malloc_len = ft_base_len(nbr, base);
	if (nbr == 0)
	{
		word = (char *)malloc(2);
		if (!word)
			return (NULL);
		word[0] = base[0];
		word[1] = '\0';
		return (word);
	}
	word = (char *)malloc(sizeof(char) * (malloc_len + 1));
	if (!word)
		return (NULL);
	return (word);
}

static char	*ft_store_strings(unsigned long nbr, char *base)
{
	int				malloc_len;
	int				len;
	char			*result;
	unsigned long	unbr;
	int				base_len;

	malloc_len = ft_base_len(nbr, base);
	result = ft_malloc_strings(nbr, base);
	len = malloc_len - 1;
	base_len = ft_strlen(base);
	result[malloc_len] = '\0';
	unbr = nbr;
	while (unbr != 0)
	{
		result[len] = base[unbr % base_len];
		unbr /= base_len;
		len--;
	}
	return (result);
}

static char	*ft_putnbr_base(unsigned long nbr, char *base)
{
	char	*result;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	result = ft_store_strings(nbr, base);
	return (result);
}

int	ft_print_p(void *ptr)
{
	unsigned long	address;
	char			*str;
	int				len;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	address = (unsigned long)ptr;
	str = ft_putnbr_base(address, "0123456789abcdef");
	if (!str)
		return (-1);
	write(1, "0x", 2);
	len = ft_print_str(str);
	free(str);
	return (len + 2);
}
