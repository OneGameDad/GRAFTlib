#include "../../includes/minishell.h"

char	*arena_strdup(t_arena **arena, const char *src, bool is_enviro, int msg)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = alloc_data(arena, sizeof(char) * (ft_strlen(src) + 1), is_enviro, msg);
	if (dest == 0)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char *arena_strjoin(t_arena **arena, const char *s1, const char *s2, bool is_enviro)
{
	char	*str;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	str = alloc_data(arena, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1), false, STRJOIN_FAIL);
	newstr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (newstr);
}