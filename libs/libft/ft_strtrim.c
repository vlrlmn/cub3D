/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:04:22 by rtchaker          #+#    #+#             */
/*   Updated: 2023/11/23 14:18:54 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!set || s1_len == 0)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
		s1_len--;
	}
	while (ft_strchr(set, s1[i + s1_len - 1]))
	{
		s1_len--;
	}
	return (ft_substr(s1, i, s1_len));
}
