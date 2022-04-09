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



void animerEnnemi(ennemi *e)
{
	if(e->num == 2/*|| e->num == 4*/)
	{
		e->num = 0;
	}
	else
	{
		e->num++;
	}
}




int collisionBb(personne p, ennemi e)
{
        if((p.pos.x+p.pos.w < e.pos.x) || (p.pos.x > e.pos.x+e.pos.w) || (p.pos.y+p.pos.h < e.pos.y) || (p.pos.y > e.pos.y+e.pos.h))
	{
		return 0;
	}  
	else
	{
		return 1;
	}

}

/*int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
	if((posp.x+posp.w < pose.x) || (posp.x > pose.x+pose.w) || (posp.y+posp.h < pose.y) || (posp.y > pose.y+pose.h))
	{
		return 0;
	}  
	else
	{
		return 1;
	}
}*/



void updateEnnemi (ennemi* e, personne *p )
{
SDL_Surface * screen;
int d,s1=400,s2=50;
d=e->pos.x-e->pos.y;
switch (e->state)
{
case WAITING : SDL_BlitSurface(e->image[0][0], NULL, screen, &e->pos);
	SDL_Flip(screen);
 SDL_Delay(500);

case FOLLOWING :
// l'ennemi s'anime et se déplace en poursuivant le héro sans attaque
 SDL_BlitSurface(e->image[0][0], NULL, screen, &e->pos);
	SDL_Flip(screen);
 SDL_Delay(500);
SDL_BlitSurface(e->image[0][1], NULL, screen, &e->pos);
	SDL_Flip(screen);
 SDL_Delay(500);
SDL_BlitSurface(e->image[0][2], NULL, screen, &e->pos);
	SDL_Flip(screen);
 SDL_Delay(500);
 do {
 if((e->pos.x <= p->pos.x)) 
 e->pos.x++;
  }while (p->pos.x != e->pos.x);}
/*case Attacking :
// l'ennemi s'anime et se déplace en attaquant le héro
 Animer ennemi(…) // choix des imagettes à partir des 2 dernières lignes
 Déplacer ennemi(…) // sens de déplacement vers le héro

Calculer distance ennemi-héro*/
switch (e->state) {
case WAITING :if (d > s1)
{ e->state = WAITING ;}
else
if( s2 < d <= s1)
 {e->state = FOLLOWING;}
case FOLLOWING :

if (s2 < d <= s1) 
{ e->state = FOLLOWING;}
else
if( 0 < d <= s2)  {  e->state = ATTACKING;} 
case ATTACKING :
if (0 < d <= s2 ) {  e->state = ATTACKING;} 
else
if (d <= 0)
{  e->state = WAITING;}
}}
