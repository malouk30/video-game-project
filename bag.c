#include "background.h"


void initBack (background *b)
{
//background
b->imgback=IMG_Load("bg.jpg");
b->posback.x=0;
b->posback.y=0;
//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W; 
b->camera.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("son.mp3"); //Chargement de la musique
Mix_PlayMusic(b->son, -1); //Jouer infiniment la musique
}


void initBack2 (background *b)
{
//background2
b->imgback=IMG_Load("bg2.jpg");
b->posback.x=0;
b->posback.y=0;
//camera2
b->camera2.x=0;
b->camera2.y=0;
b->camera2.w=SCREEN_W2; 
b->camera2.h=SCREEN_H2;
//musique
b->son=Mix_LoadMUS("son.mp3"); //Chargement de la musique
Mix_PlayMusic(b->son, -1); //Jouer infiniment la musique
}




void afficheBack (background b, SDL_Surface *ecran)
{
/* On blitte par-dessus l'écran */
SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack2 (background b, SDL_Surface *ecran)
{
/* On blitte par-dessus l'écran */
SDL_BlitSurface(b.imgback,&b.camera2,ecran,&b.posback);
}

void scrolling (background *b,int direction)
{
const int speed=6;
if (direction ==0)
        b->camera.x+=speed;
else if (direction ==1)
        b->camera.x-=speed;
else if (direction ==2)
        b->camera.y+=speed;
else if (direction ==3)
        b->camera.y-=speed;
else if (direction ==4)
        b->camera2.x+=speed;
else if (direction ==7)
        b->camera2.x-=speed;
else if (direction ==8)
        b->camera2.y+=speed;
else if (direction ==9)
        b->camera2.y-=speed;

}
