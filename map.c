#include "header.h"

void initminimap(map *m,SDL_Surface *screen)
{
m->map=IMG_Load("mini_backgg.png");
m->pos_map.x =1050;
m->pos_map.y =50;
m->mini_perso=IMG_Load("hero.png");
m->perso_pos_map.x=m->perso_pos_map.x/10+m->pos_map.x;
m->perso_pos_map.y=m->perso_pos_map.y/10+55+m->pos_map.y;
}

void MAJminimap(map * m,SDL_Rect camera,int redimensionnement)
{
if (camera.x==0)
  m->perso_pos_map.x += redimensionnement;

  if (camera.x==1)
  m->perso_pos_map.x -= redimensionnement;

  if (camera.x==2)
  m->perso_pos_map.y += redimensionnement;

  if (camera.x==3)
  m->perso_pos_map.y -= redimensionnement;
}

void afficherminimap(map *m,SDL_Surface *screen)
{
SDL_BlitSurface(m->map,NULL,screen,&m->pos_map);
SDL_BlitSurface(m->mini_perso,NULL,screen,&m->perso_pos_map);
}

void sauvegarde_score(int score)
{
FILE *fichier=NULL;
fichier=fopen("fichier.txt","a+");
fprintf(fichier,"%d \n",score);
fclose(fichier);
}

void sauvegarde_nom (char nom[20])
{
FILE *fichier=NULL;
fichier=fopen("fichier.txt","a+");
fprintf(fichier,"%s",nom);
fclose(fichier);
}

int score()
{
	int score,best=0;
	char nom[20];
	FILE* fichier=NULL;
	fichier=fopen("fichier.txt","r");
	while(score>best)
	{
		fscanf(fichier,"%s %d \n",nom,&score);
	}
	return best;
}

void Timer(int *tempsdebut)
{
   if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
    }
}

void inittemps(Time *t)
{   int test; 
	t->tempsdebut=SDL_GetTicks();
	t->mm=0;
	t->ss=0;
	test=initTexttime(&t->temps);
}

int initTexttime(Text* T)
{ int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    strcpy(T->txt, "");
    T->positionText.x = 1100;
    T->positionText.y = 10; 
    testload=loadFonttime(T,"avocado.ttf");
    T->textSurface=NULL;
    return testload;   
}

int loadFonttime(Text* T, char* path)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,30);
    return (0);
}

void update_time(Time* T)
{   int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<=10&&T->ss<=9)
       sprintf(T->temps.txt,"temps: 0%.1d: 0%.1d",T->mm,T->ss);
    else if(T->mm<=10&&T->ss>=9)
        sprintf(T->temps.txt,"temps: 0%.1d: %.1d",T->mm,T->ss);
    else if(T->mm>=10&&T->ss<=9)
          sprintf(T->temps.txt,"temps: %.1d: 0%.1d",T->mm,T->ss);
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
}

void displaytime(Time T,SDL_Surface *screen)
{
     SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));
}


