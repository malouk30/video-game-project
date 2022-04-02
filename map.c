#include "header.h"

void initmap(minimap *m)
{
    m->map = IMG_Load("minimap1.png");
    m->pos_map.x = 0;
    m->pos_map.y = 0;
}

void maj_camera_perso(INPUT input, SDL_Rect* position_perso,SDL_Rect* position_camera)
{

    if (input.clavier.right)
    {
        position_perso.x += 10;
        position_camera.y += 10;
    }
    else
        if(input.clavier.left)
    {
        position_perso.x -= 10;
        position_camera.y -= 10;
    }
    if (input.clavier.up)
    {
        position_perso.x += 10;
        position_camera.y += 10;
    }
     else
        if(input.clavier.down)
    {
        position_perso.x -= 10;
        position_camera.y -= 10;
    }
}


void majminimap(SDL_Rect position_perso, minimap *m ,SDL_Rect camera ,int redimensionnement){

  pos_miniPerso.x = position_perso.x * redimensionnement/100;
  pos_miniPerso.y = position_perso.y * redimensionnement/100;

}

void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.map, NULL, screen, &m.pos_map);
}
