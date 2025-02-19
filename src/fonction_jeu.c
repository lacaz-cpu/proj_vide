#include "game_structures.h"


position * plateau(){
    position * plateau = (position*)malloc(sizeof(position));
    tuile t_depart;
    t_depart.centre = 'r';
    t_depart.cotes[0] = 'v';
    t_depart.cotes[1] = 'r';
    t_depart.cotes[2] = 'p';
    t_depart.cotes[3] = 'r';
    t_depart.pos.x = 0;
    t_depart.pos.y = 0;
    plateau[0] = t_depart.pos;
    return plateau;
}