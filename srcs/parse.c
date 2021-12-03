/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 10:29:12 by jmaia            ###   ########.fr       */
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
	options = parse(format, i);
}
