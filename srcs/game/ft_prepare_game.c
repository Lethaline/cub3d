/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:10:08 by lethaline         #+#    #+#             */
/*   Updated: 2024/03/29 13:14:08 by lolemmen         ###   ########.fr       */
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
	if ((cub->map[x][y] == 'N' || cub->map[x][y] == 'S'
		|| cub->map[x][y] == 'W' || cub->map[x][y] == 'E') && cub->player)
		return (ft_print_error("Error\nMultiple players", FAIL));
	if (cub->map[x][y] == 'N')
		cub->player = ft_play_new(y, x, 3*(PI/2));
	if (cub->map[x][y] == 'S')
		cub->player = ft_play_new(y, x, PI/2);
	if (cub->map[x][y] == 'W')
		cub->player = ft_play_new(y, x, PI);
	if (cub->map[x][y] == 'E')
		cub->player = ft_play_new(y, x, 0);
	if (!cub->player)
		return (ft_print_error("Error\nDuring malloc\n", FAIL));
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
	return (SUCCESS);
}
