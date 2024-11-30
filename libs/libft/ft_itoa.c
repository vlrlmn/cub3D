/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtchaker <rtchaker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:51:07 by raffi             #+#    #+#             */
/*   Updated: 2023/11/30 10:00:40 by rtchaker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_putnbr(long n, char **s)
{
	if (n < 0)
	{
		*(*s)++ = '-';
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, s);
	}
	*(*s)++ = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*s;
	char	*start;
	int		len;
	long	ln;

	ln = n;
	len = ft_numlen(ln);
	s = malloc(sizeof(char) * (len + 1));
	start = s;
	if (s == NULL)
		return (NULL);
	ft_putnbr(ln, &s);
	*s = '\0';
	return (start);
}
