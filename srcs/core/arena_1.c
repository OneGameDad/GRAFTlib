#include "../../includes/graftlib.h"
#include <stdlib.h>
#include <stdint.h>

int	init_new_arena(t_arena *arena, size_t capacity)
{
	void	*data;

	arena = gr_calloc(sizeof(t_arena), 1);
	if (!arena)
		return (ARENA_MALLOC_FAIL);
	data = gr_calloc(sizeof(uint8_t), capacity);
	if (!data)
		return (DATA_MALLOC_FAIL);
	arena->capacity = capacity;
	arena->size = 0;
	arena->data = data;
	arena->next = NULL;
	return (SUCCESS);
}

void	*alloc_data(t_arena *arena, size_t size)
{
	void	*data;
	t_arena *current;
	int		i;

	current = arena;
	if ((current->size + size) > current->capacity && current->next == NULL)
	{
		init_new_arena(current->next, current->capacity);
		if (current->next == NULL ||  current->next->data == NULL)
			return (NULL);
		current = current->next;
	}
	data = &current->data[current->size];
	current->size += size;
	return (data);
}

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

void	print_arena_details(t_arena *arena)
{
	int		i;
	t_arena	*current;

	current = arena;
	i = 0;
	while (current)
	{
		ft_printf("Arena Node: %d\n", i + 1);
		ft_printf("Arena Capacity: %zu\n", arena->capacity);
		ft_printf("Arena Size: %zu\n", arena->size);
		ft_printf("Arena data pointer: %p\n", arena->data);
		++i;
		current = current->next;
	}
}
