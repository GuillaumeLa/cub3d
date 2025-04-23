#include "cub3d.h"

void    key_w()
{
    double newX;
    double newY;

    // newX = s()->p.X + s()->p.dirX * speed;
    // newY = s()->p.Y + s()->p.dirY * speed;
    newX = s()->p.X + cos(s()->p.angle) * speed;
    newY = s()->p.Y + sin(s()->p.angle) * speed;
    // if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')//collision horizontale
    if (!collision())
        s()->p.X = newX;
    // if (s()->map.data[(int)newY][(int)s()->p.X] != '1')//collision verticale
    if (!collision())
        s()->p.Y = newY;
}

void    key_s()
{
    double newX;
    double newY;

    // newX = s()->p.X - s()->p.dirX * speed;
    // newY = s()->p.Y - s()->p.dirY * speed;
    newX = s()->p.X - cos(s()->p.angle) * speed;
    newY = s()->p.Y - sin(s()->p.angle) * speed;
    // if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')
    if (!collision())
        s()->p.X = newX;
    // if (s()->map.data[(int)newY][(int)s()->p.X] != '1')
    if (!collision())
        s()->p.Y = newY;
}

void    key_a()
{
    double new_planeX;
    double new_planeY;

    new_planeX = s()->p.X - cos(s()->p.angle + M_PI / 2) * speed;
    new_planeY = s()->p.Y - sin(s()->p.angle + M_PI / 2) * speed;
    // if (s()->map.data[(int)s()->p.Y][(int)new_planeX] != '1')
        s()->p.X = new_planeX;
    // if (s()->map.data[(int)new_planeY][(int)s()->p.X] != '1')
        s()->p.Y = new_planeY;
}

void    key_d()
{
    double new_planeX;
    double new_planeY;

    new_planeX = s()->p.X + cos(s()->p.angle + M_PI / 2) * speed;
    new_planeY = s()->p.Y + sin(s()->p.angle + M_PI / 2) * speed;
    // if (s()->map.data[(int)s()->p.Y][(int)new_planeX] != '1')
        s()->p.X = new_planeX;
    // if (s()->map.data[(int)new_planeY][(int)s()->p.X] != '1')
        s()->p.Y = new_planeY;
}