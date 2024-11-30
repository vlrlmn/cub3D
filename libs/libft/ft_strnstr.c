/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:54:03 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:02:47 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	const char	*haystack_dp;

	needle_len = ft_strlen(needle);
	haystack_dp = haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack_dp != '\0' && (size_t)(haystack_dp - haystack) < len)
	{
		if ((haystack_dp - haystack) + needle_len <= len)
		{
			if (ft_strncmp(haystack_dp, needle, needle_len) == 0)
			{
				return ((char *)haystack_dp);
			}
		}
		haystack_dp++;
	}
	return (NULL);
}
