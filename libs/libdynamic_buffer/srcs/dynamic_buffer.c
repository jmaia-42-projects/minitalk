/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:23:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/16 18:31:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_buffer.h"

t_dynamic_buffer	get_buffer(size_t elem_size)
{
	t_dynamic_buffer	buffer;

	buffer.buffer = malloc(elem_size * EXPAND_LEN);
	buffer.i = 0;
	buffer.len = EXPAND_LEN;
	buffer.elem_size = elem_size;
	return (buffer);
}

int	free_buffer(t_dynamic_buffer **buffer, void (*del)(void *))
{
	unsigned long	i;

	if (!buffer || !*buffer)
		return (1);
	if (del)
	{
		i = 0;
		while (i < (*buffer)->i)
			del(get_elem_ptr(*buffer, i++));
	}
	free((*buffer)->buffer);
	free(*buffer);
	*buffer = 0;
	return (1);
}

int	append(t_dynamic_buffer *buffer, void *elem)
{
	int	err;

	if (buffer->i == buffer->len)
	{
		err = expand(buffer);
		if (err)
			return (err);
	}
	ft_memcpy(get_elem_ptr(buffer, buffer->i++), elem, buffer->elem_size);
	return (0);
}

static void	*get_elem_ptr(t_dynamic_buffer *buffer, unsigned long i)
{
	char	*buffer_bytes;
	void	*ptr;

	buffer_bytes = buffer->buffer;
	ptr = buffer_bytes + buffer->elem_size * i;
	return (ptr);
}

static int	expand(t_dynamic_buffer *buffer)
{
	void	*new_buffer;
	size_t	new_size;
	size_t	old_size;

	new_size = buffer->elem_size * (buffer->len + EXPAND_LEN);
	old_size = buffer->elem_size * buffer->len;
	new_buffer = malloc(buffer->elem_size * new_size);
	if (!new_buffer)
		return (1);
	ft_memcpy(new_buffer, buffer->buffer, old_size);
	free(buffer->buffer);
	buffer->buffer = new_buffer;
	buffer->len += EXPAND_LEN;
	return (0);
}
