/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:59:54 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/06 12:28:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int	is_flag(char c)
{
	return (get_flag_code(c) != FLAG_ERROR);
}

int	get_flag_code(char c)
{
	if (c == '0')
		return (FLAG_0_PAD);
	if (c == '-')
		return (FLAG_LEFT_ADJUSTED);
	if (c == '.')
		return (FLAG_PRECISION);
	if (c == '#')
		return (FLAG_ALTERNATE_FORM);
	if (c == ' ')
		return (FLAG_BLANK);
	if (c == '+')
		return (FLAG_ALWAYS_SIGN);
	return (FLAG_ERROR);
}

int	has_flag(int flags, int flag)
{
	return (flags & flag);
}
