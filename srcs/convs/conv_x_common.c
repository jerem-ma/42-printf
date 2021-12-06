/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 20:26:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_x_common.h"

int	conv_x_common(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned char *nbr)
{
	int				err;

	if (!nbr)
		return (1);
	err = apply_number_precision(options, &nbr);
	if (err)
	{
		free(nbr);
		return (err);
	}
	if (has_flag(options->flags, FLAG_ALTERNATE_FORM) && nbr[0])
	{
		err = apply_alternate_form(options, &nbr);
		if (err)
		{
			free(nbr);
			return (err);
		}
	}
	return (apply_general_options(output_line_buffer, options, nbr));
}

int	apply_alternate_form(t_options *options, unsigned char **raw_data)
{
	unsigned char	*new_data;
	int				raw_data_size;

	raw_data_size = ft_strlen((const char *) *raw_data) + 1;
	if (!has_flag(options->flags, FLAG_ALTERNATE_FORM))
		return (0);
	new_data = malloc(sizeof(*new_data) * (raw_data_size + 2));
	if (!new_data)
		return (1);
	ft_memcpy(new_data + 2, *raw_data, raw_data_size);
	new_data[0] = '0';
	new_data[1] = 'x';
	free(*raw_data);
	*raw_data = new_data;
	return (0);
}
