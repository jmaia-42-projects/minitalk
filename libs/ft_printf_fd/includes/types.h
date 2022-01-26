/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:28:47 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/02 19:37:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_options
{
	unsigned char	flags;
	int				minimal_field_width;
	int				precision;
	char			conv;
}	t_options;
#endif
