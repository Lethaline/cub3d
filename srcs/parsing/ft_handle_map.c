/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:54:24 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 17:54:24 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_handle_map(t_cub *cub, char *line)
{
    if (ft_check_map(line) == FALSE)
        return (ft_print_error("Error\nInvalid character in map\n", FAIL));
    return (SUCCESS);
}
