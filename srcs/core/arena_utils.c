/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpellech <gpellech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:21:37 by gpellech          #+#    #+#             */
/*   Updated: 2025/04/13 13:26:28 by gpellech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/graftlib.h"

void	reset_arena(t_arena *arena)
{
	t_arena *current;

	current = arena;
	while (current)
	{
		current->size = 0;
		gr_bzero(current->data, current->capacity);
		current = current->next;
	}
}

void	clean_arena(t_arena *arena)
{
	t_arena	*current;
	t_arena	*temp;

	current = arena;
	while (current)
	{
		current->capacity = 0;
		current->size = 0;
		free(current->data);
		temp = current->next;
		free(current);
		current = temp;
	}
}
