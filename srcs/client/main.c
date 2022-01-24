/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:06:46 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 15:01:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#include "client/send_message.h"

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
		ft_printf_fd(2, "An error occured while parsing message\n");
		return (2);
	}
	return (0);
}

static int	parse_args_if_valid(int ac, char **av, int *pid, char **message)
{
	if (ac < 3)
		return (0);
	if (!ft_isint(av[1]))
		return (0);
	*pid = ft_atoi(av[1]);
	if (*pid < 0)
		return (0);
	*message = av[2];
	return (1);
}
