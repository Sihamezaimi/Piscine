#include "Facile.h"
#include "sstream"
#include <fstream>
#include <string>
/***************************************************
                    VERTEX
****************************************************/

/// Le constructeur met en place les éléments de l'interface
VertexInterface::VertexInterface(int idx, int x, int y, std::string pic_name, int pic_idx)
{
    // La boite englobante des images
    m_top_box.set_pos(x, y);
    m_top_box.set_dim(130, 100);
    m_top_box.set_moveable();

    // Le slider de réglage de valeur
   /* m_top_box.add_child( m_slider_value );
    m_slider_value.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_value.set_dim(20,80);
    m_slider_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);*/

    // Label de visualisation de valeur
    m_top_box.add_child( m_label_value );
    m_label_value.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Down);

    // Une illustration...
    if (pic_name!="")
    {
        m_top_box.add_child( m_img );
        m_img.set_pic_name(pic_name);
        m_img.set_pic_idx(pic_idx);
        m_img.set_gravity_x(grman::GravityX::Right);
    }

    // Label de visualisation d'index du sommet dans une boite
    m_top_box.add_child( m_box_label_idx );
    m_box_label_idx.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Down);
    m_box_label_idx.set_dim(20,12);
    m_box_label_idx.set_bg_color(BLANC);
    m_box_label_idx.add_child( m_label_idx );
    m_box_label_idx.set_message("1");

    m_top_box.add_child( m_croix);
    m_croix.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_croix.set_dim(20,20);
    m_croix.set_bg_color(ROUGE);
    m_croix.set_message("X");
}

/// Gestion du Vertex avant l'appel à l'interface
void Vertex::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_value vers le slider associé
   // m_interface->m_slider_value.set_value(m_value);

    /// Copier la valeur locale de la donnée m_value vers le label sous le slider
//    m_interface->m_label_value.set_message( std::to_string( (int)m_value) );
}


/// Gestion du Vertex après l'appel à l'interface
void Vertex::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_value locale
   // m_value = m_interface->m_slider_value.get_value();
}



/***************************************************
                    EDGE
****************************************************/

/// Le constructeur met en place les éléments de l'interface
EdgeInterface::EdgeInterface(Vertex& from, Vertex& to)
{
    // Le WidgetEdge de l'interface de l'arc
    if ( !(from.m_interface && to.m_interface) )
    {
        std::cerr << "Error creating EdgeInterface between vertices having no interface" << std::endl;
        throw "Bad EdgeInterface instanciation";
    }
    m_top_edge.attach_from(from.m_interface->m_top_box);
    m_top_edge.attach_to(to.m_interface->m_top_box);
    m_top_edge.reset_arrow_with_bullet();

    // Une boite pour englober les widgets de réglage associés
    /*m_top_edge.add_child(m_box_edge);
    m_box_edge.set_dim(24,60);
    m_box_edge.set_bg_color(BLANCBLEU);

    // Le slider de réglage de valeur
    m_box_edge.add_child( m_slider_weight );
    m_slider_weight.set_range(0.0 , 100.0); // Valeurs arbitraires, à adapter...
    m_slider_weight.set_dim(16,40);
    m_slider_weight.set_gravity_y(grman::GravityY::Up);*/

    // Label de visualisation de valeur
    m_box_edge.add_child( m_label_weight );
    m_label_weight.set_gravity_y(grman::GravityY::Down);

}


/// Gestion du Edge avant l'appel à l'interface
void Edge::pre_update()
{
    if (!m_interface)
        return;

    /// Copier la valeur locale de la donnée m_weight vers le slider associé
//    m_interface->m_slider_weight.set_value(m_weight);

    /// Copier la valeur locale de la donnée m_weight vers le label sous le slider
//    m_interface->m_label_weight.set_message( std::to_string( (int)m_weight ) );
}

/// Gestion du Edge après l'appel à l'interface
void Edge::post_update()
{
    if (!m_interface)
        return;

    /// Reprendre la valeur du slider dans la donnée m_weight locale
//    m_weight = m_interface->m_slider_weight.get_value();
}



