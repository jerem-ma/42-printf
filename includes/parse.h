/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:22:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 19:31:31 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libdynamic_buffer.h"
# include "ft_printf.h"
# include "flags.h"
# include "types.h"

static int			treat_next_char(
						t_dynamic_buffer *output_line_buffer,
						const char *format, unsigned int *i, va_list ap
						);
static void			init_options(t_options *options);
static t_options	parse(const char *field);
#endif
