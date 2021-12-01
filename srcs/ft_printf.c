/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:31:41 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/30 22:44:16 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list				ap;
	unsigned int		i;
	t_infinite_string	*output_line;

	va_start(ap, format);
	i = 0;
	while (format[i])
		treat_next_char(output_line, format, &i, ap);
	ft_putstr(get_str(output_line));
	va_end(ap);
}