/***************************************************
                    GRAPH
****************************************************/

/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{
    int ajout= 0;

    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(80,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(800,500);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCBLEU);

    ///BOUTON D'AJOUT DE SOMMET OU ARC
    m_top_box.add_child(m_ajoumenu);
    m_ajoumenu.set_dim(60,60);
    //m_ajoumenu.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_ajoumenu.set_pos(225,518);
    //m_ajoumenu.set_moveable(); //Fonction pour nouveaux sommets (deplacement)
    m_ajoumenu.set_bg_color(BLEU);
   // textprintf_ex(screen, font, 400, 23, makecol(255,0,0), -1,"ADD");


    ///BOUTON DE SAVE
    m_top_box.add_child(m_suppr);
    m_suppr.set_dim(60,60);
    m_suppr.set_pos(300,518);
    m_suppr.set_bg_color(ROUGE);

    ///BOUTON MAP 1
    m_top_box.add_child(m_map1);
    m_map1.set_dim(120,60);
    m_map1.set_pos(480,518);
    m_map1.set_bg_color(VERT);


    ///BOUTON MAP 2
    m_top_box.add_child(m_map2);
    m_map2.set_dim(120,60);
    m_map2.set_pos(650,518);
    m_map2.set_bg_color(ORANGE);

    ///BOUTON MAP 3
    m_top_box.add_child(m_map3);
    m_map3.set_dim(120,60);
    m_map3.set_pos(820,518);
    m_map3.set_bg_color(ROUGE);

    ///BOUTON SEP
    m_top_box.add_child(m_sep);
    m_sep.set_dim(2,85);
    m_sep.set_pos(410,505);
    m_sep.set_bg_color(NOIR);

    ///BOUTON QUIT
    m_top_box.add_child(m_quit);
    m_quit.set_dim(25,25);
    m_quit.set_pos(980,575);
    m_quit.set_bg_color(ROUGESOMBRE);

    ///BOUTON RETOUR
    m_top_box.add_child(m_retour);
    m_retour.set_dim(25,67);
    m_retour.set_pos(980,505);
    m_retour.set_bg_color(JAUNESOMBRE);

   ///TEXTE
   m_top_box.add_child(m_texteadd);
   m_texteadd.set_message("ADD");
   m_texteadd.set_pos(245,543);

   m_top_box.add_child(m_textesave);
   m_textesave.set_message("SAVE");
   m_textesave.set_pos(317,543);

   m_top_box.add_child(m_texte1);
   m_texte1.set_message("MAP 1");
   m_texte1.set_pos(526,543);

   m_top_box.add_child(m_texte2);
   m_texte2.set_message("MAP 2");
   m_texte2.set_pos(696,543);

   m_top_box.add_child(m_texte3);
   m_texte3.set_message("MAP 3");
   m_texte3.set_pos(865,543);

   //Creation du texte retour menu
   m_top_box.add_child(m_B);
   m_B.set_message("B");
   m_B.set_pos(987,520);

   m_top_box.add_child(m_A);
   m_A.set_message("A");
   m_A.set_pos(988,532);

   m_top_box.add_child(m_C);
   m_C.set_message("C");
   m_C.set_pos(987,544);

   m_top_box.add_child(m_K);
   m_K.set_message("K");
   m_K.set_pos(987,556);

   m_top_box.add_child(m_Q);
   m_Q.set_message("Q");
   m_Q.set_pos(987,586);

}

