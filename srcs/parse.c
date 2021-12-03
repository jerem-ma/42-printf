/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 11:54:36 by jmaia            ###   ########.fr       */
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
		return (conv_c(&options, va_arg(ap, int)));
	if (options.conv == 's')
		return (conv_s(&options, va_arg(ap, const char *)));
	if (options.conv == 'p')
		return (conv_p(&options, va_arg(ap, void *)));
	if (options.conv == 'd' || options.conv == 'i')
		return (conv_d(&options, va_arg(ap, int)));
	if (options.conv == 'u')
		return (conv_u(&options, va_arg(ap, unsigned int)));
	if (options.conv == 'x')
		return (conv_x(&options, va_arg(ap, unsigned int)));
	if (options.conv == 'X')
		return (conv_X(&options, va_arg(ap, unsigned int)));
	if (options.conv == '%')
		return (conv_percent(&options, 0));
	return (1);
}
