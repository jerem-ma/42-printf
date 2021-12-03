/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:22:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 12:34:04 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdarg.h>

# include "libdynamic_buffer.h"
# include "ft_printf.h"
# include "flags.h"
# include "types.h"
# include "convs.h"

int			treat_next_char(
				t_dynamic_buffer *output_line_buffer,
				const char *format, unsigned int *i, va_list ap
				);
t_options	parse(const char *field, unsigned int *i);
#endif
