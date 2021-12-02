/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:43:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 15:53:44 by jmaia            ###   ########.fr       */
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
