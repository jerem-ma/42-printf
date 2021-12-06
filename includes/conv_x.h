/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:45:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_X_H
# define CONV_X_H

# include <stdlib.h>

# include "libft.h"
# include "libdynamic_buffer.h"

# include "conv_general.h"
# include "flags.h"
# include "types.h"

int	conv_x(t_dynamic_buffer *output_line, t_options *options,
		unsigned int param);
#endif
