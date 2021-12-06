/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 14:01:37 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_x.h"

int	conv_x(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	unsigned char	*raw_nbr;
	unsigned char	*raw_data;
	size_t			raw_nbr_size;

	raw_nbr = ft_itoa_base(param, "0123456789abcdef");
	raw_nbr_size = ft_strlen((const char *) raw_nbr) + 1;
	if (!raw_nbr)
		return (1);
	if (has_flag(options->flags, FLAG_ALTERNATE_FORM) && param != 0)
	{
		raw_data = malloc(sizeof(*raw_data) * (raw_nbr_size + 2));
		if (!raw_data)
		{
			free(raw_nbr);
			return (1);
		}
		ft_memcpy(raw_data + 2, raw_nbr, raw_nbr_size);
		raw_data[0] = '0';
		raw_data[1] = 'x';
	}
	else
		raw_data = raw_nbr;
	return (apply_general_options(output_line_buffer, options, raw_data));
}
