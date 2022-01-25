/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/25 16:13:54 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_messages.h"

#include <stdio.h>
#include <unistd.h>

static void	handle_signal(int sig, siginfo_t *info, void *ucontext);

int	handle_messages(void)
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
	while (1)
		pause();
	return (1);
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void) info;
	(void) ucontext;
	printf("Signal : %d\n", sig);
}
