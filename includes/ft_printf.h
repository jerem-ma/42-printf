/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:22:32 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 15:48:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAG_0_PAD 1
# define FLAG_LEFT_ADJUSTED 2
# define FLAG_PRECISION 4
# define FLAG_ALTERNATE_FORM 8
# define FLAG_BLANK 16
# define FLAG_ALWAYS_SIGN 32

# include <unistd.h>
# include <stdarg.h>

# include "libft.h"
# include "libdynamic_buffer.h"

typedef struct s_options
{
	unsigned char	flags;
	int				minimal_field_width;
	char			*data;
}	t_options;

int	ft_printf(const char *format, ...);
static int	treat_next_char(
		t_dynamic_buffer *output_line_buffer, const char *format,
		unsigned int *i, va_list ap
		);
static t_options	parse(const char *field);
#endif
