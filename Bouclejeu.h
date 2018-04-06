#ifndef BOUCLEJEU_H_INCLUDED
#define BOUCLEJEU_H_INCLUDED
#include <iostream>
#include "grman.h"
#include "time.h"
#include "Facile1.hpp"

class Boucle
{
private:
public:
    std::string Menu();
    void retourMenu(BITMAP *page,BITMAP *decor, int choix, bool boule);
    std::string Init_choix();
    void Chargement0(int* choix);
    void Chargement1(Graph g);
    void Chargement2(Graph g);
    void Chargement3(Graph g);
    void bouton_save(Graph g, std::string filename);
    void bouton_quitter(int* boob);
    void affichage_texte();
    void supprSommet();
    void ajoutSommet(int* ajout);
};

#endif // BOUCLEJEU_H_INCLUDED
