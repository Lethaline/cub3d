/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:28 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 01:18:21 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parsing(t_cub *cub, char *filename)
{
	int		fd;
	char	*line;
	int		scene_description;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAIL);
	scene_description = FALSE;
	while (1)
	{
		scene_description = ft_check_scene(cub->file);
		printf("%d\n", scene_description);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n' && scene_description == FALSE)
			ft_handle_scene(cub->file, line);
		if (scene_description == FALSE)
			break ;
		ft_free_ptr(line);
	}
	close(fd);
	return (SUCCESS);
}
