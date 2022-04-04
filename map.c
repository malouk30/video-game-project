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
void initialiser_temps(temps *t)
{
t->texte = NULL;

t->position.x=0;
t->position.y=0;

t->police = NULL;
t->police = TTF_OpenFont("ka1.ttf", 20);
if(t->police==NULL)
printf("error police\n");
strcpy( t->entree,"");    
t->tempsActuel = 0; 
t->tempsPrecedent = 0;
t->min = 0;
t->cmp=0;

}
void afficher_temps(temps *t,SDL_Surface *screen)
{

 int continuer = 1;

TTF_Font *police = NULL;


 SDL_Event event;
 SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {255, 0, 0};
 
t->tempsActuel = SDL_GetTicks();
 
sprintf(t->entree, "Temps : %d",t->cmp);


t->texte = TTF_RenderText_Shaded(t->police,t->entree, couleurNoire, couleurRouge);  


t->tempsActuel = SDL_GetTicks();

 
     
        if (t->tempsActuel - t->tempsPrecedent >= 1000) 
         {
            t->cmp++;  
 
            if(t->cmp ==60)
             {
               t->cmp=0;
               t->cmp++;
                  t->min++;
             }
  sprintf(t->entree, ":%dm :%ds",t->min,t->cmp); 
 

 t->texte = TTF_RenderText_Shaded(t->police, t->entree, couleurNoire, couleurRouge);
      t->tempsPrecedent = t->tempsActuel;  
          }
    
        t->position.x = 800;
        t->position.y = 0;
        SDL_BlitSurface(t->texte, NULL, screen, &t->position);
	
        SDL_Flip(screen);
  

}
