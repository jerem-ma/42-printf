/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 14:16:08 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	treat_next_char(
		t_dynamic_buffer *output_line_buffer, const char *format,
		unsigned int *i, va_list ap
		)
{
	t_options	options;

	if (format[*i++] != '%')
		return (append(output_line_buffer, (void *) &format[*i - 1]));
	options = parse(format, i);
	if (options.conv == 'c')
		return (conv_c(output_line_buffer, &options, va_arg(ap, int)));
	if (options.conv == 's')
		return (conv_s(output_line_buffer, &options, va_arg(ap, const char *)));
	if (options.conv == 'p')
		return (conv_p(output_line_buffer, &options, va_arg(ap, void *)));
	if (options.conv == 'd' || options.conv == 'i')
		return (conv_d(output_line_buffer, &options, va_arg(ap, int)));
	if (options.conv == 'u')
		return (conv_u(output_line_buffer, &options, va_arg(ap, unsigned int)));
	if (options.conv == 'x')
		return (conv_x(output_line_buffer, &options, va_arg(ap, unsigned int)));
	if (options.conv == 'X')
		return (conv_xx(output_line_buffer, &options, va_arg(ap, unsigned int)));
	if (options.conv == '%')
		return (conv_percent(output_line_buffer, &options));
	return (1);
}
