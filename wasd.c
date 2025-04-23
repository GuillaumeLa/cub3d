#include "cub3d.h"

void    key_w()
{
    double newX;
    double newY;

    newX = s()->p.X + s()->p.dirX * speed;
    newY = s()->p.Y + s()->p.dirY * speed;
    // if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')//collision horizontale
        s()->p.X = newX;
    // if (s()->map.data[(int)newY][(int)s()->p.X] != '1')//collision verticale
        s()->p.Y = newY;
    printf("X : %f ; ", s()->p.X);
    printf("Y : %f\n", s()->p.Y);
    printf("dirX : %f ; ", s()->p.dirX);
    printf("dirY : %f\n", s()->p.dirY);
}

void    key_s()
{
    double newX;
    double newY;

    newX = s()->p.X - s()->p.dirX * speed;
    newY = s()->p.Y - s()->p.dirY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)newX] != '1')
        s()->p.X = newX;
    if (s()->map.data[(int)newY][(int)s()->p.X] != '1')
        s()->p.Y = newY;
}

void    key_a()
{
    double new_planeX;
    double new_planeY;

    new_planeX = s()->p.X + s()->p.planeX * speed;
    new_planeY = s()->p.Y + s()->p.planeY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)new_planeX] != '1')
        s()->p.X = new_planeX;
    if (s()->map.data[(int)new_planeY][(int)s()->p.X] != '1')
        s()->p.Y = new_planeY;
}

void    key_d()
{
    double new_planeX;
    double new_planeY;

    new_planeX = s()->p.X - s()->p.planeX * speed;
    new_planeY = s()->p.Y - s()->p.planeY * speed;
    if (s()->map.data[(int)s()->p.Y][(int)new_planeX] != '1')
        s()->p.X = new_planeX;
    if (s()->map.data[(int)new_planeY][(int)s()->p.X] != '1')
        s()->p.Y = new_planeY;
}