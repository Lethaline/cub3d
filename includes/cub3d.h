/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:49:06 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/13 00:36:54 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

// CREER Struct file + t_cub + t_map

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct	s_file
{
	int	north;
	int	south;
	int	west;
	int	east;
	t_color	*floor;
	t_color	*cell;
}	t_file;

typedef struct	s_cub
{
	t_file	*file;
}	t_cub;

enum e_char
{
	SPACE = 1,
	FLOOR,
	WALL,
	NORTH,
	SOUTH,
	WEST,
	EAST,
};

// Checks

int		ft_check_inputs(int ac, char **av);

// Free

void	ft_free_ptr(void *ptr);
void	ft_free_tab(char **tab);

// Init

void	ft_init_color(t_color *color);
void	ft_init_cub(t_cub *cub);
void	ft_init_file(t_file *file);

// Parsing

int		ft_check_scene(t_file *file);
int		ft_handle_scene(t_file *file, char *line);
int		ft_parsing(t_cub *cub, char *filename);

// Utils

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *dest, int c, size_t len);
char	**ft_split(const char *str, char *c);
int		ft_has_delimitor(char *str, int c);
char	*ft_strcpy(char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_tablen(char **tab);
char	*get_next_line(int fd);

#endif
