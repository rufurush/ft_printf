/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:59:45 by rufurush          #+#    #+#             */
/*   Updated: 2025/05/09 15:42:14 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
