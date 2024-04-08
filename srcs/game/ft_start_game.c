#include "../../includes/cub3d.h"

int	ft_test(t_mlx *mlx, int code)
{
	printf("%d\n", code);
	mlx_destroy_window(mlx->mlx_p, mlx->wind);
	ft_exit_program(mlx->cub);
	exit(SUCCESS);
}

int	ft_key_pressed(int key_code, t_mlx *mlx)
{
	if (key_code == 53) //ESCP KEY
	{
		// mlx_destroy_image(mlx->mlx_p, mlx->img); //-> pas encore de img
		mlx_destroy_window(mlx->mlx_p, mlx->wind);
		ft_exit_program(mlx->cub);
		exit(SUCCESS);
	}
	return (0);
}

void	ft_start_game(t_mlx *mlx){
	mlx_key_hook(mlx->wind, ft_key_pressed, mlx);
	mlx_hook(mlx->wind, 17, 0, ft_test, mlx);
	//ft_raycasting(mlx);
	mlx_loop(mlx->mlx_p);
}