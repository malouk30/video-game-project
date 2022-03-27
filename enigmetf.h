#ifndef enigmetf_h_INCLUDED
#define enigmetf_h_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL. h>
#include <SDL/SOL_image. h>
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
void free_Surface_entgme (entgmetf e);

 #endif
 typedef struct
{
    int status,num,dr,vi;
    float x,y;
    float vx,vy;
 SDL_Rect posperso,vie;
SDL_Surface *tab[20],*tabvie[3]; 
 int fig;
    int dep,acc,vitesse;
    int vieper;
} personne;
typedef enum STATE STATE;
enum STATE{WAITING,FOLLOWING,ATTACKING,ESCAPING};



typedef struct
{
SDL_Rect position_miniknight;

SDL_Surface *sprite;
}miniknight;

typedef struct
{
SDL_Rect position_mini;

SDL_Surface *sprite;
}minimap;

typedef struct temps
{
SDL_Surface *texte;
SDL_Rect position;
  
TTF_Font *police ;

char entree[20];
SDL_Color couleurBlanche,couleurNoire ;
int tempsActuel,tempsPrecedent;
int min,cmp;
}temps;



//************personnage***************
void initperso(personne* p);
void Miseajour(personne* p,SDL_Surface* screen);
void afficherperso(personne* p,SDL_Surface *ecran);
void deplacerperso(personne *p);
void Saute(personne* p,float impulsion);
void ControleSol(personne* p);
void Gravite(personne* p,float factgravite,float factsautmaintenu,Uint8* keys);
void animerperso(personne* p);
void Updateperso(personne* p,Uint8* keys);
void Updateperso1(personne* p1,Uint8* keys);


