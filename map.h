#ifndef header_H_INCLUDED
#define header_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
	SDL_Surface *map;
	SDL_Rect pos_map;
	SDL_Surface *mini_perso;
	SDL_Rect perso_pos_map;
}map;

typedef struct
{
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
}Text;

typedef struct time
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
} Time;


void initminimap(map *m,SDL_Surface *screen);
void MAJminimap(map *m,SDL_Rect camera,int redimensionnement);
void afficherminimap(map *m,SDL_Surface *screen);
void sauvegarde_score(int score);
void sauvegarde_nom (char nom[]);
int score();
void inittemps(Time *t);
void Timer(int *tempsdebut);
int initTexttime(Text* T);
int loadFonttime(Text* T, char* angelina);
void update_time(Time* T);
void displaytime(Time T,SDL_Surface *screen);

#endif
