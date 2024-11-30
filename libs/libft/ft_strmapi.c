/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <raffi@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:22:57 by raffi             #+#    #+#             */
/*   Updated: 2023/11/23 14:12:28 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new_s;
	char				*start;
	unsigned int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_s = malloc(sizeof(char) * ft_strlen(s) + 1);
	start = new_s;
	if (!new_s)
		return (NULL);
	while (*s)
	{
		*new_s = f(i, *s);
		new_s++;
		s++;
		i++;
	}
	*new_s = '\0';
	return (start);
}
