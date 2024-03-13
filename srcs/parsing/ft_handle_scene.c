/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:47:23 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 01:17:14 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_handle_sprites(char **tab, t_file *file)
{
	(void)file;
//	printf("sprite %s\n", tab[0]);
	if (!ft_strncmp(tab[0], "NO", 2) || !ft_strncmp(tab[0], "SO", 2)
		|| !ft_strncmp(tab[0], "WE", 2) || !ft_strncmp(tab[0], "EA", 2))
		return (FAIL);
	return (SUCCESS);
}

static int	ft_fill_color(char **rgb, t_color *color)
{
	color->red = ft_atoi(rgb[0]);
	color->green = ft_atoi(rgb[1]);
	color->blue = ft_atoi(rgb[2]);
	if (color->red < 0 || color->red > 255 || color->green < 0
		|| color->green > 255 || color->blue < 0 || color->blue > 255)
		return (FAIL);
	return (SUCCESS);
}

static int	ft_handle_color(char **tab, t_file *file)
{
	char	**rgb;
	int		result;

	if (ft_strncmp(tab[0], "F", 1) && ft_strncmp(tab[0], "C", 1))
		return (FAIL);
	rgb = ft_split(tab[1], ",");
	if (!rgb)
		return (FAIL);
	if (ft_tablen(rgb) != 3)
	{
		ft_free_tab(rgb);
		return (FAIL);
	}
	if (!ft_strncmp(tab[0], "F", 1))
		result = ft_fill_color(rgb, file->floor);
	else
		result = ft_fill_color(rgb, file->cell);
	printf("%d %d %d\n", file->floor->red, file->floor->green, file->floor->blue);
	ft_free_tab(rgb);
	return (result);
}

int	ft_handle_scene(t_file *file, char *line)
{
	char	**tab;
	size_t	len;
	int		result;

	tab = ft_split(line, " \n");
	if (!tab)
		return (FAIL);
	if (ft_tablen(tab) != 2)
		return (FAIL);
	len = ft_strlen(tab[0]);
	if (len == 1)
		result = ft_handle_color(tab, file);
	else if (len == 2)
		result = ft_handle_sprites(tab, file);
	else
		result = FAIL;
	ft_free_tab(tab);
	return (result);
}
