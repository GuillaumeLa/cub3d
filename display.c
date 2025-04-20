#include "cub3d.h"

//affichage fenetre (ptr vers connexion a la mlx, ptr vers la window)
//gestion des touches (echap, wasd, left/right, croix rouge)

int key_press(int touche)
{
    if (touche == W)
        s()->k.w = 1;
    else if (touche == S)
        s()->k.s = 1;
    else if (touche == D)
        s()->k.d = 1;
    else if (touche == A)
        s()->k.a = 1;
    else if (touche == R)
        s()->k.r = 1;
    else if (touche == L)
        s()->k.l = 1;
    else if (touche == ECHAP)
        close_window_echap();
    return 0;
}

int key_release(int touche)
{
    if (touche == W)
        s()->k.w = 0;
    else if (touche == S)
        s()->k.s = 0;
    else if (touche == D)
        s()->k.d = 0;
    else if (touche == A)
        s()->k.a = 0;
    else if (touche == R)
        s()->k.r = 0;
    else if (touche == L)
        s()->k.l = 0;
    return 0;
}

int game_loop()
{
	if (s()->k.w)
		key_w();
	if (s()->k.s)
        key_s();
	if (s()->k.a)
        key_a();
	if (s()->k.d)
        key_d();
	if (s()->k.l)
        key_L();
    if (s()->k.r)
        key_R();

	//redisplay();
    return (0);
}

int close_window_echap()
{
    mlx_destroy_window(s()->mlx, s()->win);
    mlx_destroy_display(s()->mlx);//detruit la connexion a mlx
    free(s()->mlx);
    exit(0);
    return 0;
}

int close_window_cross()
{
    mlx_destroy_window(s()->mlx, s()->win);
    mlx_destroy_display(s()->mlx);
    free(s()->mlx);
    exit(0);
}

void open_window()
{
    s()->mlx = mlx_init();//connexion a la mlx
    if (s()->mlx == NULL)
        return;
    s()->win = mlx_new_window(s()->mlx, WIDTH, HEIGHT, NAME);//creer la fenetre
    if (s()->win == NULL)
        return;
    // mlx_key_hook(s()->win, close_window_echap, s());
    mlx_hook(s()->win, 17, 0L, close_window_cross, s());//17 = fermeture de la fenetre
    mlx_hook(s()->win, 2, 1L<<0, key_press, s());//2 = keypress
    mlx_hook(s()->win, 3, 1L<<1, key_release, s());//3 = keyrelease
    mlx_loop_hook(s()->mlx, game_loop, s());
    mlx_loop(s()->mlx);//la garder ouverte
}
