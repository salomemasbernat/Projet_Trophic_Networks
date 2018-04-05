#include "grman/grman.h"
#include <iostream>

#include "graph.h"

std::string menu (){
    std::string path;


    // Enorme menu avec jouer quitter

    std::cout<< "Entrer le nom de la chaine alimentaire:"<< std::endl;
    std::cin >> path;
    return path;
}

int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();

    /// Le nom du r�pertoire o� se trouvent les images � charger

    std::string deuxiemestring = menu();

    grman::set_pictures_path(deuxiemestring);

    /// Un exemple de graphe
     Graph g;
    //g.make_example();
    g.lirefichier("/fichier.txt" , deuxiemestring);
    //g.lirefichier("/fichier1.txt", deuxiemestring);

    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {
        /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();
       g.addsommet(); // Quand on clique sur les coordon�es
       g.barreoutils();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


