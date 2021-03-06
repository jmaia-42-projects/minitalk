/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:11:37 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/24 13:50:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_messages.h"
#include "print_pid.h"

int	main(void)
{
	int	err;

	print_pid(1);
	err = !handle_messages();
	return (err);
}
