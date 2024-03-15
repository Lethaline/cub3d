/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:36:22 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/15 01:12:38 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_lexer(int c)
{
	if (c == ' ')
		return (SPACE);
	if (c == '0')
		return (FLOOR);
	if (c == '1')
		return (WALL);
	if (c == 'N')
		return (NORTH);
	if (c == 'S')
		return (SOUTH);
	if (c == 'W')
		return (WEST);
	return (EAST);
}

void	ft_copy_map(int *map, t_map *map_line)
{
	size_t	count;

	count = 0;
	while (map_line->line && map_line->line[count])
	{
		if (map_line->line[count] != '\n')
			map[count] = ft_lexer(map_line->line[count]);
		count++;
	}
}

int	**ft_lst_to_tab(t_map **list)
{
	size_t	len;
	size_t	count;
	int		**map;

	len = ft_map_size(*list);
	map = (int **)malloc(sizeof(int *) * len);
	if (!map)
		return (NULL);
	count = 0;
	while (*list)
	{
		map[count] = (int *)malloc(sizeof(int) * ft_strlen((*list)->line));
		if (!map[count])
			return (NULL);
		ft_copy_map(map[count], *list);
		count++;
		*list = (*list)->next;
	}
	return (map);
}