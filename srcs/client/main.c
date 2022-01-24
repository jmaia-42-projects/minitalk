/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:06:46 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 14:51:19 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client/send_message.h"
#include "ft_printf.h"

static int	parse_args_if_valid(int ac, char **av, int *pid, char **message);

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		err;

	err = !parse_args_if_valid(ac, av, &pid, &message);
	if (err)
	{
		ft_printf_fd(2, "Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	err = !send_message(pid, message);
	if (err)
	{
		ft_printf_fd(2, "An error occured while sending message\n");
		return (2);
	}
	return (0);
}

static int	parse_args_if_valid(int ac, char **av, int *pid, char **message)
{
	(void) ac;
	(void) av;
	(void) pid;
	(void) message;
	return (0);
}
