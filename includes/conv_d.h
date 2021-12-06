/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:46:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_D_H
# define CONV_D_H

# include <stdlib.h>

# include "libft.h"
# include "libdynamic_buffer.h"

# include "types.h"
# include "flags.h"
# include "conv_general.h"

int	conv_d(t_dynamic_buffer *output_line, t_options *options, int param);
unsigned char	*append_left_char(char left_char, const char *str);
#endif
