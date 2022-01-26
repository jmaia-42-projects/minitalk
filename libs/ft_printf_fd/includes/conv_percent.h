/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:38:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_PERCENT_H
# define CONV_PERCENT_H

# include <stdlib.h>

# include "libdynamic_buffer.h"

# include "types.h"
# include "conv_general.h"

int	conv_percent(t_dynamic_buffer *output_line, t_options *options);
#endif
