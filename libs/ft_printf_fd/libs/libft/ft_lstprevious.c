/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprevious.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:49:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/06 12:51:54 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprevious(t_list *lst, t_list *node)
{
	t_list	*previous;
	t_list	*cur;

	previous = 0;
	cur = lst;
	while (cur->next && cur != node)
	{
		previous = cur;
		cur = cur->next;
	}
	if (cur == node)
		return (previous);
	return (0);
}
