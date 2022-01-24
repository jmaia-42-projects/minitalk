/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:04:31 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 21:14:00 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_field.h"

t_options	parse_field(const char *field, int *i)
{
	t_options	options;

	init_options(&options);
	parse_flags(&options, field, i);
	parse_minimal_field_width(&options, field, i);
	parse_precision(&options, field, i);
	if (is_conv(field[*i]))
		options.conv = field[(*i)++];
	else
		options.flags = FLAG_ERROR;
	if (has_flag(options.flags, FLAG_PRECISION)
		&& has_flag(options.flags, FLAG_0_PAD))
		options.flags &= ~FLAG_0_PAD;
	return (options);
}

void	parse_flags(t_options *options, const char *field, int *i)
{
	while (field[*i] && is_flag(field[*i])
		&& get_flag_code(field[*i]) != FLAG_PRECISION)
	{
		options->flags |= get_flag_code(field[*i]);
		(*i)++;
	}
}

void	parse_minimal_field_width(t_options *options, const char *field, int *i)
{
	if (ft_isdigit(field[*i]))
		options->minimal_field_width = ft_atoi(&field[*i]);
	skip_atoied_number(field, i);
}

void	parse_precision(t_options *options, const char *field, int *i)
{
	if (field[*i] == '.')
	{
		options->flags |= FLAG_PRECISION;
		(*i)++;
		options->precision = ft_atoi(&field[*i]);
		skip_atoied_number(field, i);
	}
}

void	skip_atoied_number(const char *field, int *i)
{
	while (ft_isspace(field[*i]))
		(*i)++;
	if (field[*i] == '+' || field[*i] == '-')
		(*i)++;
	while (ft_isdigit(field[*i]))
		(*i)++;
}
