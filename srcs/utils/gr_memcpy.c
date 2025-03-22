/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:53:31 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/22 21:56:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

void	*gr_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_str;
	const char	*src_str;
	size_t		i;

	if (n == 0 || src == dest)
		return (dest);
	dest_str = (char *)dest;
	src_str = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}
