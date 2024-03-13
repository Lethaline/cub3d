/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:18:46 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/11 12:30:20 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len;
	size_t	count;
	size_t	index;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	count = 0;
	while (s1 && s1[count])
	{
		joined[count] = s1[count];
		count++;
	}
	index = 0;
	while (s2 && s2[index])
	{
		joined[count + index] = s2[index];
		index++;
	}
	joined[len] = '\0';
	return (joined);
}
