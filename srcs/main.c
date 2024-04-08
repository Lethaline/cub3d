/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2024/04/08 19:16:05 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	t_cub	*cub;

	if (ft_check_inputs(ac, av) == FAIL)
		return (FAIL);
	cub = ft_cub_new(av[1]);
	if (ft_parsing(cub) == FAIL)
		return (FAIL);
	if (ft_prepare_game(cub) == FAIL)
		return (ft_exit_program(cub));
	mlx = ft_mlx_new(cub);
	ft_start_game(mlx);
	ft_exit_program(cub);
	return (SUCCESS);
}
