/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:28:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_x.h"

int	conv_x(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	unsigned char	*nbr;
	int				err;

	nbr = ft_itoa_base(param, "0123456789abcdef");
	err = conv_x_common(output_line_buffer, options, &nbr);
	free(nbr);
	return (err);
}
