/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:42:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_U_H
# define CONV_U_H

# include "libft.h"
# include "libdynamic_buffer.h"

# include "conv_general.h"
# include "types.h"

int	conv_u(t_dynamic_buffer *output_line, t_options *options,
		unsigned int param);
#endif
