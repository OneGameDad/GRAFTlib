#ifndef GRAFTLIB_H
# define GRAFTLIB_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

/********************************************************************* MACROS */
#ifndef ARENA_BUFFER
# define ARENA_BUFFER	10485760
/** Currently set to 10mb */
#endif

# define SUCCESS		0
# define ARENA_MALLOC_FAIL	-1
# define DATA_MALLOC_FAIL	-2

/******************************************************************** STRUCTS */
typedef struct s_arena
{
	size_t		capacity;
	size_t		size;
	uint8_t		*data;
	struct s_arena	*next;
}	t_arena;

/************************************************************ UTILS FUNCTIONS */
/** These functions are utility functions used across multiple functions */


void	*gr_calloc(size_t count, size_t size);

void	gr_bzero(void *ptr, size_t n);

size_t	gr_strlen(const char *str);

int		gr_printf(const char *format, ...);

void	*gr_memcpy(void *dest, const void *src, size_t n);

char	*gr_strdup(t_arena *arena, const char *str);

/************************************************************* CORE FUNCTIONS */

int	init_new_arena(t_arena *arena, size_t capacity);

void	*alloc_data(t_arena *arena, size_t size);

void	reset_arena(t_arena *arena);

void	clean_arena(t_arena *arena);

void	print_arena_details(t_arena *arena);

#endif
