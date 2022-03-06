#ifndef  fonction_H_INCLUDED
#define fonction_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>

typedef struct
{

} enigme;

void afficherEnigme(enigme e, SDL_Surface * screen);
void InitEnigme(enigme * e, char *nomfichier);
void animer (enigme * e);
void sauvegarder (personne p, background b, char * nomfichier);
int charger ( personne * p, background *b , char * nomfichier);

 #endif
