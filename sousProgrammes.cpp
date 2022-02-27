/**
 * @file main.cpp
 * @author Matis CHABANAT et Arthur LE MENN 
 * @brief Nous certifions que ce document (corps du module) a été réalisé par nous-même.
 *        Il a été réalisé dans le cadre de la SAE 1.02 Comparaison d'approches algorithmiques, 
 *        lors du semestre 1 du BUT informatique à Anglet, 2021-2022.
 * @date 2022-01-05
 */

#include "sousProgrammes.h"

void afficherRegles()
{
    afficherTexteEnCouleur("B A T A I L L E  N A V A L E", bleu, true);
    cout << endl;
    cout << "Vous devez couler un bateau de 4 cases" << endl;
    cout << "(vertical ou horizontal ou diagonal)." << endl;
    cout << endl;
}

void afficherGrille(char tableau[NB_LIGNES][NB_COLONNES], unsigned int nbLigne, unsigned int nbColonne)
{
    // Declaration des indices des boucles
    unsigned int i;
    unsigned int j;

    cout << "  A B C D E F G H I" << endl;

    // Affichage de la grille de jeu
    for (i = 0; i <= (nbLigne - 1); i++)
    {
        cout << i + 1 << " ";

        for (j = 0; j <= (nbColonne - 1); j++)
        {
            cout << tableau[i][j] << " ";
        }

        // Passage à la ligne
        cout << endl;
    }
    cout << endl;
}

void placerBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau)
{
    // VARIABLES
    bool continuer = true;            // condition d'arrêt
    unsigned short int sensBateau; // Sens dans lequel sera le bateau (compris entre 1 et 4)

    while (continuer == true)
    {
        // INITIALISATION
        // Déterminer la coordonnée de base du bateau
        tableau[0].coordX = random(0, largeurPlateau - 1);
        tableau[0].coordY = random(0, hauteurPlateau - 1);
        // Mettre continuer a true
        continuer = true;
        // Determiner dans quel sens sera le bateau
        sensBateau = static_cast<unsigned short int>(random(1, 4)); // Transtypage car on ne veut pas mettre de int (random) dans un unsigned short int (sensBateau) (-> eviter un warning)

        // PLACEMENT DU BATEAU
        for (unsigned int i = 1; i < longueurBateau; i++)
        {
            switch (sensBateau)
            {
            case 1:
                if (tableau[0].coordX + longueurBateau < largeurPlateau)
                {
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i - 1].coordX + 1;
                    tableau[i].coordY = tableau[i - 1].coordY;
                    continuer = false;
                }
                else
                {
                    i = longueurBateau;
                }
                break;
            case 2:
                if (tableau[0].coordY + longueurBateau < hauteurPlateau)
                {
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i - 1].coordX;
                    tableau[i].coordY = tableau[i - 1].coordY + 1;
                    continuer = false;
                }
                else
                {
                    i = longueurBateau;
                }
                break;
            case 3:
                if (tableau[0].coordX + longueurBateau < largeurPlateau && tableau[0].coordY + longueurBateau < hauteurPlateau)
                {
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i - 1].coordX + 1;
                    tableau[i].coordY = tableau[i - 1].coordY + 1;
                    continuer = false;
                }
                else
                {
                    i = longueurBateau;
                }
                break;
            case 4:
                if (tableau[0].coordX - longueurBateau > largeurPlateau && tableau[0].coordY - longueurBateau > hauteurPlateau)
                {
                    //Déterminer les coordonnées de la suite du bateau
                    tableau[i].coordX = tableau[i - 1].coordX - 1;
                    tableau[i].coordY = tableau[i - 1].coordY - 1;
                    continuer = false;
                }
                else
                {
                    i = longueurBateau;
                }
                break;
            }
        }
    }
}

void afficherCoordBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau)
{
    Coordonnee coordEnCours;
    unsigned short int i;

    cout << "Bateau = ";

    for (i = 0; i < longueurBateau; i++)
    {
        coordEnCours = indiceVersCoordonnee(tableau[i]);
        cout << "(" << coordEnCours.coordX << "," << coordEnCours.coordY << ") ";
    }
    cout << endl;
    cout << endl;
}

Coordonnee indiceVersCoordonnee(IndiceCoordonnee indice)
{
    //VARIABLES
    Coordonnee coordonneeFinale; //Les coordonnées qui vont être retourné par le programme

    //TRAITEMENT
    coordonneeFinale.coordX = char(indice.coordX + 65);
    coordonneeFinale.coordY = char(indice.coordY + 49);

    return coordonneeFinale;
}

IndiceCoordonnee coordonneeVersIndice(Coordonnee coordonnee)
{
    //VARIABLES
    IndiceCoordonnee indiceFinal; //Les indices qui vont être retourné par le programme

    //TRAITEMENT
    indiceFinal.coordX = int(coordonnee.coordX) - 65;
    indiceFinal.coordY = int(coordonnee.coordY) - 49;

    return indiceFinal;
}
