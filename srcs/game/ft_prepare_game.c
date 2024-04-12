/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:10:08 by lethaline         #+#    #+#             */
/*   Updated: 2024/04/09 05:16:51 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_must_be_closed(char c, char *list)
{
	size_t	count;

	count = 0;
	while (list && list[count])
	{
		if (list[count] == c)
			return (TRUE);
		count++;
	}
	return (FALSE);
}

static int	ft_player(char c, char *list)
{
	size_t	count;

	count = 0;
	while (list && list[count])
	{
		if (list[count] == c)
			return (TRUE);
		count++;
	}
	return (FALSE);
}

static int	ft_check_closed(t_cub *cub, size_t x, size_t y)
{
	if (!ft_must_be_closed(cub->map[x][y], "0NSWE"))
		return (SUCCESS);
	if (!cub->map[x - 1][y] || cub->map[x - 1][y] == ' ')
		return (ft_print_error("Error\nMap not closed\n", FAIL));
	if (!cub->map[x + 1][y] || cub->map[x + 1][y] == ' ')
		return (ft_print_error("Error\nMap not closed\n", FAIL));
	if (!cub->map[x][y - 1] || cub->map[x][y - 1] == ' ')
		return (ft_print_error("Error\nMap not closed\n", FAIL));
	if (!cub->map[x][y + 1] || cub->map[x][y + 1] == ' ')
		return (ft_print_error("Error\nMap not closed\n", FAIL));
	return (SUCCESS);
}

static int	ft_check_player(t_cub *cub, size_t x, size_t y)
{
	if (!ft_player(cub->map[x][y], "NSWE"))
		return (SUCCESS);
	if (cub->direction != -1)
		return (ft_print_error("Error\nMultiple players\n", FAIL));
	cub->x = x;
	cub->y = y;
	if (cub->map[x][y] == NORTH)
		cub->direction = 3 * (PI/2);
	if (cub->map[x][y] == SOUTH)
		cub->direction = PI/2;
	if (cub->map[x][y] == WEST)
		cub->direction = PI;
	if (cub->map[x][y] == EAST)
		cub->direction = 0;
	return (SUCCESS);
}

int	ft_prepare_game(t_cub *cub)
{
	size_t	index;
	size_t	jndex;

	index = 0;
	while (cub->map[index])
	{
		jndex = 0;
		while (cub->map[index][jndex])
		{
			if (ft_check_player(cub, index, jndex))
				return (FAIL);
			if (ft_check_closed(cub, index, jndex))
				return (FAIL);
			jndex++;
		}
		index++;
	}
	if (cub->direction == -1)
		return (ft_print_error("Error\nMissing player\n", FAIL));
	return (SUCCESS);
}
