#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{
    SDL_Surface *map_img;
	SDL_Rect pos_map;
    SDL_Surface *miniPerso_img;
	SDL_Rect pos_miniPerso;

}minimap;

typedef struct
{
	SDL_Rect pos_perso;
	SDL_Surface *perso;
} Personne;

void initmap(minimap *m);
void majminimap(Personne *p,minimap *m,SDL_Rect camera,int redimensionnement);
void afficherminimap(minimap m,SDL_Surface *screen);
void initialiser_temps(temps *t);
void afficher_temps(temps *t,SDL_Surface *screen);

#endif // HEADER_H_INCLUDED

