#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#define HAUTEUR 1200
#define LARGEUR 1000
#define CASE 10
#define COLONNE 100

// Le code est encore inconplet Notre equipe T&Q travail dessu pour en délivrer une verssion complete et plus optimiser dans les prochains jours !


int main(int argc, char *argv[])
{

    // on definit notre tableau

    void affiche_2 (int **T , int n1 , int n2);

        int main(void)
        {

                int i, j, n1 = CASE , n2 = COLONNE;
                int **BP = NULL;


        /*
            On alloue d’abord le tableau contenant les pointeurs des lignes (bien voir la taille demandée)
         */
            for (i = 0; i < n1; i++)
            {
                BP = (int * *) malloc(n1 * sizeof(int *));
                if (BP == NULL) // si le malloc ne marche pas
                {
                    puts(" PB1 ");
                    exit(1);
                }

            }
            /*
             Puis, on alloue chaque ligne à la longueur souhaitée
             */

            for (i = 0; i < n1; i++)
            {
                BP[i] = (int *) malloc( n2 * sizeof(int));
                if ( BP[i] == NULL ) // si le malloc ne marche pas
                {
                    printf(" PB2 : i = %d \n", i);
                    exit(1);
                }
            }
            /*
             On regarde les tailles des pointeurs.
             */
            printf( " sizeof de  BP : %lu \n", sizeof(BP));
            printf( " sizeof de *BP : %lu \n", sizeof(*BP));
            puts("\n");


            /*
             On peut donc alors remplir le tableau
             */
            for(i = 0; i < n1; i++)
            {
                for (j = 0; j < n2; j++)
                {
                    BP[i][j] = 0;
                }
            }

            affiche_2 (BP , n1 , n2);

            /*
              libérer la mémoire le plus tôt possible i.e. ne pas attendre la fin du programme. On le fait dans l’ordre inverse de celui de l’allocation.
             */
            for (i = 0; i < n1; i++)
                free(BP[i]);
            free(BP);
            puts(" =============================================== \n");

        }




    SDL_Event event;
    int continuer = 1;



    SDL_Init(SDL_INIT_VIDEO);

   // Creation de la fenetre de jeux


    SDL_Surface *fenetrejeux=NULL;

    fenetrejeux=SDL_SetVideoMode(1200, 1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);



    // On définit le Sol de la map a l'aide d'une image de sol ( nous voulions definir la map en entier a l'aide de logiciel
    // comme Tiled mais nous nous sommes dit qu'il serait peut etre plus interessant de n'utiliser cette methode que sur le sol
    // afin de mieu pouvoir travailler sur le reste du décor .

    SDL_Surface *Map;
    Map=IMG_Load("SolMap.png");
    SDL_Rect MapPosition;
    MapPosition.x=0;
    MapPosition.y=0;



    SDL_BlitSurface(Map,NULL,fenetrejeux,&MapPosition);
    SDL_Flip(fenetrejeux);

    //on s'occupe de Blit une premiere fois les que nous "reblirerons" dans la boucle while bariere

    SDL_Surface *bariere;
    bariere=IMG_Load("bariere.png");
    SDL_Rect barierePosition;
    barierePosition.x=50;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=145;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=250;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=370;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=810;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=710;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=910;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=1020;
    barierePosition.y=180;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=170;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=270;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=370;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=470;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=570;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=670;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    barierePosition.x=770;
    barierePosition.y=770;

    SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
    SDL_Flip(fenetrejeux);

    //croix du milieu

    SDL_Surface *croix;
    croix=IMG_Load("croix_mid.png");
    SDL_Rect croixPosition;
    croixPosition.x=520;
    croixPosition.y=470;

    SDL_BlitSurface(croix,NULL,fenetrejeux,&croixPosition);
    SDL_Flip(fenetrejeux);

    //casque deco

    SDL_Surface *casque;
    casque=IMG_Load("casque.png");
    SDL_Rect casquePosition;
    casquePosition.x=975;
    casquePosition.y=310;

    SDL_BlitSurface(casque,NULL,fenetrejeux,&casquePosition);
    SDL_Flip(fenetrejeux);

    SDL_Surface *tour_2;
    tour_2=IMG_Load("t2.png");
    SDL_Rect tour_2Position;
    tour_2Position.x=0;
    tour_2Position.y=0;

    SDL_BlitSurface(tour_2,NULL,fenetrejeux,&tour_2Position);
    SDL_Flip(fenetrejeux);


    //tente deco

    SDL_Surface *tente;
    tente=IMG_Load("tente_1.png");
    SDL_Rect tentePosition;
    tentePosition.x=1000;
    tentePosition.y=200;

    SDL_BlitSurface(tente,NULL,fenetrejeux,&tentePosition);

    SDL_Flip(fenetrejeux);


    //pillier deco

    SDL_Surface *pilier;
    pilier=IMG_Load("pilier.png");
    SDL_Rect pilierPosition;
    pilierPosition.x=625;
    pilierPosition.y=545;

    SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
    pilierPosition.x=625;
    pilierPosition.y=450;

    SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
    pilierPosition.x=500;
    pilierPosition.y=545;

    SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
    pilierPosition.x=500;
    pilierPosition.y=450;

    SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
    SDL_Flip(fenetrejeux);


    //arbre


    SDL_Surface *arbre;
    arbre=IMG_Load("arbre_1.png");
    SDL_Rect arbrePosition;
    arbrePosition.x=340;
    arbrePosition.y=570;

    SDL_BlitSurface(arbre,NULL,fenetrejeux,&arbrePosition);
    SDL_Flip(fenetrejeux);

    SDL_Surface *arbre2;
    arbre2=IMG_Load("arbre_2.png");
    SDL_Rect arbre2Position;
    arbre2Position.x=200;
    arbre2Position.y=400;

    SDL_BlitSurface(arbre2,NULL,fenetrejeux,&arbre2Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *arbre3;
    arbre3=IMG_Load("arbre_3.png");
    SDL_Rect arbre3Position;
    arbre3Position.x=720;
    arbre3Position.y=650;

    SDL_BlitSurface(arbre3,NULL,fenetrejeux,&arbre3Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *arbre4;
    arbre4=IMG_Load("arbre_4.png");
    SDL_Rect arbre4Position;
    arbre4Position.x=910;
    arbre4Position.y=490;

    SDL_BlitSurface(arbre4,NULL,fenetrejeux,&arbre4Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *arbre5;
    arbre5=IMG_Load("arbre_5.png");
    SDL_Rect arbre5Position;
    arbre5Position.x=720;
    arbre5Position.y=370;

    SDL_BlitSurface(arbre5,NULL,fenetrejeux,&arbre5Position);
    SDL_Flip(fenetrejeux);


    // mur et porte et garde


    SDL_Surface *porte;
    porte=IMG_Load("porte_1.jpg");
    SDL_Rect portePosition;
    portePosition.x=500;
    portePosition.y=19;

    SDL_BlitSurface(porte,NULL,fenetrejeux,&portePosition);
    portePosition.x=562;
    portePosition.y=19;

    SDL_BlitSurface(porte,NULL,fenetrejeux,&portePosition);
    SDL_Flip(fenetrejeux);


    SDL_Surface *mur;
    mur=IMG_Load("mur_1.jpg");
    SDL_Rect murPosition;
    murPosition.x=453;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=624;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=670;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=716;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=762;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=808;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=854;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=900;
    murPosition.y=0;


    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=946;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=992;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=1038;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=407;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=361;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=315;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=269;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=223;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=177;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=131;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=85;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
     murPosition.x=1082;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
    murPosition.x=39;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=1110;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    murPosition.x=1140;
    murPosition.y=0;

    SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

    SDL_Flip(fenetrejeux);

//mur arrière


SDL_Surface *murar;
    murar=IMG_Load("murchateau4.jpg");
    SDL_Rect murarPosition;
    murarPosition.x=620;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=570;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=530;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=470;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=430;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=400;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=380;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=350;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=300;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=250;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=190;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=130;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=70;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=30;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=2;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=680;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=720;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=750;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=860;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=920;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=800;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=950;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=1000;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=1050;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=1100;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    murarPosition.x=1150;
    murarPosition.y=940;

    SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
    SDL_Flip(fenetrejeux);




    //tour

    SDL_Surface *tour;
    tour=IMG_Load("tower_1.png");
    SDL_Rect tourPosition;
    tourPosition.x=1080;
    tourPosition.y=0;


    SDL_BlitSurface(tour,NULL,fenetrejeux,&tourPosition);
    SDL_Flip(fenetrejeux);


    // mur coté droit et gauche


        SDL_Surface *couloir;
    couloir=IMG_Load("couloir.jpg");
    SDL_Rect couloirPosition;
    couloirPosition.x=4;
    couloirPosition.y=450;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=400;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=350;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=300;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=250;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=200;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=150;





    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=500;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=550;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=600;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=650;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=700;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=750;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=800;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=850;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=4;
    couloirPosition.y=900;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=450;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=400;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=350;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=300;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=250;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=200;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=150;




    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=500;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=550;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=600;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=650;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=700;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=750;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=800;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=850;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=900;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    couloirPosition.x=1168;
    couloirPosition.y=450;


    SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
    SDL_Flip(fenetrejeux);



     //le public de l'arene:


    SDL_Surface *public_dos;
    public_dos=IMG_Load("publiquedos1.png");
    SDL_Rect public_dosPosition;
    public_dosPosition.x=205;
    public_dosPosition.y=840;

    SDL_BlitSurface(public_dos,NULL,fenetrejeux,&public_dosPosition);

    public_dosPosition.x=705;
    SDL_BlitSurface(public_dos,NULL,fenetrejeux,&public_dosPosition);
    SDL_Flip(fenetrejeux);

    SDL_Surface *public_dos2;
    public_dos2=IMG_Load("publiquedos2.png");
    SDL_Rect public_dos2Position;
    public_dos2Position.x=375;
    public_dos2Position.y=840;


    SDL_BlitSurface(public_dos2,NULL,fenetrejeux,&public_dos2Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *public_dos3;
    public_dos3=IMG_Load("publiquedos3.png");
    SDL_Rect public_dos3Position;
    public_dos3Position.x=525;
    public_dos3Position.y=840;


    SDL_BlitSurface(public_dos3,NULL,fenetrejeux,&public_dos3Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *public_face1;
    public_face1=IMG_Load("publiqueface1.png");
    SDL_Rect public_face1Position;
    public_face1Position.x=75;
    public_face1Position.y=100;

    SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
    public_face1Position.x=260;
    public_face1Position.y=100;
    SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
    public_face1Position.x=760;
    public_face1Position.y=140;
    SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *public_face2;
    public_face2=IMG_Load("publiqueface2.png");
    SDL_Rect public_face2Position;
    public_face2Position.x=865;
    public_face2Position.y=100;

    SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
    public_face2Position.x=665;
    SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
    public_face2Position.x=155;
    public_face2Position.y=140;

    SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
    SDL_Flip(fenetrejeux);

    //chevalier ( garde )

    SDL_Surface *cheva;
    cheva=IMG_Load("cheva_1.png");
    SDL_Rect chevaPosition;
    chevaPosition.x=525;
    chevaPosition.y=70;

    SDL_BlitSurface(cheva,NULL,fenetrejeux,&chevaPosition);
    SDL_Flip(fenetrejeux);

    SDL_Surface *cheva2;
    cheva2=IMG_Load("cheva_2.png");
    SDL_Rect cheva2Position;
    cheva2Position.x=1110;
    cheva2Position.y=300;

    SDL_BlitSurface(cheva2,NULL,fenetrejeux,&cheva2Position);
    SDL_Flip(fenetrejeux);

    SDL_Surface *buisson;
    buisson=IMG_Load("buisson.png");
    SDL_Rect buissonPosition;
    buissonPosition.x=410;
    buissonPosition.y=150;

    SDL_BlitSurface(buisson,NULL,fenetrejeux,&buissonPosition);
    buissonPosition.x=580;
    buissonPosition.y=150;

    SDL_BlitSurface(buisson,NULL,fenetrejeux,&buissonPosition);
    SDL_Flip(fenetrejeux);


    //le personnage du jeux (celui qui se deplace)


    int n=100;
    int p=100;

    SDL_Surface *Bob;
    Bob=IMG_Load("bob.png");
    SDL_Rect BobPosition;
    BobPosition.x=n;
    BobPosition.y=p;

    SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);
    SDL_Flip(fenetrejeux);









    SDL_EnableKeyRepeat(10,10);




    while(continuer)
    {

        SDL_PollEvent(&event);

        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        case SDL_KEYDOWN:

            // switch pour gérer le deplacement avec les fleches du clavier
            switch(event.key.keysym.sym)
            {

            case SDLK_UP:
                BobPosition.y-=10;
                SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);
                SDL_WaitEvent(&event);
                SDL_Flip(fenetrejeux);

                break;
            case SDLK_DOWN:
                BobPosition.y+=10;
                SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);
                SDL_WaitEvent(&event);
                SDL_Flip(fenetrejeux);

                break;
            case SDLK_RIGHT:
                BobPosition.x+=10;
                SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);
                SDL_WaitEvent(&event);
                SDL_Flip(fenetrejeux);

                break;
            case SDLK_LEFT:
                BobPosition.x-=20;
                SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);
                SDL_WaitEvent(&event);
                SDL_Flip(fenetrejeux);




                break;




            }





        }

            // Voici le " hic " du code, en effet au lieu de configurer une map et de la "blitter" dans la boucle du fait que nous avons blitter
            // la plupart des élements pour les positionner sur la fenetre nous devons les "rebliter" ici ce qui rend le code assez lourd mais les repercution
            // ne se voit pas meme si la methode utiliser reste un peu bancale.

            SDL_FillRect(fenetrejeux,NULL,SDL_MapRGB(fenetrejeux->format,0,0,0));


                            SDL_BlitSurface(Map,NULL,fenetrejeux,&MapPosition);


                             barierePosition.x=50;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=145;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=250;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=370;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=810;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=710;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=910;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=1020;
                            barierePosition.y=180;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=170;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=270;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=370;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=470;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=570;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=670;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            barierePosition.x=770;
                            barierePosition.y=770;

                            SDL_BlitSurface(bariere,NULL,fenetrejeux,&barierePosition);
                            SDL_BlitSurface(casque,NULL,fenetrejeux,&casquePosition);
                            SDL_BlitSurface(tour_2,NULL,fenetrejeux,&tour_2Position);






                            SDL_BlitSurface(croix,NULL,fenetrejeux,&croixPosition);

                            SDL_BlitSurface(tente,NULL,fenetrejeux,&tentePosition);

                            pilierPosition.x=625;
                            pilierPosition.y=545;
                            SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
                            pilierPosition.x=625;
                            pilierPosition.y=450;

                            SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
                            pilierPosition.x=500;
                            pilierPosition.y=545;

                            SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
                            pilierPosition.x=500;
                            pilierPosition.y=450;

                            SDL_BlitSurface(pilier,NULL,fenetrejeux,&pilierPosition);
                            SDL_BlitSurface(arbre,NULL,fenetrejeux,&arbrePosition);
                            SDL_BlitSurface(arbre2,NULL,fenetrejeux,&arbre2Position);
                            SDL_BlitSurface(arbre3,NULL,fenetrejeux,&arbre3Position);
                            SDL_BlitSurface(arbre4,NULL,fenetrejeux,&arbre4Position);
                            SDL_BlitSurface(arbre5,NULL,fenetrejeux,&arbre5Position);

                            portePosition.x=500;
                            portePosition.y=19;

                            SDL_BlitSurface(porte,NULL,fenetrejeux,&portePosition);
                            portePosition.x=562;
                            portePosition.y=19;

                            SDL_BlitSurface(porte,NULL,fenetrejeux,&portePosition);

                            murPosition.x=453;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=624;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=670;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=716;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=762;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=808;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=854;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=900;
                                murPosition.y=0;


                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=946;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=992;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=1038;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=407;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=361;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=315;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=269;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=223;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=177;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=131;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=85;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                 murPosition.x=1082;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);
                                murPosition.x=39;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=1110;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);

                                murPosition.x=1140;
                                murPosition.y=0;

                                SDL_BlitSurface(mur,NULL,fenetrejeux,&murPosition);



                            murarPosition.x=620;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=570;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=530;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=470;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=430;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=400;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=380;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=350;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=300;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=250;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=190;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=130;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=70;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=30;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=2;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=680;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=720;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=750;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=860;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=920;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=800;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=950;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=1000;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=1050;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=1100;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);
                                murarPosition.x=1150;
                                murarPosition.y=940;

                                SDL_BlitSurface(murar,NULL,fenetrejeux,&murarPosition);


                             SDL_BlitSurface(tour,NULL,fenetrejeux,&tourPosition);
                            couloirPosition.x=4;
                                couloirPosition.y=450;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=400;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=350;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=300;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=250;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=200;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=150;





                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=500;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=550;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=600;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=650;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=700;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=750;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=800;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=850;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=4;
                                couloirPosition.y=900;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=450;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=400;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=350;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=300;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=250;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=200;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=150;




                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=500;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=550;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=600;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=650;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=700;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=750;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=800;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=850;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=900;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                                couloirPosition.x=1168;
                                couloirPosition.y=450;


                                SDL_BlitSurface(couloir,NULL,fenetrejeux,&couloirPosition);
                            public_dosPosition.x=205;
                                public_dosPosition.y=840;

                                SDL_BlitSurface(public_dos,NULL,fenetrejeux,&public_dosPosition);

                                public_dosPosition.x=705;
                                SDL_BlitSurface(public_dos,NULL,fenetrejeux,&public_dosPosition);
                            SDL_BlitSurface(public_dos2,NULL,fenetrejeux,&public_dos2Position);
                            SDL_BlitSurface(public_dos3,NULL,fenetrejeux,&public_dos3Position);
                            public_face1Position.x=75;
                                public_face1Position.y=100;

                                SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
                                public_face1Position.x=260;
                                public_face1Position.y=100;
                                SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
                                public_face1Position.x=760;
                                public_face1Position.y=140;
                                SDL_BlitSurface(public_face1,NULL,fenetrejeux,&public_face1Position);
                                public_face2Position.x=865;
                                public_face2Position.y=100;

                                SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
                                public_face2Position.x=665;
                                SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
                                public_face2Position.x=155;
                                public_face2Position.y=140;

                                SDL_BlitSurface(public_face2,NULL,fenetrejeux,&public_face2Position);
                                SDL_BlitSurface(cheva,NULL,fenetrejeux,&chevaPosition);
                                SDL_BlitSurface(cheva2,NULL,fenetrejeux,&cheva2Position);
                                buissonPosition.x=410;
                                buissonPosition.y=150;

                                SDL_BlitSurface(buisson,NULL,fenetrejeux,&buissonPosition);
                                buissonPosition.x=580;
                                buissonPosition.y=150;

                                SDL_BlitSurface(buisson,NULL,fenetrejeux,&buissonPosition);



                                SDL_BlitSurface(Bob,NULL,fenetrejeux,&BobPosition);

                                if(n = 1000)
                                {
                                    n=900;
                                }
                                SDL_Flip(fenetrejeux);








        }




 SDL_Quit();

}



// fonction pour afficher notre tableau


void affiche_2 (int **T, int n1, int n2)
{
    int i, j = 0;
    puts("\n");
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; i++)
        {
            printf(" %d \n", T[i][j]);
        }
    }
    puts("\n");
}






