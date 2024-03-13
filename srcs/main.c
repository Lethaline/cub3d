/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:03:12 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/10 14:30:20 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ft_check_inputs(ac, av) == FAIL)
		return (FAIL);
	ft_memset(&cub, 0, sizeof(t_cub));
	ft_init_cub(&cub);
	if (ft_parsing(&cub, av[1]) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
