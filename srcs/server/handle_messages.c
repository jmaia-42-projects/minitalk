/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 22:55:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_messages.h"

#include <stdio.h>
#include <unistd.h>

static void	handle_signal(int a);

int	handle_messages(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_handler = &handle_signal;
	sa.sa_mask = set;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (1);
}

static void	handle_signal(int a)
{
	printf("Signal : %d\n", a);
}
