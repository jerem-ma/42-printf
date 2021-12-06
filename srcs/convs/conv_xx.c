/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 20:42:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_xx.h"

int	conv_xx(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	return (conv_x_common(output_line_buffer, options,
			ft_itoa_base(param, "0123456789ABCDEF")));
}
