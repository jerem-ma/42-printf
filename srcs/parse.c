/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 19:41:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	treat_next_char(
		t_dynamic_buffer *output_line_buffer, const char *format,
		unsigned int *i, va_list ap
		)
{
	t_options	options;

	if (format[*i++] != '%')
		return (append(output_line_buffer, (void *) &format[*i - 1]));
}

static t_options	parse(const char *field)
{
	t_options	options;
	int			i;

	init_options(&options);
	i = 0;
	while (field[i] && is_flag(field[i]))
	{
		options.flags &= get_flag_code(field[i]);
		i++;
	}
	while (field[i] && ft_isdigit())
	{

	}
	if (is_conv(field[i]))
		options.conv = field[i];
	else
		options.flags = FLAG_ERROR;
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
