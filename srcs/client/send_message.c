/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:21:05 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 17:55:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/send_message.h"

static int	send_char(int pid, char c);

int	send_message(int pid, const char *message)
{
	int	i;
	int	err;

	i = 0;
	while (message[i] && !err)
		err = !send_char(pid, message[i++]);
	if (err)
		return (0);
	err = !send_char(pid, 0);
	if (err)
		return (0);
	return (1);
}

static int	send_char(int pid, char c)
{
	int		i;
	char	bit;
	int		err;

	i = 0;
	while (i < 8)
	{
		bit = c & 1 << (7 - i);
		if (bit)
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		i++;
	}
	if (err)
		return (0);
	return (1);
}
