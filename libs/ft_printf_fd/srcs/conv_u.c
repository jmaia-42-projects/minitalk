/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:06:33 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_u.h"

int	conv_u(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	const unsigned char	*raw_data;
	int					err;

	raw_data = ft_itoa(param);
	if (!raw_data)
		return (1);
	err = apply_number_precision(options, (unsigned char **)&raw_data);
	if (err)
	{
		free((void *)raw_data);
		return (1);
	}
	err = annoying_0_flag(options, ((unsigned char **)&raw_data));
	if (err)
	{
		free((void *)raw_data);
		return (1);
	}
	err = apply_general_options(output_line_buffer, options, raw_data);
	free((void *)raw_data);
	return (err);
}
