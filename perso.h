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
