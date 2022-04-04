#include "enigmetf.h"
void init_enigme( enigme *e ,char *nomfichier)
{
   e->background= IMG_Load("img/background.png") ;

	TTF_Init( ) ;
	SDL_Color couleur = {0,0,0};

(*e) . police = TTF_OpenFont("arial. ttf", 30);

   FILE *fquestion=NULL;
    e->question = NULL;
    e->pos_question.x=200;
    e->pos_question.y=250;
    
e->police1 = TTF_OpenFont("arial. ttf", 20);

   FILE *freponse=NULL;
    e->pos_reponse_1.x=200;
    e->pos_reponse_1.y=500;
    e->reponse_2 = NULL;
    e->pos_reponse_2.x=450;
    e->pos_reponse_2.y=500;
    e->reponse_3 =NULL;
    e->pos_reponse_3.x=700;
    e->pos_reponse_3.y=500;

    e->alea = 0;

    e->youwin =IMG_Load("img/youwin.png");
    e->youlost =IMG_Load("img/youlost.png");
    e->position_youwin.x = 170;
    e->position_youwin.y = 255;
    e->position_youlost.x = 240;
    e->position_youlost.y = 255;
}

void blit_enigme ( enigme e, SDL_Surface* screen)
{
        SDL_BlitSurface(en->question,NULL,screen,&en->pos_question);
        SDL_BlitSurface(en->reponse_1,NULL,screen,&en->pos_reponse_1);
        SDL_BlitSurface(en->reponse_2,NULL,screen,&en->pos_reponse_2);
        SDL_BlitSurface(en->reponse_3,NULL,screen,&en->pos_reponse_3);

}

void free_enigme( enigme *e)
{
    SDL_FreeSurface(e->question);
    SDL_FreeSurface(e->reponse_1);
    SDL_FreeSurface(e->reponse_2);
    SDL_FreeSurface(e->reponse_3);
    SDL_FreeSurface(e->youwin);
    SDL_FreeSurface(e->youlost);
    TTF_CloseFont(e->police);
    TTF_CloseFont(e->police1);
}

void alea_enigme(enigme *e)
{
	char ques[20] = {0};
	char rep1[10] = {0};
	char rep2[10] = {0};
	char rep3[10] = {0};
int c_question;
int c_reponses;
int ligne_quest =1;
int ligne_rep=1;
	srand(time(NULL));
	do {
		e->alea = rand()%3 ;
	}while ((e->alea >=1)&&(e->alea <4));

	freponse=fopen( "reponses. txt", "r+");
	fquestion = fopen("question.txt","r+"); 
	if ( freponse!=NULL )
	{
		while (ligne_quest < e->alea)
		{
			c_question = fgetc(fquestion);
			if ( c_question == '\n')
				ligne_quest++;
		}
		fgets(question,20,fquestion);
		fclose(fquestion);

		while ( ligne_reponse < e->alea )
		{
			c_reponses = fgetc(freponse);
			if ( c_reponses == '\n')
				ligne_reponse++;
		}
		fscanf(freponse,"%s %s %s",rep1,rep2,rep3);
		fclose(freponse);
	}
                 e->question     = TTF_RenderText_Blended(e->police,ques,Color);
	e->reponse_1 = TTF_RenderText_Blended(e->police1,rep1,Color);
	e->reponse_2 = TTF_RenderText_Blended(e->police1,rep2,Color);
	e->reponse_3 = TTF_RenderText_Blended(e->police1,rep3,Color);
}
SDL_Delay(100);
}
