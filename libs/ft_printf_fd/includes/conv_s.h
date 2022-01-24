/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 15:29:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_S_H
# define CONV_S_H

# include "libft.h"
# include "libdynamic_buffer.h"

# include "conv_general.h"
# include "types.h"
# include "flags.h"

int	conv_s(t_dynamic_buffer *output_line_buffer, t_options *options,
		const char *param);
int	apply_str_precision(t_options *options, unsigned char **raw_data);
#endif
