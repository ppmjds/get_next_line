/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:37:27 by pperez-m          #+#    #+#             */
/*   Updated: 2021/11/01 14:07:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cont_read(char *rline, char c)
{
	int	i;

	i = 0;
	if(rline != 0)
	{
		while (rline[i] != '\0')
		{
			if (rline[i] == c)
				return (i);
			i++;
		}
	}
	return (0);
}

char	*next_line(char **readline)
{
	char	*line;
	int		i;
	char	*s;
	int		len;

	s = *readline;
	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = ft_strndup(s, i);
	if (!s[i])
	{
		free(s);
		*readline = 0;
		return (line);
	}
	len = ft_strlen(*readline) - i;
	*readline = ft_strndup(s + i + 1, len);
	free(s);
	return (line);
}

char	*get_next_line(int fd)
{
	int			nchar;
	char		*line = NULL;
	char		buffer[BUFFER_SIZE + 1];
	static char	*readline = 0;
	char		*tmp;

	if (readline == 0)
		readline = ft_strndup("", 0);
	nchar = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (cont_read(readline, '\n') == 0 && nchar > 0)
	{
		nchar = read(fd, buffer, BUFFER_SIZE);
		if (nchar == -1)
			return (NULL);
		buffer[nchar] = '\0';
		tmp = readline;
		readline = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	line = next_line(&readline);
//	printf("line = %c\n", *line);
	if (nchar == 0)
		return (NULL);
	return (line);
}
