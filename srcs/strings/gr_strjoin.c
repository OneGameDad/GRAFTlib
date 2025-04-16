
#include "../../includes/graftlib.h"
#include <stddef.h>

char	*gr_strjoin(t_arena *arena, const char *s1, const char *s2)
{
	char	*str;
	char	*newstr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = gr_strlen(s1);
	s2_len = gr_strlen(s2);
	str = alloc_data(arena, sizeof(char) * (s1_len + s2_len + 1));
	newstr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (newstr);
}
