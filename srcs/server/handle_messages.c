/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/25 17:25:40 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_messages.h"

#include <stdio.h>
#include <unistd.h>

static void	init_signal_handling(void);
static void	handle_signal(int sig, siginfo_t *info, void *ucontext);
static void	handle_loop(t_dynamic_buffer *buffer);

int	g_sig = 0;

int	handle_messages(void)
{
	t_dynamic_buffer	*buffer;
	int					status;

	init_signal_handling();
	buffer = get_buffer();
	if (!buffer)
		return (0);
	status = handle_loop(buffer);
	free_buffer(&buffer, &free);
	return (status);
}

static void	handle_loop(t_dynamic_buffer *buffer)
{
	char	*message;

	while (1)
	{
		pause();
		if (g_sig)
		{
			g_sig = 0;
		}
	}
}

static void	init_signal_handling(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_sigaction = &handle_signal;
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	g_sig = sig;
}
