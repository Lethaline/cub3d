/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 23:16:28 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/15 01:13:07 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_handle_error(t_cub *cub, char *line, int error)
{
	ft_exit_program(cub);
	ft_free_ptr(line);
	return (error);
}

static int	ft_work_on_map(t_cub *cub)
{
	if (cub->map_lines != NULL)
		return (TRUE);
	return (FALSE);
}

int	ft_parsing_listener(t_cub *cub, char *line)
{
	if (line[0] == '\n' && ft_work_on_map(cub) == TRUE)
		return (ft_print_error("Error\nNew line not allowed in map\n", FAIL));
	if (line[0] != '\n')
	{
		if (!ft_check_scene(cub->file) && ft_check_map(line)== TRUE)
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
	int		result;

	while (1)
	{
		line = get_next_line(cub->input_fd);
		if (!line || line[0] == '\0')
			break ;
		if (ft_parsing_listener(cub, line) == FAIL)
			return (ft_handle_error(cub, line, FAIL));
		ft_free_ptr(line);
	}
	/*cub->map = ft_lst_to_tab(&cub->map_lines);
	if (!cub->map)
		return (ft_print_error("Error\nTab creation\n", FAIL));*/
	close(cub->input_fd);
	return (SUCCESS);
}
