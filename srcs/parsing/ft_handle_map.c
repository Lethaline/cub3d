/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:54:24 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/15 22:55:36 by lethaline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_handle_map(t_cub *cub, char *line)
{
    if (ft_check_map(line) == FALSE)
        return (ft_print_error("Error\nInvalid character in map\n", FAIL));
	ft_map_add_back(&cub->map_lines, ft_map_new(ft_strdup(line)));
    return (SUCCESS);
}
