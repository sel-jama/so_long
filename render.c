#include "so_long.h"

void	render_map(so_long *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->cols;
	while (vars->rows > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->cols > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 50;
			vars->cols--;
		}
		vars->cols = backup_w;
		y_map++;
		y1 += 50;
		vars->cols--;
	}
}
// }void	to_left(so_long **v)
// {
// 	int		img_w;
// 	int		img_h;

// 	(*v)->img = mlx_xpm_file_to_image(
// 			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
// 	mlx_put_image_to_window(
// 		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
// 	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] == 'E')
// 	{
// 		if ((*v)->collect <= 0)
// 			exit_door(&v);
// 	}
// 	else if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50) - 1] != '1')
// 	{
// 		(*v)->x_p -= 50;
// 		put_text(&v);
// 	}
// 	if ((*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] == 'C')
// 		collected(&v);
// 	(*v)->img = mlx_xpm_file_to_image(
// 			(*v)->mlx, "./img/left.xpm", &img_w, &img_h);
// 	mlx_put_image_to_window(
// 		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
// }