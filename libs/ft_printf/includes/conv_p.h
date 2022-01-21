/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 17:04:19 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_P_H
# define CONV_P_H

# include <stdlib.h>

# include "libdynamic_buffer.h"
# include "libft.h"

# include "conv_general.h"
# include "types.h"

int	conv_p(t_dynamic_buffer *output_line, t_options *options, void *param);
#endif
