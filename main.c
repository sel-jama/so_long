# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int print_key(int keycode, void *param)
{
    printf("%i\n", keycode);
    exit(0);
    return (0);
}
int main(void)
{
    void    *mlx;
    void    *win;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 10 * 64, 5 * 64, "test");
    //mlx_key_hook(win, print_key, NULL);
    mlx_hook(win, 17, 0, print_key, NULL);
    mlx_loop(mlx);
    return (0);
}
/*
    display_game
    move_palayer
*/