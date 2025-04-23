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
				s()->player.x = x;
				s()->player.y = y;
				if (c == 'N') 
					s()->player.angle = 3 * M_PI / 2;
				if (c == 'S') 
					s()->player.angle = M_PI / 2;
				if (c == 'E') 
					s()->player.angle = 0;
				if (c == 'W') 
					s()->player.angle = M_PI;
				return;
			}
		}
	}
}
void init_game()
{
    init_player();
    s()->mlx = mlx_init();
    s()->win = mlx_new_window(s()->mlx, WIDTH, HEIGHT, "CUB3D");
    s()->img = mlx_new_image(s()->mlx, WIDTH, HEIGHT);
    s()->pixel_data = mlx_get_data_addr(s()->img, &s()->bpp, &s()->size_line, &s()->endian);
    mlx_put_image_to_window(s()->mlx, s()->win, s()->img, 0, 0);
}

int main(int argc , char *argv[])
{
	if(argc != 2)
		return (write(2,"Error // Wrong number of arguments\n", 35), 1);
	if(!parse_cub(argv[1]))
		return (write(2,"Error // Invalid .cub file\n", 27), 1);
	init_game();
    mlx_loop_hook(s()->mlx, raytracing, s());
    mlx_loop(s()->mlx);
	printf("North texture path: %s\n", s()->decals.north.path);
	printf("South texture path: %s\n", s()->decals.south.path);
	//printf("West texture path: %s\n", s()->decals.west.path);
	printf("East texture path: %s\n", s()->decals.east.path);
	printf("Floor color: %d, %d, %d\n", s()->decals.floor_color.r, s()->decals.floor_color.g, s()->decals.floor_color.b);
	printf("Ceiling color: %d, %d, %d\n", s()->decals.ceiling_color.r, s()->decals.ceiling_color.g, s()->decals.ceiling_color.b);
	printf("Map lines: %d\n", s()->map.line);
	printf("Map columns: %d\n", s()->map.columns);
	for (int i = 0; i < s()->map.line; i++)
	{
		printf("Map line %d: %s", i + 1, s()->map.data[i]);
		free(s()->map.data[i]);
	}
	free(s()->decals.north.path);
	free(s()->decals.south.path);
	free(s()->decals.west.path);
	free(s()->decals.east.path);
	return (0);
}