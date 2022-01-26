/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:16:37 by jmaia             #+#    #+#             */
/*   Updated: 2021/11/29 13:13:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char *str, char c)
{
	int	is_in_word;
	int	n;

	n = 0;
	is_in_word = 0;
	--str;
	while (*++str)
	{
		if (*str == c)
			is_in_word = 0;
		else if (!is_in_word)
		{
			++n;
			is_in_word = 1;
		}
	}
	return (n);
}

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
	i--;
	dest[i] = 0;
	return (dest);
}

static int	insert_word(char **splitted, int start, int end, char *str)
{
	char	*word;

	word = malloc(sizeof(*word) * (end - start + 2));
	if (!word)
		return (0);
	ft_strncpy(word, (char *)(str + start), end - start + 2);
	word[end - start + 1] = 0;
	*splitted = word;
	return (1);
}

static void	free_everything(char **splitted, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(splitted[i]);
	free(splitted);
}

char	**ft_split(char *str, char c)
{
	int		start;
	int		i;
	int		i_splitted;
	char	**splitted;
	int		has_error;

	splitted = malloc(sizeof(*splitted) * (count_words(str, c) + 1));
	if (splitted == 0)
		return (0);
	splitted = (splitted++, start = -1, i = -1, i_splitted = 0, splitted--,
			splitted);
	while (str[++i])
	{
		if (str[i] != c && start == -1)
			start = i;
		if ((str[i + 1] == c || !str[i + 1]) && start != -1)
		{
			has_error = !insert_word(splitted + i_splitted, start, i, str);
			if (has_error)
				free_everything(splitted, i_splitted + 1);
			start = (start++, ++i_splitted, start = -1, start);
		}
	}
	splitted[i_splitted] = 0;
	return (splitted);
}
