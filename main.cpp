#include <iostream>
#include "grman.h"

#include "Facile.h"
#include "Bouclejeu.h"

using namespace std;


int main()
{
    // A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    //Déclaration de variables
    int ajout=0;
    int debut = 0;
    int boob =0;
    std::string choix;
    bool boule=true;

    //Bitmap de fond menu
      BITMAP *page;
      BITMAP *decor;

    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    // charger images de fond/menu
    decor=load_bitmap("pics/Topological.bmp",NULL);
    if (!decor)
    {
        allegro_message("n'a pas pu trouver topological.bmp");
        exit(EXIT_FAILURE);
    }

     ///MENU CONSOLE
    std::ifstream fichier("titre.txt", std::ios::in);
    if(fichier)
    {
        std::string contenu;
        for(int i=0 ; i<20 ; i++)
        {
            getline(fichier,contenu);
            std::cout<<contenu<<std::endl;
        }
    }

    Boucle b;

    choix=b.Menu();
    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    ///Graphe niveau 1 (simple)
    Graph g;
    g.make_example();
    ///Graphe niveau 2 (moyen)
    Graph x;
    //x.make_exampleB();
     ///Graphe niveau 3 (difficile)
    Graph y;
    //y.make_exampleC();

    ///BOUCLE DE JEU
      while ( !key[KEY_ESC] &&  (boob !=1) )
    {
            //Boucle de Presentation
            while( (!key[KEY_ENTER]) && (debut !=1))
            {
                // effacer buffer en appliquant décor
                blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);
                blit (page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            }

            //Condition pour quitter la boucle de presentation
            debut = 1;

            //Initialisation de choix

            //std::cout<<"Choix vaut desormais: "<<choix<<std::endl;
            //Choix parmis les 3 graphes
            if((mouse_b & 1) && (mouse_y > 530) && (mouse_x > 270))
                choix = b.Init_choix();

           if(choix=="1")
            {
                b.Chargement1(g);
            }
            if(choix=="2")
            {
                std::cout<<"menu deux"<<std::endl;
                //b.Chargement2(x);
            }
            if(choix=="3")
            {
                std::cout<<"menu trois"<<std::endl;
                //b.Chargement3(y);

            }


            /*if(choix==0);
            {
                Chargement0(&choix);
            }*/

            //Ajout de composantes
            b.ajoutSommet(&ajout);

            //RETOUR
           // retourMenu(page,decor,,choix);

            //SAVE
            b.bouton_save(g);

            //Suppression de composantes

            //Conditions de fermeture de l'utilisateur
            b.bouton_quitter(&boob);
    }
    grman::fermer_allegro();

return 0;

}

END_OF_MAIN();
