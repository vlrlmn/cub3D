/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raffi <raffi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:15:24 by rtchaker          #+#    #+#             */
/*   Updated: 2023/12/27 11:21:53 by raffi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	invalid_arg(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len < 2)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (str[j] == str[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	base_to_dig(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	skip_spaces(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

unsigned int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	long	num;
	int		base_str_len;
	int		bit;

	i = 0;
	num = 0;
	base_str_len = ft_strlen(base);
	if (base_str_len < 2 || invalid_arg(base, base_str_len))
		return (0);
	sign = skip_spaces(str, &i);
	bit = base_to_dig(str[i], base);
	while (bit != -1)
	{
		num = num * base_str_len + bit;
		i++;
		bit = base_to_dig(str[i], base);
	}
	return (num * sign);
}
