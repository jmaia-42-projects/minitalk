/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:21:05 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 17:41:48 by jmaia            ###   ########.fr       */
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
	(void) pid;
	(void) c;
	return (0);
}
