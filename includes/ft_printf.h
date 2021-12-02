/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:22:32 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 15:33:34 by jmaia            ###   ########.fr       */
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

int	ft_printf(const char *format, ...);
#endif
