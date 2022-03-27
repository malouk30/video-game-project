#include "header.h"

void initmap(minimap *m)
{
    m->map = IMG_Load("minimap1.png");
    //position minimap
    m->pos_map.x = 0;
    m->pos_map.y = 0;
}

void majminimap(Personne *p, minimap *m ,SDL_Rect camera ,int redimensionnement){
  if (camera.x==0)//right
  p->pos_perso.x += redimensionnement;

  if (camera.x==1)//left
  p->pos_perso.x -= redimensionnement;

  if (camera.x==2)//down
  p->pos_perso.y += redimensionnement;

  if (camera.x==3)//up
  p->pos_perso.y -= redimensionnement;
}

void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.map, NULL, screen, &m.pos_map);
}
