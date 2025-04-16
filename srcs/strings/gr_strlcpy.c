
#include "../../includes/graftlib.h"

size_t	gr_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = gr_strlen(src);
	if ((length + 1) < size)
		gr_memcpy(dest, src, (length + 1));
	else if (size != 0)
	{
		gr_memcpy(dest, src, (size - 1));
		dest[size - 1] = 0;
	}
	return (length);
}
