/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:29:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_d.h"

int	conv_d(t_dynamic_buffer *output_line_buffer, t_options *options, int param)
{
	unsigned char	*raw_nbr;
	unsigned char	*raw_data;
	char			left_char;

	raw_nbr = (unsigned char *) ft_itoa(param);
	if (!raw_nbr)
		return (1);
	left_char = has_flag(options->flags, FLAG_ALWAYS_SIGN) * '+';
	left_char += !left_char * has_flag(options->flags, FLAG_BLANK);
	if (left_char)
	{
		raw_data = (append_left_char(left_char, (const char *) (raw_nbr)));
		free(raw_nbr);
		if (!raw_data)
			return (1);
	}
	else
		raw_data = raw_nbr;
	return (apply_general_options(output_line_buffer, options, raw_data));
}

static unsigned char	*append_left_char(char left_char, const char *str)
{
	unsigned char	*final;

	final = malloc(sizeof(*final) * (ft_strlen(str) + 2));
	if (!final)
		return (0);
	final[0] = left_char;
	ft_memcpy(final + 1, str, ft_strlen(str) + 1);
	return (final);
}
