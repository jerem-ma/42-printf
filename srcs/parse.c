/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 18:53:41 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treat_next_char(
		t_dynamic_buffer *output_line_buffer, const char *format,
		unsigned int *i, va_list ap
		)
{
	t_options	options;

	if (format[*i++] != '%')
		return (append(output_line_buffer, format[i - 1]));
}

static t_options	parse(const char *field)
{
	t_options	options;

	init_options(&options);
	return (options);
}

static void	init_options(t_options *options)
{
	options->flags = 0;
	options->minimal_field_width = 0;
	options->data = 0;
	options->conv = 0;
}

static int	is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}
