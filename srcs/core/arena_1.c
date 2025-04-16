#include "../../includes/graftlib.h"
#include <stddef.h>

static size_t	round_to_eight(size_t num)
{
	size_t	result;

	if ((num & 7) == 0)
		return (num);
	result = (num + 7) & ~7;
	return (result);
}

int	init_new_arena(t_arena *arena, size_t capacity)
{
	void	*data;
	size_t	size;
	size_t	data_cap;

	size = round_to_eight(sizeof(t_arena));
	arena = gr_calloc(size, 1);
	if (!arena)
		return (ARENA_MALLOC_FAIL);
	data_cap = round_to_eight(capacity);
	data = gr_calloc(sizeof(uint8_t), data_cap);
	if (!data)
		return (DATA_MALLOC_FAIL);
	arena->capacity = data_cap;
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

	if (size > current->capacity)
		return (NULL);
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



