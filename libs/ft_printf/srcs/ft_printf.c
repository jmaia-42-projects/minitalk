/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:31:41 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/08 15:19:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"

void	free_things(void *p1, void *p2)
{
	free(p1);
	free(p2);
}

int	ft_printf(const char *format, ...)
{
	va_list				ap;
	unsigned int		i;
	t_dynamic_buffer	output_line_buffer;
	char				*output_line;
	int					err;

	output_line_buffer = get_buffer(sizeof(char));
	if (!output_line_buffer.buffer)
		return (1);
	va_start(ap, format);
	i = 0;
	err = 0;
	while (format[i] && !err)
		err = treat_next_char(&output_line_buffer, format, &i, ap);
	va_end(ap);
	if (err)
	{
		free(output_line_buffer.buffer);
		return (-1);
	}
	output_line = as_str(&output_line_buffer);
	ft_put_bytes_fd(output_line, output_line_buffer.i, 1);
	free_things(output_line_buffer.buffer, output_line);
	return (output_line_buffer.i);
}
