#include "cub3d.h"
#include "get_next_line.h"

int main(int argc , char *argv[])
{
	t_config	conf;

	if(argc != 2)
		return (write(2,"Error // Wrong number of arguments\n", 35), 1);
	if(!parse_cub(argv[1], &conf))
		return (write(2,"Error // Invalid .cub file\n", 27), 1);
	printf("North texture path: %s\n", conf.decals.north.path);
	printf("South texture path: %s\n", conf.decals.south.path);
	printf("West texture path: %s\n", conf.decals.west.path);
	printf("East texture path: %s\n", conf.decals.east.path);
	printf("Floor color: %d, %d, %d\n", conf.decals.floor_color.r, conf.decals.floor_color.g, conf.decals.floor_color.b);
	printf("Ceiling color: %d, %d, %d\n", conf.decals.ceiling_color.r, conf.decals.ceiling_color.g, conf.decals.ceiling_color.b);
	free(conf.decals.north.path);
	free(conf.decals.south.path);
	free(conf.decals.west.path);
	free(conf.decals.east.path);
	return (0);
}