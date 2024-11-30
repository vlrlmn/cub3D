/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:42:44 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:02:52 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			ch;
	char			*newch;

	ch = (char)c;
	newch = 0;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			newch = (char *)s;
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (newch);
}
