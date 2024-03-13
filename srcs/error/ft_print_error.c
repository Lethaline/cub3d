/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:21:09 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 18:21:10 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_print_error(char *message, int error)
{
	size_t	count;

	count = 0;
	while (message && message[count])
	{
		write(2, &message[count], 1);
		count++;
	}
	return (error);
}
