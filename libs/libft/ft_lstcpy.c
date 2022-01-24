/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:09:07 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/13 12:43:57 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst)
{
	t_list	*cur;
	t_list	*cpy;
	t_list	*cur_cpy;

	cur = lst;
	if (!lst)
		return (0);
	cpy = ft_lstnew(cur->content);
	if (!cpy)
		return (0);
	cur_cpy = cpy;
	while (cur->next)
	{
		cur = cur->next;
		cur_cpy->next = ft_lstnew(cur->content);
		cur_cpy = cur_cpy->next;
		if (!cur_cpy)
		{
			ft_lstclear(&cpy, 0);
			return (0);
		}
	}
	return (cpy);
}
