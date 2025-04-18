#ifndef CUB3D_H
#define CUB3D_H
# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_player {
    int x;
    int y;
    char direction;
} t_player;

typedef struct s_texture {
    char *path;
    void *img;
} t_texture ;

typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;

typedef struct s_map {
    int line;
    int columns;
    char **data;
} t_map;

typedef struct s_decals {
    t_texture north;
    t_texture south;
    t_texture west;
    t_texture east;
    t_color     floor_color;
    t_color     ceiling_color;
} t_decals;

typedef struct s_config {
    void    *mlx;
    void    *win;
    t_map    map;
    t_decals decals;
} t_config;
int     handle_map(char *filename);
int     parse_cub(char *filename);
int     handle_decals(char *filename , t_config *conf);
int     handle_rgb(int identifier , t_config *conf, char **rgb);
int     handle_files(char *line , t_config *conf , int identifier);
int     find_identifier(char *line);
int     parse_identifier(char *line , int identifier ,t_config *conf);
t_config	*s(void);
#endif