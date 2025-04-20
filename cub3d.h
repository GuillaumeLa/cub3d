#ifndef CUB3D_H
#define CUB3D_H
# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define BOLD "\033[1m"
# define RESET "\033[0m"

# define WIDTH 640
# define HEIGHT 480
# define NAME "cub3d"
# define ECHAP 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define L 65361
# define R 65363
# define speed 0.1

typedef struct s_player
{
    double X;
    double Y;
    double dirX;//(1;0) si le joueur regarde a droite
    double dirY;//(0;-1) si le joueur regarde vers le haut
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
    void        *mlx;
    void        *win;
    t_map       map;
    t_decals    decals;
    t_player    p;
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

//deplacements
void    key_w();
void    key_s();
void    key_a();
void    key_d();
void    key_R();
void    key_L();

//display
void open_window();
int close_window_cross();
int close_window_echap();

//raycasting
int    raycasting();

//utils
t_config	*s(void);

#endif