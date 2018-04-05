#ifndef FACILE_H
#define FACILE_H

#include <iostream>
#include <stack>
#include <fstream>


#include <vector>
#include <map>
#include <string>
#include <memory>
#include "C:\Users\jerem\Documents\Projet semestre 4\Piscine-master/grman.h"
/*
//Classe du niveau 1-facile
class Facile
{
    private:
    /// Utiliser une top_box de type WidgetBox pour encapsuler
        /// tous les éléments de l'interface associés à votre objet
        grman::WidgetBox m_top_box;
        grman::WidgetImage m_img;  //represente le soleil en haut à gauche
        grman::WidgetEdge m_lien2; // Sera un lien orienté entre la boite à boutons et le clown

        grman::WidgetVSlider m_slider_value;
        grman::WidgetText m_label_value;

        grman::WidgetEdge m_lien1;

    public:
        Facile();
        void update();
        virtual ~Facile();

    protected:


};

*/

class VertexInterface
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Vertex;
    friend class EdgeInterface;
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        // La boite qui contient toute l'interface d'un sommet
        grman::WidgetBox m_top_box;

        // Un slider de visualisation/modification de la valeur du sommet
//        grman::WidgetVSlider m_slider_value;

        // Un label de visualisation de la valeur du sommet
        grman::WidgetText m_label_value;

        // Une image de "remplissage"
        grman::WidgetImage m_img;

        // Un label indiquant l'index du sommet
        grman::WidgetText m_label_idx;
        grman::WidgetText m_croix;
        // Une boite pour le label précédent
        grman::WidgetText m_box_label_idx;



    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        VertexInterface(int idx, int x, int y, std::string pic_name="", int pic_idx=0);
};


class Vertex
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    friend class VertexInterface;
    friend class Edge;
    friend class EdgeInterface;

    private :
        /// liste des indices des arcs arrivant au sommet : accès aux prédécesseurs
        std::vector<int> m_in;

        /// liste des indices des arcs partant du sommet : accès aux successeurs
        std::vector<int> m_out;

        /// un exemple de donnée associée à l'arc, on peut en ajouter d'autres...
        double m_value;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<VertexInterface> m_interface = nullptr;

        // Docu shared_ptr : https://msdn.microsoft.com/fr-fr/library/hh279669.aspx
        // La ligne précédente est en gros équivalent à la ligne suivante :
        // VertexInterface * m_interface = nullptr;


    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Vertex (double value=0, VertexInterface *interface=nullptr) :
            m_value(value), m_interface(interface)  {  }

        /// Vertex étant géré par Graph ce sera la méthode update de graph qui appellera
        /// le pre_update et post_update de Vertex (pas directement la boucle de jeu)
        /// Voir l'implémentation Graph::update dans le .cpp
        void pre_update();
        void post_update();
};



class EdgeInterface
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Edge;
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        // Le WidgetEdge qui "contient" toute l'interface d'un arc
        grman::WidgetEdge m_top_edge;

        // Une boite pour englober les widgets de réglage associés
        grman::WidgetBox m_box_edge;

        // Un slider de visualisation/modification du poids valeur de l'arc
        // grman::WidgetVSlider m_slider_weight;

        // Un label de visualisation du poids de l'arc
        grman::WidgetText m_label_weight;

        //MenuMaxiBestBox
       // grman::WidgetBox m_po


    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        EdgeInterface(Vertex& from, Vertex& to);
};


class Edge
{
    // Les (methodes des) classes amies pourront accéder
    // directement aux attributs (y compris privés)
    friend class Graph;
    friend class EdgeInterface;

    private :
        /// indice du sommet de départ de l'arc
        int m_from;

        /// indice du sommet d'arrivée de l'arc
        int m_to;

        /// un exemple de donnée associée à l'arc, on peut en ajouter d'autres...
        double m_weight;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<EdgeInterface> m_interface = nullptr;


    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Edge (double weight=0, EdgeInterface *interface=nullptr) :
            m_weight(weight), m_interface(interface)  {  }

        /// Edge étant géré par Graph ce sera la méthode update de graph qui appellera
        /// le pre_update et post_update de Edge (pas directement la boucle de jeu)
        /// Voir l'implémentation Graph::update dans le .cpp
        void pre_update();
        void post_update();
};




class GraphInterface
{
    friend class Graph;

    private :

        /// Les widgets de l'interface. N'oubliez pas qu'il ne suffit pas de déclarer
        /// ici un widget pour qu'il apparaisse, il faut aussi le mettre en place et
        /// le paramétrer ( voir l'implémentation du constructeur dans le .cpp )

        /// La boite qui contient toute l'interface d'un graphe
        grman::WidgetBox m_top_box;
        //Ajout et SAVE
        grman::WidgetBox m_ajoumenu;
        grman::WidgetBox m_suppr;
        //MAP1
        grman::WidgetBox m_map1;
        //MAP2
        grman::WidgetBox m_map2;
        //MAP3
        grman::WidgetBox m_map3;
        //Line de séparation
        grman::WidgetBox m_sep;
        //Bouton quitter
        grman::WidgetBox m_quit;
        //Bouton retour
        grman::WidgetBox m_retour;

        grman::WidgetBox m_box_label_idx;

        //TEXTE
        grman::WidgetText m_texteadd;
        grman::WidgetText m_textesave;
        grman::WidgetText m_texte1;
        grman::WidgetText m_texte2;
        grman::WidgetText m_texte3;

        //Technique pour ecriture en descendant
        grman::WidgetText m_B;
        grman::WidgetText m_A;
        grman::WidgetText m_C;
        grman::WidgetText m_K;
        grman::WidgetText m_Q;


        /// Dans cette boite seront ajoutés les (interfaces des) sommets et des arcs...
        grman::WidgetBox m_main_box;

        /// Dans cette boite seront ajoutés des boutons de contrôle etc...
        grman::WidgetBox m_tool_box;


        // A compléter éventuellement par des widgets de décoration ou
        // d'édition (boutons ajouter/enlever ...)

    public :

        // Le constructeur met en place les éléments de l'interface
        // voir l'implémentation dans le .cpp
        GraphInterface(int x, int y, int w, int h);

};


class Graph
{
    private :

        /// La "liste" des arêtes
        std::map<int, Edge> m_edges;

        /// La liste des sommets
        std::map<int, Vertex> m_vertices;

        /// le POINTEUR sur l'interface associée, nullptr -> pas d'interface
        std::shared_ptr<GraphInterface> m_interface = nullptr;

    public:

        /// Les constructeurs sont à compléter selon vos besoin...
        /// Ici on ne donne qu'un seul constructeur qui peut utiliser une interface
        Graph (GraphInterface *interface=nullptr) :
            m_interface(interface)  {  }

        void add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name="", int pic_idx=0 );
        void add_interfaced_edge(int idx, int vert1, int vert2, double weight=0);

        /// Méthode spéciale qui construit un graphe à partir de fichiers.txt
        void make_example();
     //?
        void make_exampleC();   //?


        /// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
        void update();
        void load_file(std::string filename);
        void save_file(std::string filename);
        void make_exampleB();
};



#endif // FACILE_H
