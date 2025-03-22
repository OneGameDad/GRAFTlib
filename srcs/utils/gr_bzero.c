/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:30:13 by gpellech          #+#    #+#             */
/*   Updated: 2024/11/01 14:53:59 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

void	gr_bzero(void *ptr, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (n-- > 0)
	{
		*(str++) = 0;
	}
}
