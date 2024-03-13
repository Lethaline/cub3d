/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:20:01 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/11 12:54:55 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*ft_leaks_free(char *buffer, char *str)
{
	char	*mem;

	mem = ft_strjoin(buffer, str);
	ft_free_ptr(buffer);
	return (mem);
}

static char	*ft_save_memory(char *buffer)
{
	size_t	count;
	size_t	index;
	char	*save;
	
	count = 0;
	while (buffer && buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		ft_free_ptr(buffer);
		return (NULL);
	}
	save = ft_calloc(ft_strlen(buffer) - count + 1, sizeof(char));
	count++;
	index = 0;
	while (buffer[count])
	{
		save[index] = buffer[count];
		count++;
		index++;
	}
	ft_free_ptr(buffer);
	return (save);
}

static char	*ft_treat_line(char *buffer)
{
	char	*line;
	size_t	count;

	count = 0;
	if (!buffer[count])
		return (NULL);
	while (buffer && buffer[count] && buffer[count] != '\n')
		count++;
	line = ft_calloc(count + 2, sizeof(char));
	count = 0;
	while (buffer && buffer[count] && buffer[count] != '\n')
	{
		line[count] = buffer[count];
		count++;
	}
	if (buffer && buffer[count] && buffer[count] == '\n')
	{
		line[count] = '\n';
		count++;
	}
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	char	*str;
	int		readchar;

	if (!buffer)
		buffer = ft_calloc(1,1);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readchar = 1;
	while (ft_has_delimitor(str, '\n') == FALSE && readchar > 0)
	{
		readchar = read(fd, str, BUFFER_SIZE);
		if (readchar == -1)
		{
			ft_free_ptr(str);
			return (NULL);
		}
		str[readchar] = '\0';
		buffer = ft_leaks_free(buffer, str);
	}
	ft_free_ptr(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_treat_line(buffer);
	buffer = ft_save_memory(buffer);
	return (line);
}
