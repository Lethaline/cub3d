/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 01:11:49 by lethaline         #+#    #+#             */
/*   Updated: 2024/04/09 02:53:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_play	*ft_play_new(void)
{
	t_play	*new;

	new = (t_play *)malloc(sizeof(t_play));
	if (!new)
		return (NULL);
	ft_init_play(&new);
	return (new);
}
