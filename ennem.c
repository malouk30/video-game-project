#include "ennemi.h"

void initEnnemi(ennemi *e)
{
	int j;
	char ennemiL[30];
	char ennemiR[30];
       
	e->dir = 0;
	e->speed = 2;
	e->num = 0;


	for(j=0 ; j<3 ;j++)
    { 
    	sprintf(ennemiR,"resources/image/R%d.png",j);
    	e->image[0][j] = IMG_Load(ennemiR);
    	sprintf(ennemiL,"resources/image/L%d.png",j);
    	e->image[1][j] = IMG_Load(ennemiL);
	sprintf(ennemiL,"resources/image/lp%d.png",j);
    	e->image[2][j] = IMG_Load(ennemiR);
	sprintf(ennemiL,"resources/image/rp%d.png",j);
    	e->image[3][j] = IMG_Load(ennemiL);
    }

    e->pos.x = 0;
    e->pos.y = 325;
    e->pos.w = e->image[0][0]->w;
    e->pos.h = e->image[0][0]->h;
}



void afficherEnnemi(ennemi e, SDL_Surface *screen)
{
	SDL_BlitSurface(e.image[e.dir][e.num],NULL,screen,&e.pos);

}



void deplacerEnnemi(ennemi *e)
{
	int limDroite =1150;
	int limGauche = 0;

	if(e->dir == 0)
	{
		e->pos.x += e->speed;
	}
	if(e->dir == 1)
	{
		e->pos.x -= e->speed;
	}
	if(e->pos.x > limDroite)
	{
		e->dir = 1;
	}
	if(e->pos.x < limGauche)
	{
		e->dir = 0;
	}
    
}
