/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:25:14 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 16:17:25 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_general.h"

//int	apply_general_options(t_dynamic_buffer *output_line_buffer,
//		t_options *options, const unsigned char *raw_data)
//{
//	
//}

int	apply_minimal_field_width(t_dynamic_buffer *output_line_buffer,
		t_options *options, unsigned char *raw_data)
{
	size_t	len_raw_data;
	int		n_spaces;
	int		i;
	char	filler;
	int		err;

	len_raw_data = ft_strlen((char *) raw_data);
	n_spaces = options->minimal_field_width - len_raw_data;
	n_spaces *= (n_spaces > 0);
	i = 0;
	filler = (!!has_flag(options->flags, FLAG_0_PAD)) * '0'
		+ !(has_flag(options->flags, FLAG_0_PAD)) * ' ';
	err = 0;
	while (!err && i++ < n_spaces)
		err = append(output_line_buffer, &filler);
	return (err);
}

int	apply_minimal_field_width_number(t_dynamic_buffer *output_line_buffer,
		t_options *options, unsigned char *raw_data)
{
	if (has_flag(options->flags, FLAG_PRECISION)
		&& has_flag(options->flags, FLAG_0_PAD))
		options->flags &= ~FLAG_0_PAD;
	return (apply_minimal_field_width(output_line_buffer, options, raw_data));
}

int	apply_number_precision(t_options *options, unsigned char **raw_data)
{
	int				n_digits;
	int				n_zeros;
	int				i;
	unsigned char	*new_data;

	n_digits = ft_strlen((char *) raw_data) - ((*raw_data)[0] == '-');
	n_zeros = options->precision - n_digits;
	n_zeros *= n_zeros > 0;
	if (!n_zeros)
		return (0);
	new_data = malloc(sizeof(*new_data) * (ft_strlen((char *) *raw_data)
				+ n_zeros + 1));
	if (!new_data)
		return (1);
	ft_memcpy(new_data + (*(raw_data)[0] == '-') + n_zeros, *raw_data,
		ft_strlen((char *) *raw_data) + 1);
	i = 0;
	while (i < n_zeros)
		new_data[i++] = '0';
	if (*(raw_data)[0] == '-')
		new_data[i] = '-';
	free(*raw_data);
	*raw_data = new_data;
	return (0);
}
