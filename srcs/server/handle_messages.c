/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:06:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/27 13:12:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_messages.h"

#include <stdio.h>
#include <unistd.h>

static void	init_signal_handling(void);
static void	handle_signal(int sig, siginfo_t *info, void *ucontext);
static int	handle_loop(t_dynamic_buffer *buffer);
static int	append_bit(siginfo_t sig, char *c, int *i_bit,
				t_dynamic_buffer *buffer);

siginfo_t	g_last_sig = {0};

int	handle_messages(void)
{
	t_dynamic_buffer	dirty_tmp;
	t_dynamic_buffer	*buffer;
	int					status;

	init_signal_handling();
	dirty_tmp = get_buffer(sizeof(char));
	if (!dirty_tmp.buffer)
		return (0);
	buffer = &dirty_tmp;
	status = handle_loop(buffer);
	free_buffer(&buffer, 0);
	return (status);
}

static int	handle_loop(t_dynamic_buffer *buffer)
{
	char	c;
	int		i_bit;
	int		tmp_pid;
	int		err;

	i_bit = 0;
	tmp_pid = 0;
	while (1)
	{
		if (!g_last_sig.si_pid)
			continue ;
		if (tmp_pid != g_last_sig.si_pid)
		{
			i_bit = 0;
			c = 0;
			buffer->i = 0;
		}
		err = !append_bit(g_last_sig, &c, &i_bit, buffer);
		if (err)
			return (0);
		tmp_pid = g_last_sig.si_pid;
		g_last_sig = (siginfo_t){0};
		kill(tmp_pid, SIGUSR1);
	}
}

static int	append_bit(siginfo_t sig, char *c, int *i_bit,
				t_dynamic_buffer *buffer)
{
	char	*message;

	if (*i_bit == 0)
		*c = 0;
	if (sig.si_signo == SIGUSR1)
		*c |= 1 << (7 - *i_bit);
	++*i_bit;
	if (*i_bit == 8)
	{
		*i_bit = 0;
		append(buffer, c);
	}
	if (*i_bit == 0 && *c == 0)
	{
		message = as_str(buffer);
		buffer->i = 0;
		buffer->len = 0;
		ft_putendl_fd(message, 1);
		if (!message)
			return (0);
		free(message);
	}
	return (1);
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
	(void) sig;
	(void) ucontext;
	g_last_sig = *info;
}
