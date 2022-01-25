/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_message.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:26:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/25 16:18:48 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_MESSAGE_H
# define SEND_MESSAGE_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

int	send_message(int pid, const char *message);

#endif
