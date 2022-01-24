/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:51:12 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/25 10:08:11 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*last_found;
	int		i;

	last_found = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			last_found = (char *)s + i;
		i++;
	}
	if (c == 0)
		last_found = (char *)s + i;
	return (last_found);
}
