#ifndef enigmetf_h_INCLUDED
#define enigmetf_h_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SOL_image.h>
#include <SDL/SOL_ttf.h>
#include <time_h>

typedef struct
{
	int resultat;
	SDL_Surface *youwin,*youlost;
	SDL_Rect position_youwin,position_youlost;

	TTF_Font *police,*police1;
	SDL_Surface *reponse_1,*reponse_2,*reponse_3,*question;
	SDL_Rect  pos_reponse_1,pos_reponse_2,pos_reponse_3,pos_question;
	int alea;
	
}enigmetf;


void alea_enigme(enigme *e);
void init_enigme( enigme *e,char *nomfichier);
void blit_enigme( enigme *e, SDL_Surface* screen);
void free_enigme( enigme *e);

 #endif
 
