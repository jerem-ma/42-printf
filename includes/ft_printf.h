/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:22:32 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 18:39:07 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAG_ERROR 1
# define FLAG_0_PAD 2
# define FLAG_LEFT_ADJUSTED 4
# define FLAG_PRECISION 8
# define FLAG_ALTERNATE_FORM 16
# define FLAG_BLANK 32
# define FLAG_ALWAYS_SIGN 64

# include <unistd.h>
# include <stdarg.h>

# include "libft.h"
# include "libdynamic_buffer.h"

typedef struct s_options
{
	unsigned char	flags;
	int				minimal_field_width;
	char			*data;
	char			conv;
}	t_options;

int					ft_printf(const char *format, ...);
static int			treat_next_char(
						t_dynamic_buffer *output_line_buffer,
						const char *format, unsigned int *i, va_list ap
						);
static t_options	parse(const char *field);
static int			is_conv(char c);
#endif
