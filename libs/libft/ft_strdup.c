/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raffi <raffi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:15:10 by rtchaker          #+#    #+#             */
/*   Updated: 2023/11/14 19:28:39 by raffi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*p;
	size_t			str_len;

	str_len = ft_strlen(s1) + 1;
	p = malloc(sizeof(char) * str_len);
	if (p != NULL)
	{
		return (ft_memcpy(p, s1, str_len));
	}
	return (NULL);
}
