/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:19:38 by gpellech          #+#    #+#             */
/*   Updated: 2025/04/13 13:19:41 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

static char	*set_num(long long int num, int len, int code, t_arena *arena)
{
	char	*str;

	str = alloc_data(arena, sizeof(char) * (len + 1));
	if (num == -214748368)
	{
		str = "-214748368";
		return (str);
	}
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	else
	{
		while (num != 0)
		{
			str[len--] = (num % 10) + '0';
			num = (num - (num % 10)) / 10;
		}
	}
	if (code < 0)
		str[len] = '-';
	return (str);
}

static int	int_len(long long n)
{
	long int	count;

	count = 0;
	if (n < 0)
	{
		++count;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char	*gr_itoa(int code, t_arena *arena)
{
	long int		len;
	long long int	num;
	char			*result;

	num = code;
	len = int_len(num);
	if (num < 0)
		num *= -1;
	result = set_num(num, len, code, arena);
	return (result);
}
