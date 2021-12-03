/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:04:31 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 10:22:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_field.c"

t_options	parse(const char *field)
{
	t_options	options;
	int			i;

	init_options(&options);
	i = 0;
	parse_flags(&options, field, &i);
	parse_minimal_field_width(&options, field, &i);
	parse_precision(&options, field, &i);
	if (is_conv(field[i]))
		options.conv = field[i];
	else
		options.flags = FLAG_ERROR;
	return (options);
}

void	parse_flags(t_options *options, const char *field, int *i)
{
	while (field[*i] && is_flag(field[*i]))
	{
		options->flags |= get_flag_code(field[*i]);
		*i++;
	}
}

void	parse_minimal_field_width(t_options *options, const char *field, int *i)
{
	if (ft_isdigit(field[*i]))
		options->minimal_field_width = ft_atoi(field[*i]);
	skip_atoied_number(field, i);
}

void	parse_precision(t_options *options, const char *field, int *i)
{
	if (field[*i] == '.')
	{
		options->flags |= FLAG_PRECISION;
		*i++;
		options->precision = ft_atoi(field[*i]);
		skip_atoied_number(field, i);
	}
}

void	skip_atoied_number(const char *field, int *i)
{
	while (ft_isspace(field[*i]))
		*i++;
	if (field[*i] == '+' || field[*i] == '-')
		*i++;
	while (ft_isdigit(field[*i]))
		*i++;
}
