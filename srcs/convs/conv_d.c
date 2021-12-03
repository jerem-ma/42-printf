/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 14:04:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_d.h"

int	conv_d(t_dynamic_buffer *output_line_buffer, t_options *options, int param)
{
	const unsigned char	*raw_data;

	raw_data = ft_itoa(param);
	if (!raw_data)
		return (1);
	return (apply_general_options(output_line_buffer, options, raw_data));
}
