/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:36:22 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/17 02:38:04 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_new_line(char *line)
{
	size_t	count;

	count = 0;
	while (line && line[count])
	{
		if (line[count] == '\n')
			return (TRUE);
		count++;
	}
	return (FALSE);
}

char	*ft_remove_new_line(char *line)
{
	size_t	index;
	size_t	jndex;
	char	*temp;

	index = 0;
	jndex = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(line));
	if (!temp)
		return (NULL);
	while (line && line[index])
	{
		if (line[index] != '\n')
		{
			temp[jndex] = line[index];
			jndex++;
		}
		index++;
	}
	temp[jndex] = '\0';
	return (temp);
}

char	**ft_lst_to_tab(t_map **list)
{
	size_t	len;
	size_t	count;
	char	**map;
	t_map	*first;

	len = ft_map_size(*list);
	first = *list;
	map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	count = 0;
	while (*list && count < len)
	{
		if (ft_new_line((*list)->line) == TRUE)
			map[count] = ft_remove_new_line((*list)->line);
		else
			map[count] = ft_strdup((*list)->line);
		if (!map[count])
			return (ft_free_tab(map));
		count++;
		*list = (*list)->next;
	}
	map[count] = NULL;
	*list = first;
	return (map);
}