void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    load_file("Graphe.txt");

   /* if((mouse_b & 1) && (mouse_y > 530) && (mouse_x > 270))
    {

    }*/

    // La ligne précédente est en gros équivalente à :
    // m_interface = new GraphInterface(50, 0, 750, 600);

  /// Les sommets doivent être définis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image
    /*add_interfaced_vertex(0, 30.0, 200, 100, "SOLEIL.bmp");
    add_interfaced_vertex(1, 60.0, 400, 100, "PLante.bmp");
    add_interfaced_vertex(2,  50.0, 200, 300, "criquet.bmp");
    add_interfaced_vertex(3,  0.0, 400, 300, "souris.bmp");
    add_interfaced_vertex(4,  100.0, 600, 300, "serpent.bmp");*/

    /*add_interfaced_vertex(5,  0.0, 100, 500, "bad_clowns_xx3xx.jpg", 0);
    add_interfaced_vertex(6,  0.0, 300, 500, "bad_clowns_xx3xx.jpg", 1);
    add_interfaced_vertex(7,  0.0, 500, 500, "bad_clowns_xx3xx.jpg", 2);*/

    /// Les arcs doivent être définis entre des sommets qui existent !
    // AJouter l'arc d'indice 0, allant du sommet 0 au sommet 1 de poids 50 etc...
    /*add_interfaced_edge(0, 0, 1, 50.0);
    add_interfaced_edge(1, 1, 2, 50.0);
    add_interfaced_edge(2, 2, 3, 75.0);
    add_interfaced_edge(3, 3, 4, 25.0);*/

    /*add_interfaced_edge(4, 6, 3, 25.0);
    add_interfaced_edge(5, 7, 3, 25.0);
    add_interfaced_edge(6, 3, 4, 0.0);
    add_interfaced_edge(7, 2, 0, 100.0);
    add_interfaced_edge(8, 5, 2, 20.0);
    add_interfaced_edge(9, 3, 7, 80.0);*/
}

void Graph::make_exampleB()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    //load_file("Graphe.txt");
    std::cout<<"TEST"<<std::endl;
}

/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update()
{
    if (!m_interface)
        return;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_edges)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_edges)
        elt.second.post_update();

}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_vertex(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{
    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding vertex at idx=" << idx << " already used..." << std::endl;
        throw "Error adding vertex";
    }
    // Création d'une interface de sommet
    VertexInterface *vi = new VertexInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Vertex(value, vi);
}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_edge(int idx, int id_vert1, int id_vert2, double weight)
{

    if ( m_edges.find(idx)!=m_edges.end() )
    {
        std::cerr << "Error adding edge at idx=" << idx << " already used..." << std::endl;
        throw "Error adding edge";
    }



    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding edge idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding edge";
    }

    EdgeInterface *ei = new EdgeInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_edge);
    m_edges[idx] = Edge(weight, ei);

    m_edges[idx].m_from = id_vert1;
    m_edges[idx].m_to = id_vert2;

    m_vertices[id_vert1].m_out.push_back(idx);
    m_vertices[id_vert2].m_in.push_back(idx);
}

void Graph::load_file(std::string filename)
{
    std::ifstream file(filename, std::ios::in);
    int nbpics, x,y, nbarretes;
    int test;
    int n1, n2;
    std::string namepic;

    if(file)
    {
        file >> nbpics;
        for(unsigned int i = 0; i < nbpics; i++)
        {
            file >> x >> y >> namepic;
            add_interfaced_vertex(i,0,x,y, namepic);
        }

        file >> nbarretes;

        for(unsigned int i = 0; i < nbarretes; i++)
        {
            file >> n1 >> n2;
            add_interfaced_edge(i, n1, n2, 50);
        }

    }
    else std::cout << "[-] Couldn't open the file ! " << std::endl;
}

void Graph::save_file(std::string filename)
{

    std::ofstream fichier(filename, std::ios::out | std::ios::trunc);
    {
        if (fichier)
        {
            fichier << m_vertices.size() << std::endl;

            for(unsigned int i = 0 ; i < m_vertices.size() ; i++)
            {
                fichier << m_vertices[i].m_interface->m_top_box.get_posx() << " " << m_vertices[i].m_interface->m_top_box.get_posy() << " " << m_vertices[i].m_interface->m_img.get_pic_name() << std::endl;
            }

            fichier << m_edges.size() << std::endl;

            for(unsigned int j = 0 ; j < m_edges.size() ; j++)
            {
                fichier << m_edges[j].m_from << " " << m_edges[j].m_to << std::endl;
            }
        }
        else std::cout << "erreur lors de la sauvegarde" << std::endl;
    }
    fichier.close();
}

void supprimer()
{

}

