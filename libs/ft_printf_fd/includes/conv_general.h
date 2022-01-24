/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_general.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:19:23 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 10:34:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_GENERAL_H
# define CONV_GENERAL_H

# include <stdlib.h>

# include "libdynamic_buffer.h"
# include "libft.h"

# include "types.h"
# include "flags.h"
# include "annoying_prec0val0.h"
# include "is_sign.h"

int	apply_general_options(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data);

int	apply_general_options_with_len(t_dynamic_buffer *output_line_buffer,
		t_options *options, const unsigned char *raw_data, unsigned int len);

int	apply_minimal_field_width(t_dynamic_buffer *output_line_buffer,
		t_options *options, unsigned int len);

int	apply_minimal_field_width_number(t_dynamic_buffer *output_line_buffer,
		t_options *options, unsigned char *raw_data);

int	apply_number_precision(t_options *options, unsigned char **raw_data);

int	append_str(t_dynamic_buffer *output_line_buffer,
		const unsigned char *raw_data, unsigned int len);
#endif
