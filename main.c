#include "cub3d.h"
#include "get_next_line.h"

void init_player(void)
{
	for (int y = 0; y < s()->map.line; y++)
	{
		for (int x = 0; x < s()->map.columns; x++)
		{
			char c = s()->map.data[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				s()->p.x = x;
				s()->p.y = y;
				if (c == 'N') 
					s()->p.angle = 3 * M_PI / 2;
				if (c == 'S') 
					s()->p.angle = M_PI / 2;
				if (c == 'E') 
					s()->p.angle = 0;
				if (c == 'W') 
					s()->p.angle = M_PI;
				return;
			}
		}
	}

	s()->p.X = 5.0;
	s()->p.Y = 5.0;
	s()->p.dirX = 0.0;
	s()->p.dirY = -1.0;
	s()->p.planeX = 0.66;
	s()->p.planeY = 0.0;
}
void init_game()
{
    init_player();
    s()->mlx = mlx_init();
	if (s()->mlx == NULL)
		return;
    s()->win = mlx_new_window(s()->mlx, WIDTH, HEIGHT, NAME);
    if (s()->win == NULL)
		return;
	s()->img = mlx_new_image(s()->mlx, WIDTH, HEIGHT);
    s()->pixel_data = mlx_get_data_addr(s()->img, &s()->bpp, &s()->size_line, &s()->endian);
    mlx_put_image_to_window(s()->mlx, s()->win, s()->img, 0, 0);
	mlx_hook(s()->win, 17, 0L, close_window_cross, NULL);//17 = fermeture de la fenetre
    mlx_hook(s()->win, 2, 1L<<0, key_press, NULL);//2 = keypress
    mlx_hook(s()->win, 3, 1L<<1, key_release, NULL);//3 = keyrelease
    mlx_loop_hook(s()->mlx, game_loop, NULL);
	mlx_loop_hook(s()->mlx, raytracing, s());
    mlx_loop(s()->mlx);
}

int main(int argc , char *argv[])
{
	if(argc != 2)
		return (write(2,"Error // Wrong number of arguments\n", 35), 1);
	else
	{
		if (parse_cub(argv[1]))
			init_game();
		else
			return (write(2,"Error // Invalid .cub file\n", 27), 1);
	}
	// init_game();
	// printf("North texture path: %s\n", s()->decals.north.path);
	// printf("South texture path: %s\n", s()->decals.south.path);
	// //printf("West texture path: %s\n", s()->decals.west.path);
	// printf("East texture path: %s\n", s()->decals.east.path);
	// printf("Floor color: %d, %d, %d\n", s()->decals.floor_color.r, s()->decals.floor_color.g, s()->decals.floor_color.b);
	// printf("Ceiling color: %d, %d, %d\n", s()->decals.ceiling_color.r, s()->decals.ceiling_color.g, s()->decals.ceiling_color.b);
	// printf("Map lines: %d\n", s()->map.line);
	// printf("Map columns: %d\n", s()->map.columns);
	for (int i = 0; i < s()->map.line; i++)
	{
		// printf("Map line %d: %s", i + 1, s()->map.data[i]);
		free(s()->map.data[i]);
	}
	free(s()->decals.north.path);
	free(s()->decals.south.path);
	free(s()->decals.west.path);
	free(s()->decals.east.path);
	return (0);
}