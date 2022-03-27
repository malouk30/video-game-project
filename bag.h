#ifndef MENU_H_
#define MENU_H_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1366
#define SCREEN_H 678
//partage d'ecran
//ecran_2
#define SCREEN_W2 683
#define SCREEN_H2 678
typedef struct
{
	SDL_Surface *imgback;
	SDL_Rect posback;
	SDL_Rect camera;
	SDL_Rect camera2;
	Mix_Music *son;
}background;


void initBack (background *b);
void initBack2 (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void afficheBack2 (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
#endif /* MENU_H_ */
