/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:37:29 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 11:34:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*cur;
	t_list	*new;
	t_list	*f_new;

	if (lst == 0)
		return (0);
	cur = lst;
	mapped = 0;
	while (cur)
	{
		f_new = f(cur->content);
		new = ft_lstnew(f_new);
		ft_lstadd_back(&mapped, new);
		cur = cur->next;
	}
	del = 0;
	return (mapped);
}
