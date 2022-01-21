/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:55:57 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/07 17:58:31 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_U_H
# define CONV_U_H

# include "libft.h"
# include "libdynamic_buffer.h"

# include "conv_general.h"
# include "types.h"
# include "annoying_0_flag.h"

int	conv_u(t_dynamic_buffer *output_line, t_options *options,
		unsigned int param);
#endif
