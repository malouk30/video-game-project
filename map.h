#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{
    SDL_Surface *map;
	SDL_Rect pos_map;
}minimap;

typedef struct
{
	SDL_Rect pos_perso;
	SDL_Surface *perso;
} Personne;

void initmap(minimap *m);
void majminimap(Personne *p,minimap *m,SDL_Rect camera,int redimensionnement);
void afficherminimap(minimap m,SDL_Surface *screen);

#endif // HEADER_H_INCLUDED
