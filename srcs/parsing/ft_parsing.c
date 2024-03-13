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

static int	ft_handle_error(t_cub *cub, char *line, int error)
{
	ft_free_cub(cub);
	ft_free_ptr(line);
	return (error);
}

int	ft_parsing(t_cub *cub)
{
	int		fd;
	char	*line;
	int		result;

	while (1)
	{
		line = get_next_line(cub->input_fd);
		if (!line || line[0] == '\0')
			break ;
		if (line[0] != '\n')
		{
			if (ft_check_scene(cub->file) == FALSE)
				result = ft_handle_scene(cub->file, line);
			if (ft_check_scene(cub->file) == TRUE)
				printf("map");
		}
		if (result == FAIL)
			return (ft_handle_error(cub, line, 1));
		ft_free_ptr(line);
	}
	ft_debug_cub(cub);
	close(fd);
	return (SUCCESS);
}
