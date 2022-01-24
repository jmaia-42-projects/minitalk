/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:32:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/21 18:02:11 by jmaia            ###   ########.fr       */
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
	ft_printf(format, getpid());
}
