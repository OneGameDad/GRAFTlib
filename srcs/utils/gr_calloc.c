/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:39:57 by gpellech          #+#    #+#             */
/*   Updated: 2025/03/11 09:12:40 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"
#include <stdlib.h>

void	*gr_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count <= 0 || size <= 0)
		return (NULL);
	else if (count != 0 && (count * size) / count != size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	gr_bzero(ptr, total);
	return (ptr);
}
