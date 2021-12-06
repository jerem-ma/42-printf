/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 18:16:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_p.h"

int	conv_p(t_dynamic_buffer *output_line_buffer, t_options *options,
		void *param)
{
	unsigned char		*raw_data;
	unsigned char		*final_data;
	unsigned long int	ptr;

	ptr = (unsigned long int) param;
	raw_data = ft_itoa_base(ptr, "0123456789abcdef");
	if (!raw_data)
		return (1);
	final_data = malloc(sizeof(*final_data)
			* (ft_strlen((const char *)raw_data) + 3));
	if (!final_data)
	{
		free(raw_data);
		return (1);
	}
	ft_memcpy(final_data + 2, raw_data, ft_strlen((const char *)raw_data) + 1);
	raw_data[0] = '0';
	raw_data[1] = 'x';
	return (apply_general_options(output_line_buffer, options, raw_data));
}
