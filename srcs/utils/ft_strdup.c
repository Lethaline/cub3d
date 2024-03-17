/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:43:42 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 17:43:43 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	count;
	size_t	len;

	count = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
