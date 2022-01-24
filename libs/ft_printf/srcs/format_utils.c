/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:05:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/03 12:33:07 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_utils.h"

void	init_options(t_options *options)
{
	options->flags = 0;
	options->minimal_field_width = 0;
	options->precision = 0;
	options->conv = 0;
}

int	is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}
