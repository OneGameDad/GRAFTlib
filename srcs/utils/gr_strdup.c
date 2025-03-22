/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:40:49 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/22 21:41:29 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

char	*gr_strdup(t_arena *arena, const char *str)
{
	char	*dup;
	size_t	len;
	size_t	bytes;

	if (str == NULL)
		return (NULL);
	len = gr_strlen(str);
	bytes = (len + 1) * sizeof(char);
	dup = alloc_data(arena, bytes);
	if (!dup)
		return (NULL);
	gr_memcpy(dup, str, bytes);
	return (dup);
}
