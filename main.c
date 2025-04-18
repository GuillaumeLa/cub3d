#include "cub3d.h"
#include "get_next_line.h"

int main(int argc , char *argv[])
{
	if(argc != 2)
		return (write(2,"Error // Wrong number of arguments\n", 35), 1);
	if(!parse_cub(argv[1]))
		return (write(2,"Error // Invalid .cub file\n", 27), 1);
	printf("North texture path: %s\n", s()->decals.north.path);
	printf("South texture path: %s\n", s()->decals.south.path);
	printf("West texture path: %s\n", s()->decals.west.path);
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