/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:25:14 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 15:59:58 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_general.h"

int	apply_general_options(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data)
{
	
}

int	apply_minimal_field_width(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data)
{
	size_t	len_raw_data;
	int		n_spaces;
	int		i;
	char	filler;
	int		err;

	len_raw_data = ft_strlen(raw_data);
	n_spaces = options->minimal_field_width - len_raw_data;
	n_spaces *= (n_spaces > 0);
	i = 0;
	filler = (options->flags & FLAG_0_PAD) * '0'
		+ !(options->flags & FLAG_0_PAD) * ' ';
	err = 0;
	while (!err && i++ < n_spaces)
		err = append(output_line_buffer, &filler);
	return (err);
}
