
#include "../../includes/graftlib.h"
void	*gr_realloc(t_arena *arena, void *ptr, size_t o_size, size_t n_size)
{
	void	*new_ptr;
	size_t	copy;

	new_ptr = alloc_data(arena, sizeof(char) * n_size);
	if (o_size < n_size)
		copy = o_size;
	else
		copy = n_size;
	if (ptr)
		gr_memcpy(new_ptr, ptr, copy);
	return (new_ptr);
}
