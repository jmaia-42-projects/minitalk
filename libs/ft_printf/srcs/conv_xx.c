/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:59:30 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:29:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conv_xx.h"

int	conv_xx(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned int param)
{
	unsigned char	*nbr;
	int				err;

	nbr = ft_itoa_base(param, "0123456789ABCDEF");
	err = conv_x_common(output_line_buffer, options, &nbr);
	free(nbr);
	return (err);
}
