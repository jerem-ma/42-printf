/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/07 09:38:26 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_s.h"

int	conv_s(t_dynamic_buffer *output_line_buffer, t_options *options,
		const char *param)
{
	unsigned char	*raw_data;
	int				err;

	raw_data = (unsigned char *) ft_strdup(param);
	if (!raw_data)
		return (1);
	err = apply_str_precision(options, &raw_data);
	if (err)
	{
		free(raw_data);
		return (err);
	}
	err = apply_general_options(output_line_buffer, options, raw_data);
	free(raw_data);
	return (err);
}

int	apply_str_precision(t_options *options, unsigned char **raw_data)
{
	unsigned char	*new_data;
	int				new_data_len;

	if (!has_flag(options->flags, FLAG_PRECISION))
		return (0);
	if (options->precision > (int) ft_strlen((char *)*raw_data))
		new_data_len = ft_strlen((char *)*raw_data);
	else
		new_data_len = options->precision;
	new_data = malloc(sizeof(*new_data) * (new_data_len + 1));
	if (!new_data)
		return (1);
	ft_memcpy(new_data, *raw_data, new_data_len);
	new_data[new_data_len] = 0;
	free(*raw_data);
	*raw_data = new_data;
	return (0);
}
