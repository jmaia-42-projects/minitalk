/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:21:52 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 17:44:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FIELD_H
# define PARSE_FIELD_H

# include "types.h"
# include "libft.h"
# include "format_utils.h"
# include "flags.h"

t_options	parse_field(const char *field, int *i);
void		parse_flags(t_options *options, const char *field, int *i);
void		parse_minimal_field_width(t_options *options, const char *field,
				int *i);
void		parse_precision(t_options *options, const char *fied, int *i);
void		skip_atoied_number(const char *field, int *i);
#endif
