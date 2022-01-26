/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 14:06:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_d.h"

int	annoying_0_flag(t_options *options, unsigned char **raw_data);

int	conv_d(t_dynamic_buffer *output_line_buffer, t_options *options, int param)
{
	unsigned char	*raw_data;
	int				err;

	raw_data = (unsigned char *) ft_itoa(param);
	if (!raw_data)
		return (1);
	err = conv_d_returns(output_line_buffer, options, param, &raw_data);
	free(raw_data);
	return (err);
}

int	conv_d_returns(t_dynamic_buffer *output_line_buffer,
		t_options *options, int param, unsigned char **raw_data)
{
	int		err;
	char	left_char;

	left_char = !!has_flag(options->flags, FLAG_ALWAYS_SIGN) * '+';
	left_char += !left_char * !!has_flag(options->flags, FLAG_BLANK) * ' ';
	if (left_char && param >= 0)
	{
		if (append_left_char(left_char, raw_data))
		{
			free(*raw_data);
			return (1);
		}
	}
	if (apply_number_precision(options, raw_data))
	{
		free(*raw_data);
		return (1);
	}
	err = annoying_0_flag(options, raw_data);
	err += apply_general_options(output_line_buffer, options, *raw_data);
	return (err);
}

int	append_left_char(char left_char, unsigned char **str)
{
	unsigned char	*final;

	final = malloc(sizeof(*final) * (ft_strlen((const char *)*str) + 2));
	if (!final)
		return (1);
	final[0] = left_char;
	ft_memcpy(final + 1, *str, ft_strlen((const char *)*str) + 1);
	free((void *)(*str));
	*str = final;
	return (0);
}
