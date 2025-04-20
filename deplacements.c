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
    double speed = 0.1;//"vitesse/fluidite de deplacement"
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

}

void    key_d()
{

}

void    key_R()
{

}

void    key_L()
{

}