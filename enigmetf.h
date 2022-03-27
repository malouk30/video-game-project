#ifndef enigmetf_h_INCLUDED
#define enigmetf_h_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SOL_image.h>
#include <SDL/SOL_ttf.h>
#include <time_h>

typedef struct{
SDL_Surface *background; // le background sur lequel je vais afficher la question et les reponses
SDL_Surface *question; // la surface sur laquelle je vais afficher la question
SDL_Surface *reponses[4]; // la surface sur laquelle je vais afficher les reponses
SDL_Surface *button; // le boutton sur lequel je vais cliquer
SDL_Surface *button_s; // boutton selectionné

int pos_selected; // 1 2 3
SDL_Rect pos_question; // position de 1a question
SDL_Rect pos_reponse1; // positton de la reponse
SDL_Rect pos_reponse2;     //        //
SDL_Rect pos_reponse3;    //        //
int num_question; //  1 2 3 
 
SDL_Rect pos_reponseltxt; // la pos du txt que je vais mettre sur l img de la rep
SDL_Rect pos_reponse2txt;         //        //
SDL_Rect pos_reponse3txt;       
int vrat_reponse; // 1 2 3
int positionVraiReponse; // la pos de la vraie rep ( pos du txt et img )
TF_Font *police;
TTF_Font *police1;

} entgmetf;
void InitEnigme (enigmetf *e, char *nomfichter[] );
void afficherEnigme (enigmetf e, SDL_Surface *ecran);
void verify_enigme (enigmetf *e, SDL_Surface*ecran);
void animer (enigmetf *e);
void free_Surface_entgme (enigmetf e);

 #endif
 
