/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/16 18:40:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdynamic_buffer.h"
#include <stdlib.h>
#include "libft.h"

int	adjust(t_dynamic_buffer *buffer)
{
	void	*new_buffer;
	size_t	new_size;
	size_t	old_size;

	if (buffer->i == buffer->len)
		return (1);
	new_size = buffer->i;
	old_size = buffer->len;
	new_buffer = malloc(buffer->elem_size * new_size);
	if (!new_buffer)
		return (0);
	ft_memcpy(new_buffer, buffer->buffer, old_size);
	free(buffer->buffer);
	buffer->buffer = new_buffer;
	buffer->len = new_size;
	return (1);
}
