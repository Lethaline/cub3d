/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:12:57 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 16:12:58 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_cub	*ft_cub_new(char *filename)
{
	t_cub	*new;

	new = (t_cub *)malloc(sizeof(t_cub));
	if (!new)
		return (NULL);
	ft_init_cub(&new);
	new->input_fd = open(filename, O_RDONLY);
	if (new->input_fd == -1)
	{
		ft_free_ptr(new);
		return (NULL);
	}
	return (new);
}
