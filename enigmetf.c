#include "enigmetf.h"


void InitEnigme(enigmetf *e,char *nomfichier[]){ 
 
	nomfichier[100];

	FILE *fquestion=NULL;
	FILE *freponse=NULL;
	FILE *fvraireponse=NULL;
	
	e->pos_selected=0;
	e->background= IMG_Load("img/background.png");
	e->button= IMG_Load("img/button.png");
	e->button_s= IMG_Load("img/button_s.png");

	TTF_Init();


	SDL_Color couleur = {0,0,0}; 

	(*e).police = TTF_OpenFont("arial.ttf", 20);
	e->police1 = TTF_OpenFont("arial.ttf", 30);
	  
	char questionn[50];
	
	srand(time(NULL)); 
	e->num_question=rand()%3+1; //0,1,2/1,2,3

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%3+1;
	}
	 
	sprintf(*nomfichier,"questions.txt");
	fquestion=fopen(*nomfichier,"r+");
	if(fquestion!=NULL){

		int test=1;
		while (fgets(questionn, 50, fquestion) &&(test!=e->num_question)){ 
			test++;
		}		
		fclose(fquestion);
	}

	char reponse[50];

	int min,max,vrep;
    switch(e->num_question)
    {
    	case 1:
    	{
    		min=1;
    		max=3;

    		 
    		break;
    	}
    	case 2:
    	{
    		min=4;
    		max=6;

    		break;
    	}
    	case 3:
    	{
    		min=7;
    		max=9;

    		break;
    	}
    }

	
	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){
	int testr=0;
	while (fgets((reponse), 50, freponse) &&(testr<max)){	//parcour
			
			if(testr>=min){
				e->reponses[testr-min]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			testr++;
		}
	fclose(fquestion);
	}
	
	fquestion=fopen(*nomfichier,"r+");
	if(fquestion!=NULL){
	int testrv=1;
	while (fgets((reponse), 50, fquestion)){
			
			if(testrv==vrep){ 
				e->reponses[2]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			testrv++;			
		}		
		fclose(fquestion);
	}
	
	


	srand(time(NULL));
	e->positionVraiReponse=rand()%3+1; 

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%3+1;
	}



	e->question = TTF_RenderText_Blended(e->police, questionn, couleur);

	e->pos_question.x=270;
	e->pos_question.y=270;
 
	e->pos_reponse1.x=375;
	e->pos_reponse1.y=522;


	e->pos_reponse2.x=177;
	e->pos_reponse2.y=648;

	e->pos_reponse3.x=566;
	e->pos_reponse3.y=651;

	e->pos_reponse1txt.x=e->pos_reponse1.x+50;
	e->pos_reponse1txt.y=522+30;

	e->pos_reponse2txt.x=177+50;
	e->pos_reponse2txt.y=648+30;

	e->pos_reponse3txt.x=566+50;
	e->pos_reponse3txt.y=651+30;
 
	
	(*e).image_clock=IMG_Load("clock1.png");  

	e->pos_image_clock.x=500;
	e->pos_image_clock.y=100;
	
	e->single_Clock.w=57;
	e->single_Clock.h=81;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;

 

}

void afficherEnigme(enigmetf e,SDL_Surface *ecran){

	
		
	SDL_BlitSurface(e.background, NULL, ecran, NULL);
	SDL_Flip(ecran);
	displayClock(e,ecran);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);
	SDL_Flip(ecran);
	

	switch(e.positionVraiReponse){
		case 1:{

			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);lok
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}	
			break;
		}
		case 2:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		case 3:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	
	SDL_Delay(100);
}

void verify_enigme(enigmetf *e,SDL_Surface*ecran){

	SDL_Rect pos={160,330}; 
	if(e->positionVraiReponse==e->pos_selected)
	{
		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);

	}
	else
	{
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);
	}
	SDL_Delay(2000);

}
void displayClock(enigmetf e,SDL_Surface *ecran){
			
 		SDL_BlitSurface(e.image_clock,&(e.single_Clock), ecran, &e.pos_image_clock);
}
void animer(enigmetf *e){
		 	
	if (e->clock_num >=0 && e->clock_num <8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	}
	
	if ( e->clock_num == 8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num=0;
	}
 
	 
}

void free_Surface_enigme(enigmetf e){

	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.question);
	SDL_FreeSurface(e.reponses[0]);
	SDL_FreeSurface(e.reponses[1]);
	SDL_FreeSurface(e.reponses[2]);
	SDL_FreeSurface(e.button);
	SDL_FreeSurface(e.button_s);
}
