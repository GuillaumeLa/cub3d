#include "cub3d.h"

void    key_w()
{
    double speed = 0.1;//"vitesse/fluidite de deplacement"
    double new_x;
    double new_y;

    new_x = s()->p.x + s()->p.dir_x * speed;
    new_y = s()->p.y + s()->p.dir_y * speed;
    if (s()->map.data[(int)s()->p.y][(int)new_x] != '1')//collision horizontale
        s()->p.x = new_x;
    if (s()->map.data[(int)new_y][(int)s()->p.x] != '1')//collision verticale
        s()->p.y = new_y;
}

void    key_s()
{
    double speed = 0.1;
    double new_x;
    double new_y;

    new_x = s()->p.x - s()->p.dir_x * speed;
    new_y = s()->p.y - s()->p.dir_y * speed;
    if (s()->map.data[(int)s()->p.y][(int)new_x] != '1')
        s()->p.x = new_x;
    if (s()->map.data[(int)new_y][(int)s()->p.x] != '1')
        s()->p.y = new_y;
}

void    key_a()
{
    double speed = 0.1;
    double new_plane_x;
    double new_plane_y;

    new_plane_x = s()->p.x + s()->p.plane_x * speed;
    new_plane_y = s()->p.y + s()->p.plane_y * speed;
    if (s()->map.data[(int)s()->p.y][(int)new_plane_x] != '1')
        s()->p.x = new_plane_x;
    if (s()->map.data[(int)new_plane_y][(int)s()->p.x] != '1')
        s()->p.y = new_plane_y;
}

void    key_d()
{
    double speed = 0.1;
    double new_plane_x;
    double new_plane_y;

    new_plane_x = s()->p.x - s()->p.plane_x * speed;
    new_plane_y = s()->p.y - s()->p.plane_y * speed;
    if (s()->map.data[(int)s()->p.y][(int)new_plane_x] != '1')
        s()->p.x = new_plane_x;
    if (s()->map.data[(int)new_plane_y][(int)s()->p.x] != '1')
        s()->p.y = new_plane_y;
}

void    key_R()
{
    double speed;//ajouter dans la struct ou def macro?
    double old_dirx;
    double old_planex;

    old_dirx = s()->p.dir_x;
    old_planex = s()->p.planex;
    s()->p.dirx = s()->p.dirx * cos
}

void    key_L()
{

}
