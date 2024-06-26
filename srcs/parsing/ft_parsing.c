/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:28 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/11 17:14:37 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_handle_error(t_cub *cub, char *line, int error)
{
	ft_free_cub(cub);
	ft_free_ptr(line);
	get_next_line(-1);
	return (error);
}

static int	ft_work_on_map(t_cub *cub)
{
	if (cub->map_lines != NULL)
		return (TRUE);
	return (FALSE);
}

static int	ft_parsing_listener(t_cub *cub, char *line)
{
	if (line[0] == '\n' && ft_work_on_map(cub) == TRUE)
		return (ft_print_error("Error\nNew line not allowed in map\n", FAIL));
	if (line[0] != '\n')
	{
		if (!ft_check_scene(cub->file) && ft_check_map(line) == TRUE)
			return (ft_print_error("Error\nMissing ID scene\n", FAIL));
		if (!ft_check_scene(cub->file))
			return (ft_handle_scene(cub->file, line));
		if (ft_check_scene(cub->file))
			return (ft_handle_map(cub, line));
	}
	return (SUCCESS);
}

int	ft_parsing(t_cub *cub)
{
	char	*line;

	while (1)
	{
		line = get_next_line(cub->input_fd);
		if (!line || line[0] == '\0')
			break ;
		if (ft_parsing_listener(cub, line) == FAIL)
			return (ft_handle_error(cub, line, FAIL));
		ft_free_ptr(line);
	}
	if (ft_check_ext(cub->file->north, ".xpm")
		|| ft_check_ext(cub->file->south, ".xpm")
		|| ft_check_ext(cub->file->east, ".xpm")
		|| ft_check_ext(cub->file->west, ".xpm"))
		return (ft_print_error("Error\nBad sprite extension\n", FAIL));
	cub->width = ft_map_width(&cub->map_lines);
	cub->height = ft_map_size(&cub->map_lines);
	cub->map = ft_lst_to_tab(&cub->map_lines);
	if (!cub->map)
	{
		ft_print_error("Error\nDuring map creation\n", FAIL);
		return (ft_free_cub(cub));
	}
	return (SUCCESS);
}
