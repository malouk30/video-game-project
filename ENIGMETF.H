#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED
#include <stato- hz
#include <stdlib.h>
#include <SDL/SDL. h>
#include <SDL/SOL_image. h>
#include <SDL/SOL_ttf.h>
#include <time_h>

typedef struct{
SDL_Surface *background; // 1 background alt besh nafficher fiha l question o les reponses
ali besh nafficher feha l question
source question: //l surface
s[4]://1 surface ali besh nafficher feha les reponses
SDL_Surface *button; //
i button all besh nenzl alth
SDL_Surface *button_s;

int pos_selected; / / 1 2 3
SDL_Rect pos_question; / /
position mta3 1 question
DL_Rect pos_reponse1; /
ositton mta3 Lreponse
SDL_Rect pos_reponse2; / / l position mta3 1 reponse
SDL_Rect pos_reponse3; // 1 position mta3 1 reponse
int num_question; / /

SDL_Rect pos_reponseltxt; / / 1 position mita3 1 txt all besh nhoto fouk L image ta3 1 reponse
SDL_Rect pos_reponse2txt; /
1 position mta3 1 txt ali besh nhoto fouk L image ta3 1 reponse
SDL_Rect pos_reponse3txt; / /
position mta3 1 txt ali besh nhoto fouk l image ta3 1 reponse
int vrat_reponse; // 1 reponse I s717a yam loula wala 1 thenya wala I theltha
int positionVraiReponse; // 1 position mta3 1 reponse I s717a o ali heya l position mta3 1 image wel texte
TF_Font *police;
TTF_Font *police1;

Jentgmetf;
void InitEnigma(enigmatf *e, char *nomfichter[] );
Word atTicherEntgme (enigmatf e, SDL_Surface *ecran);
void verify_entgme(enigmatf *e, SDL_Surface*ecran);
void animer (entgmetf *e);
void free_Surface_entgme(entgmetf e);

 #endif
