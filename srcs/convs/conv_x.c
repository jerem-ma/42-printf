/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 14:06:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_x.h"

int	conv_x(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	const unsigned char	*raw_data;

	raw_data = ft_itoa_base(param, "0123456789abcdef");
	if (!raw_data)
		return (1);
	return (apply_general_options(output_line_buffer, options, raw_data));
}
