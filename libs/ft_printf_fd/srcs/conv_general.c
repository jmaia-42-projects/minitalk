/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:25:14 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 10:34:50 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_general.h"

int	apply_general_options(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data)
{
	return (apply_general_options_with_len(output_line_buffer, options,
			raw_data, ft_strlen((const char *)raw_data)));
}

int	apply_general_options_with_len(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data, unsigned int len)
{
	int	err;

	err = 0;
	if (has_flag(options->flags, FLAG_LEFT_ADJUSTED))
		err = append_str(output_line_buffer, raw_data, len);
	err += apply_minimal_field_width(output_line_buffer, options, len);
	if (!has_flag(options->flags, FLAG_LEFT_ADJUSTED))
		err += append_str(output_line_buffer, raw_data, len);
	return (err);
}

int	append_str(t_dynamic_buffer *output_line_buffer, const unsigned char *str,
		unsigned int len)
{
	unsigned int	i;
	int				err;

	i = 0;
	err = 0;
	while (!err && i < len)
		err = append(output_line_buffer, (void *)&str[i++]);
	return (err);
}

int	apply_minimal_field_width(t_dynamic_buffer *output_line_buffer,
		t_options *options, unsigned int len_raw_data)
{
	int		n_spaces;
	int		i;
	char	filler;
	int		err;

	filler = (!!has_flag(options->flags, FLAG_0_PAD)) * '0'
		+ !(has_flag(options->flags, FLAG_0_PAD)) * ' ';
	if (filler != ' ')
		return (0);
	n_spaces = options->minimal_field_width - len_raw_data;
	n_spaces *= (n_spaces > 0);
	i = 0;
	err = 0;
	while (!err && i++ < n_spaces)
		err = append(output_line_buffer, &filler);
	return (err);
}

int	apply_number_precision(t_options *options, unsigned char **raw_data)
{
	int				n_digits;
	int				n_zeros;
	int				i;
	unsigned char	*new_data;

	annoying_prec0val0(options, raw_data);
	n_digits = ft_strlen((char *) *raw_data) - is_sign((*raw_data)[0]);
	n_zeros = options->precision - n_digits;
	n_zeros *= n_zeros > 0;
	if (!n_zeros)
		return (0);
	new_data = malloc(sizeof(*new_data) * (ft_strlen((char *) *raw_data)
				+ n_zeros + 1));
	if (!new_data)
		return (1);
	ft_memcpy(new_data + n_zeros, *raw_data,
		ft_strlen((char *) *raw_data) + 1);
	i = 0;
	while (i < n_zeros)
		new_data[is_sign((*raw_data)[0]) + i++] = '0';
	if (is_sign((*raw_data)[0]))
		new_data[0] = (*raw_data)[0];
	free(*raw_data);
	*raw_data = new_data;
	return (0);
}
