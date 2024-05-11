/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:47:23 by lolemmen          #+#    #+#             */
/*   Updated: 2024/05/11 16:47:16 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_handle_east_west(char **tab, t_file *file)
{
	if (!ft_strncmp(tab[0], "WE", 2) && file->west != NULL)
		return (ft_print_error("Error\nDuplicate WE line\n", FAIL));
	if (!ft_strncmp(tab[0], "WE", 2) && ft_access(tab[1]) == SUCCESS)
	{
		file->west = ft_strdup(tab[1]);
		if (file->west == NULL)
			return (ft_print_error("Error\nStrdup failed for WE\n", FAIL));
	}
	if (!ft_strncmp(tab[0], "EA", 2) && file->east != NULL)
		return (ft_print_error("Error\nDuplicate EA line\n", FAIL));
	if (!ft_strncmp(tab[0], "EA", 2) && ft_access(tab[1]) == SUCCESS)
	{
		file->east = ft_strdup(tab[1]);
		if (file->east == NULL)
			return (ft_print_error("Error\nStrdup failed for EA\n", FAIL));
	}
	return (SUCCESS);
}

static int	ft_handle_sprites(char **tab, t_file *file)
{
	if (ft_strncmp(tab[0], "NO", 2) && ft_strncmp(tab[0], "SO", 2)
		&& ft_strncmp(tab[0], "WE", 2) && ft_strncmp(tab[0], "EA", 2))
		return (ft_print_error("Error\nSprite ID code : NO SO WE EA\n", FAIL));
	if (!ft_strncmp(tab[0], "NO", 2) && file->north != NULL)
		return (ft_print_error("Error\nDuplicate NO line\n", FAIL));
	if (!ft_strncmp(tab[0], "NO", 2) && ft_access(tab[1]) == SUCCESS)
	{
		file->north = ft_strdup(tab[1]);
		if (file->north == NULL)
			return (ft_print_error("Error\nStrdup failed for NO\n", FAIL));
	}
	if (!ft_strncmp(tab[0], "SO", 2) && file->south != NULL)
		return (ft_print_error("Error\nDuplicate SO line\n", FAIL));
	if (!ft_strncmp(tab[0], "SO", 2) && ft_access(tab[1]) == SUCCESS)
	{
		file->south = ft_strdup(tab[1]);
		if (file->south == NULL)
			return (ft_print_error("Error\nStrdup failed for SO\n", FAIL));
	}
	if (!ft_strncmp(tab[0], "EA", 2) || !ft_strncmp(tab[0], "WE", 2))
		return (ft_handle_east_west(tab, file));
	return (SUCCESS);
}

static int	ft_fill_color(char **rgb, t_color *color)
{
	color->red = ft_atoi(rgb[0]);
	color->green = ft_atoi(rgb[1]);
	color->blue = ft_atoi(rgb[2]);
	if (color->red < 0 || color->red > 255 || color->green < 0
		|| color->green > 255 || color->blue < 0 || color->blue > 255)
		return (ft_print_error("Error\nColors code : >= 0 and <= 255\n", FAIL));
	return (SUCCESS);
}

static int	ft_handle_color(char **tab, t_file *file)
{
	char	**rgb;
	int		result;

	if (ft_strncmp(tab[0], "F", 1) && ft_strncmp(tab[0], "C", 1))
		return (ft_print_error("Error\nColors code : F or C\n", FAIL));
	rgb = ft_split(tab[1], ",");
	if (!rgb)
		return (FAIL);
	if (ft_tablen(rgb) != 3)
	{
		ft_free_tab(rgb);
		return (ft_print_error("Error\nColors code : Red,Green,Blue\n", FAIL));
	}
	if (!ft_strncmp(tab[0], "F", 1) && ft_check_color(file->floor))
		result = ft_print_error("Error\nDuplicate F line\n", FAIL);
	else if (!ft_strncmp(tab[0], "C", 1) && ft_check_color(file->cell))
		result = ft_print_error("Error\nDuplicate C line\n", FAIL);
	else if (!ft_strncmp(tab[0], "F", 1))
		result = ft_fill_color(rgb, file->floor);
	else
		result = ft_fill_color(rgb, file->cell);
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
	{
		ft_free_tab(tab);
		return (ft_print_error("Error\nSprite code : ID name\n", FAIL));
	}
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
