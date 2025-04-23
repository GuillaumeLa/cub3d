#ifndef CUB3D_H
# define CUB3D_H

# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define NAME "CUB3D"
# define WIDTH 800
# define HEIGHT 400
# define TILE_SIZE 20
# define DEBUG 0
# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define L 65361
# define R 65363
# define speed 0.01
# define rot_speed 0.01

typedef struct s_player {
    int x;
    int y;
    float angle;

    double X;
    double Y;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
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

typedef struct s_keys
{
    int w;
    int s;
    int d;
    int a;
    int r;
    int l;
} t_keys;

typedef struct s_config {
    void    *mlx;
    void    *win;
    int     bpp;
    int     size_line;
    int     endian;
    char    *pixel_data;
    void   *img;
    t_map    map;
    t_decals decals;
    t_player p;
    t_keys      k;
} t_config;

//parsing
int     handle_map(char *filename);
int     parse_cub(char *filename);
int     handle_decals(char *filename , t_config *conf);
int     handle_rgb(int identifier , t_config *conf, char **rgb);
int     handle_files(char *line , t_config *conf , int identifier);
int     find_identifier(char *line);
int     parse_identifier(char *line , int identifier ,t_config *conf);

//deplacement (wasd.c rotations.c)
void    key_w();
void    key_s();
void    key_a();
void    key_d();
void    key_R();
void    key_L();

//display (esc, red cross, gestion du clavier)
void open_window();
int close_window_cross();
int close_window_echap();
int key_press(int touche);
int key_release(int touche);
int game_loop();

//raycasting
int     raytracing(t_config *game);
int collision();

//utils
t_config	*s(void);

#endif