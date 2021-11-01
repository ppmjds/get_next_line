

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (l + 1));
	if (str == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strndup(const char *s, size_t	len)
{
	char	*d;

//	if (len < 0)
//		return (0);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (!d)
		return (0);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
