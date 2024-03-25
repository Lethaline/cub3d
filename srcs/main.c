/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/25 16:10:26 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_cub	*cub;
	int		fd;

	if (ft_check_inputs(ac, av) == FAIL)
		return (FAIL);
	cub = ft_cub_new(av[1]);
	if (ft_parsing(cub) == FAIL)
		return (FAIL);
	if (ft_prepare_game(cub) == FAIL)
		return (ft_exit_program(cub));
	mlx.cub = cub;
	ft_start_game(&mlx);
	ft_exit_program(cub);
	return (SUCCESS);
}
