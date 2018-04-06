#include "Bouclejeu.h"

//Ajout de sommet
void Boucle::ajoutSommet(Graph g)
{
    if(mouse_b & 1)
    {
        if(mouse_x > 40 && mouse_y > 518 && mouse_x<=100 && mouse_y<=578)
        {

        }
    }
    //g.AjoutArcs();

}

//Suppression de sommet
void Boucle::supprSommet()
{

}

void Boucle::affichage_texte()
{
    //textprintf_ex(screen, font, 400, 23, makecol(255,0,0), -1,"ADD");
}

//Bouton quitter programme
void Boucle::bouton_quitter(int* boob)
{
    if(mouse_b & 1)
    {
        if(mouse_x > 775 && mouse_y > 575 )
        {
            *boob = 1;
        }
    }
}

void Boucle::bouton_save(Graph g,std::string filename)
{
    if (mouse_b & 1)
    {
        if(mouse_x > 90 && mouse_y > 518 && mouse_x<=150 && mouse_y<=578)
        {
         g.save_file(filename);
            std::cout<<"1\n"<<std::endl;
        }
    }
}

void Boucle::Chargement1(Graph g)
{
    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
    g.update();


    /// Mise à jour générale (clavier/souris/buffer etc...)
    grman::mettre_a_jour();
}

void Boucle::Chargement2(Graph g)
{
    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
    g.update();

    /// Mise à jour générale (clavier/souris/buffer etc...)
    grman::mettre_a_jour();
}


void Boucle::Chargement3(Graph g)
{
    /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
    g.update();

    /// Mise à jour générale (clavier/souris/buffer etc...)
    grman::mettre_a_jour();
}

void Boucle::Chargement0(int* choix)
{
    if(mouse_b & 1)
    {
        if(mouse_x > 68 && mouse_y > 353 && mouse_x < 186 && mouse_y < 388 )
        {
            *choix=*choix+1;
        }
    }
}

std::string Boucle::Init_choix()
{
    std::string test="0";
    if(mouse_b & 1)
    {
        if(mouse_x > 270 && mouse_y > 518 && mouse_x <400 && mouse_y < 578 )
        {
            test = "1";
        }

        if(mouse_x > 445 && mouse_y > 518 && mouse_x < 575 && mouse_y < 578 )
        {
            test = "2";
        }

        if(mouse_x >617 && mouse_y > 518 && mouse_x < 742 && mouse_y < 578 )
        {
            test = "3";
        }

        std::cout<<"Test est: "<<test<<std::endl;

    }
    return test;
}

void Boucle::retourMenu(BITMAP *page,BITMAP *decor, int choix, bool boule)
{
    if(mouse_b & 1)
    {
        if(mouse_x > 775 && mouse_y > 510  && mouse_x < 800 && mouse_y < 570)
        {
            blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            boule=true;
            choix=0;
        }
        //return true ;
    }
    //else return false ;
}

std::string Boucle::Menu()
{
    std::string choix="7";
    while (choix != "1" && choix != "2" && choix != "3")
    {
        std::cout<< "Choisir un graphe:"<<std::endl;
        std::cout<<"\n";
        std::cout<<"1. Graphe simple "<<std::endl;
        std::cout<<"2. Graphe maritime "<<std::endl;
        std::cout<<"3. Graphe complex"<<std::endl;
        std::cin>> choix;


    }
    return choix;
}

