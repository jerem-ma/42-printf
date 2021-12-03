/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 18:04:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_C_H
# define CONV_C_H

# include "types.h"
# include "libdynamic_buffer.h"

int			conv_c(t_dynamic_buffer *output_line, t_options *options, int param);
static char	*append_left_char(char left_char, char *str);
#endif
