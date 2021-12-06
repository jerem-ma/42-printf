/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:41:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_s.h"

int	conv_s(t_dynamic_buffer *output_line_buffer, t_options *options,
		const char *param)
{
	const unsigned char	*raw_data;

	raw_data = (const unsigned char *) ft_strdup(param);
	if (!raw_data)
		return (1);
	return (apply_general_options(output_line_buffer, options, raw_data));
}
