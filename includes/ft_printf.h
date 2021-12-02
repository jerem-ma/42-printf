/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:22:32 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 19:30:04 by jmaia            ###   ########.fr       */
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

# include "parse.h"

int					ft_printf(const char *format, ...);
static int			is_conv(char c);
#endif
