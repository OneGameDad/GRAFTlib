/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:43:04 by gpellech          #+#    #+#             */
/*   Updated: 2024/10/31 14:43:46 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

size_t	gr_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}
