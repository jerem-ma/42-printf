/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:31:41 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 13:50:08 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list				ap;
	unsigned int		i;
	t_dynamic_buffer	output_line_buffer;
	char				*output_line;
	int					err;

	output_line_buffer = get_buffer(sizeof(char));
	va_start(ap, format);
	i = 0;
	while (format[i])
		treat_next_char(&output_line_buffer, format, &i, ap);
	output_line = as_str(&output_line_buffer);
	ft_putstr_fd(output_line, 1);
	va_end(ap);
	if (err)
		return (-1);
	else
		return (ft_strlen(output_line));
}
