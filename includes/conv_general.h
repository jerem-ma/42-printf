/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_general.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:23 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:20:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_GENERAL_H
# define CONV_GENERAL_H

# include "libdynamic_buffer.h"
# include "types.h"
# include "flags.h"

int	apply_general_options(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data);
#endif
