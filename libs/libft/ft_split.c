/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:00:59 by rtchaker          #+#    #+#             */
/*   Updated: 2023/11/30 10:02:03 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			wordcount++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wordcount);
}

static void	free_word_array(char **word_array, size_t count)
{
	while (count > 0)
		free(word_array[--count]);
	free(word_array);
}

static char	**split_words(const char *s, char c, char **word_array, size_t i)
{
	size_t	start;
	size_t	count;

	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			word_array[count] = ft_substr(s, start, i - start);
			if (!word_array[count])
			{
				free_word_array(word_array, count);
				return (NULL);
			}
			count++;
		}
		else
			i++;
	}
	word_array[count] = NULL;
	return (word_array);
}

char	**ft_split(char const *s, char c)
{
	char		**word_array;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_array = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (word_array == NULL)
		return (NULL);
	if (!word_array)
		return (NULL);
	return (split_words(s, c, word_array, i));
}
