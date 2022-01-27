/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:21:05 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/27 12:19:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/send_message.h"

static int	send_char(int pid, char c);
static void	init_signal_handling(void);
static void	handle_signal(int sig, siginfo_t *info, void *ucontext);
static int	wait_for_process(void);

int	g_wait_for_process = 0;

int	send_message(int pid, const char *message)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	init_signal_handling();
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
	int		j;
	char	bit;
	int		err;

	i = 0;
	err = 0;
	while (i < 8 && !err)
	{
		j = 0;
		err = !wait_for_process();
		if (err)
			return (0);
		bit = c & 1 << (7 - i);
		g_wait_for_process = pid;
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

static int	wait_for_process(void)
{
	int	j;

	j = 0;
	while (g_wait_for_process && j < 10000)
	{
		usleep(1);
		j++;
	}
	if (j == 10000)
		return (0);
	return (1);
}

static void	init_signal_handling(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sa.sa_sigaction = &handle_signal;
	sa.sa_mask = set;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
}

static void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	if (sig == SIGUSR1 && info->si_pid == g_wait_for_process)
		g_wait_for_process = 0;
}
