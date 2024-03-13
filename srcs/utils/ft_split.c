/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:26:57 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/11 18:22:27 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_is_sep(char c, char *sep)
{
	size_t	count;

	count = 0;
	while (sep[count])
	{
		if (sep[count] == c)
			return (TRUE);
		count++;
	}
	return (FALSE);
}

static char	**ft_free(char **str, int size)
{
	while (size >= 0)
	{
		free(str[size]);
		size--;
	}
	free(str);
	return (NULL);
}

static int	ft_check_if_null_word(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str[i], sep))
		i++;
	return (i);
}

static int	ft_get_nb_word(char *str, char *sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, sep))
			str++;
		i = ft_check_if_null_word(str, sep);
		str += i;
		if (i)
			word++;
	}
	return (word);
}

char	**ft_split(char const *s, char *c)
{
	char	**tab;
	int		size;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	size = ft_get_nb_word((char *)s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && ft_is_sep(*s, c))
			s++;
		n = ft_check_if_null_word((char *)s, c);
		tab[i] = ft_strcpy((char *)s, n);
		if (!tab[i])
			return (ft_free(tab, size));
		s += n;
		i++;
	}
	tab[size] = 0;
	return (tab);
}
