/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:32:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/26 16:48:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_pid.h"

void	print_pid(int newline)
{
	const char	*format;

	if (newline)
		format = "PID: %d\n";
	else
		format = "PID: %d";
	ft_printf_fd(1, format, getpid());
}
