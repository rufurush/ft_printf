/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufurush <rufurush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:58:47 by rufurush          #+#    #+#             */
/*   Updated: 2025/06/14 14:37:59 by rufurush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		ft_print_p(void *ptr);
int		ft_print_x(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_print_d(int n);
int		ft_print_lx(unsigned int n);
int		ft_print_str(char *str);
int		ft_print_u(unsigned int n);
int		ft_print_c(char c);
char	*ft_strdup(const char *s);

#endif