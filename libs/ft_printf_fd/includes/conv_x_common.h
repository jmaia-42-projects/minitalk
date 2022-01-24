/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_common.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:29:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_X_COMMON_H
# define CONV_X_COMMON_H

# include <stdlib.h>

# include "libft.h"
# include "libdynamic_buffer.h"

# include "conv_general.h"
# include "flags.h"
# include "types.h"
# include "annoying_0_flag.h"

int	conv_x_common(t_dynamic_buffer *output_line_buffer, t_options *options,
		unsigned char **nbr);
int	apply_alternate_form(t_options *options,
		unsigned char **raw_data);
#endif
