#include "../../includes/cub3d.h"

int	ft_test(t_mlx *mlx, int code)
{
	printf("%d\n", code);
	mlx_destroy_window(mlx->mlx_p, mlx->wind); //segfault
	ft_exit_program(mlx->cub); //segfault
	exit(SUCCESS);
}

int	ft_key_pressed(int key_code, t_mlx *mlx)
{
	printf("%d", key_code);
	if (key_code == 53) //ESCP KEY
	{
		// mlx_destroy_image(mlx->mlx_p, mlx->img); //-> pas encore de img
		mlx_destroy_window(mlx->mlx_p, mlx->wind); //-> SEGFAULT ??????
		ft_exit_program(mlx->cub); //-> srcs/parsing/ft_lst_to_tab.c:73:11: warning: incompatible integer to pointer conversion returning 'int' from a function with result type 'char **' [-Wint-conversion]
		exit(SUCCESS);
	}
	return (0);
}

void	ft_start_game(t_mlx *mlx){
	mlx_key_hook(mlx->wind, ft_key_pressed, mlx);
	mlx_hook(mlx->wind, 17, 0, ft_test, mlx);
	mlx_loop(mlx->mlx_p);
}