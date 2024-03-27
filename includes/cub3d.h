/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:49:06 by lolemmen          #+#    #+#             */
/*   Updated: 2024/03/27 10:05:24 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_file
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	*floor;
	t_color	*cell;
}	t_file;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_play
{
	int		x;
	int		y;
	char	direction;
}	t_play;

typedef struct s_cub
{
	t_file	*file;
	t_map	*map_lines;
	t_play	*player;
	char	**map;
	int		input_fd;
}	t_cub;

typedef struct s_mlx //the mlx structure
{
	void  	*wind;
	void  	*mlx_p;
	t_cub	*cub;
	
	// t_ray   *ray; // the ray structure
	// t_data   *dt; // the data structure
	// t_player  *ply; // the player structure
} t_mlx;

enum e_char
{
	SPACE = 32,
	FLOOR = 48,
	WALL = 49,
	NORTH = 78,
	SOUTH = 83,
	WEST = 87,
	EAST = 69
};

// Checks

int		ft_check_inputs(int ac, char **av);

// Debug

void	ft_debug(void);
void	ft_debug_int_map(int **tab);
void	ft_debug_cub(t_cub *cub);

// Error

int		ft_print_error(char *message, int error);

// Free

int		ft_exit_program(t_cub *cub);
void	ft_free_map_lines(t_cub *cub);
void	ft_free_ptr(void *ptr);
void	ft_free_int_tab(t_cub *cub);
char	**ft_free_tab(char **tab);
void	ft_free_cub(t_cub *cub);

// Game

int		ft_prepare_game(t_cub *cub);
void	ft_start_game(t_mlx *mlx);

// Init

void	ft_init_color(t_color **color);
void	ft_init_cub(t_cub **cub);
void	ft_init_file(t_file **file);
void	ft_init_map(t_map **map);
void	ft_init_mlx(t_mlx **mlx);
void	ft_init_play(t_play **player);

// New

t_color	*ft_color_new(void);
t_cub	*ft_cub_new(char *filename);
t_file	*ft_file_new(void);
t_map	*ft_map_new(void *line);
t_mlx   *ft_mlx_new(t_cub *cub);
t_play	*ft_play_new(int x, int y, char direction);

// Parsing

int		ft_check_map(char *line);
int		ft_check_scene(t_file *file);
int		ft_check_color(t_color *color);
int		ft_handle_map(t_cub *cub, char *line);
int		ft_handle_scene(t_file *file, char *line);
char	**ft_lst_to_tab(t_map **list);
int		ft_parsing(t_cub *cub);

// Utils

int		ft_access(char *filename);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *dest, int c, size_t len);
char	**ft_split(const char *str, char *c);
int		ft_has_delimitor(char *str, int c);
void	ft_map_add_back(t_map **map, t_map *new);
size_t	ft_map_size(t_map *map);
char	*ft_strcpy(char *src, int n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_tablen(char **tab);
char	*get_next_line(int fd);

#endif
