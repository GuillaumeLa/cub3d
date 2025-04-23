#include "cub3d.h"

int collision()
{
    if(s()->map.data[(int)s()->p.Y][(int)s()->p.Y] == '1')
        return 1;
    return 0;
}