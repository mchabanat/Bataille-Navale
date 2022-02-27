/**
 * @file main.cpp
 * @author Matis CHABANAT et Arthur LE MENN 
 * @brief Nous certifions que ce document (programme principal) a été réalisé par nous-même.
 *        Il a été réalisé dans le cadre de la SAE 1.02 Comparaison d'approches algorithmiques, 
 *        lors du semestre 1 du BUT informatique à Anglet, 2021-2022.
 * @date 2022-01-05
 */

/*
 Programme : Bataille Navale
 But :  Realiser une partie du jeu de société "Bataille Navale" (simplifié)
 Date de dernière modification : 05/01/22
 Auteur : Chabanat Matis, Le Menn Arthur | TD1 - TP1
 Remarques : 
*/

#include <iostream>
#include "sousProgrammes.h"
#include "game-tools.h"
using namespace std;

int main(void)
{
    /************************************* VARIABLES *************************************/
    char plateau[NB_LIGNES][NB_COLONNES] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Représente le plateau de jeu de la bataille navale

    // Compteurs
    unsigned short int nbTouches; // Nombre de tirs qui ont touché le bateau
    unsigned short int nbTirs;    // Nombre de tirs effectués depuis le début de la partie

    // Coordonnées du bateau
    const unsigned short int LONG_BATEAU = 4;  // La longueur du bateau
    IndiceCoordonnee coordBateau[LONG_BATEAU]; // Les coordonnées du bateau

    // Concernant le tir
    bool dejaJoue;           // Indique si le joueur a deja joué a ces indices la ou non
    bool estTouche;          // Indique si le tir touche le navire
    Coordonnee coordTir;     // Représente les coordonnées du tir saisies par le joueur
    bool abandon;            // True si le joueur souhaite abandonner, false sinon

    // Indicateur de saisie
    bool erreurSaisie; // L'utilisateur à fait une erreur de saisie ou pas

    /************************************* TRATEMENTS *************************************/
    /********** INITIALISATION **********/
    // Mise des variables à leurs statuts initiaux
    erreurSaisie = true;

    // Initialiser les compteurs
    nbTouches = 0;
    nbTirs = 0;

    // Initialiser les coordonnées du bateau
    placerBateau(coordBateau, LONG_BATEAU, NB_COLONNES, NB_LIGNES);

    /********** JOUER LA PARTIE **********/
    while (nbTouches < LONG_BATEAU)
    {
        // Initialisation de la manche
        estTouche = false;

        // Effacer l'écran
        effacer();

        // Affichage de l'entête
        afficherRegles();

        // Affichage des coordonnées du bateau
        afficherCoordBateau(coordBateau, LONG_BATEAU);

        // Afficher la nouvelle grille
        afficherGrille(plateau, NB_LIGNES, NB_COLONNES);

        // Saisie verif des coordonnées
        do
        {
            do
            {
                // Avant la saisie on considère qu'il n'y a pas d'erreur
                erreurSaisie = false;

                // Saisie
                cout << "Votre " << nbTirs + 1 << "e tir (ex. A3) ou abandonner (@@) : ";
                cin >> coordTir.coordX;
                cin >> coordTir.coordY;

                // Recherche en coordX
                if (coordTir.coordX != 'A' && coordTir.coordX != 'B' && coordTir.coordX != 'C' && coordTir.coordX != 'D' && coordTir.coordX != 'E' &&
                    coordTir.coordX != 'F' && coordTir.coordX != 'G' && coordTir.coordX != 'H' && coordTir.coordX != 'I' && coordTir.coordX != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'X' !", rouge, true);
                    erreurSaisie = true;
                }

                // Recherche en coordY
                if (coordTir.coordY != '1' && coordTir.coordY != '2' && coordTir.coordY != '3' && coordTir.coordY != '4' && coordTir.coordY != '5' &&
                    coordTir.coordY != '6' && coordTir.coordY != '7' && coordTir.coordY != '8' && coordTir.coordY != '9' && coordTir.coordY != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'Y' !", rouge, true);
                    erreurSaisie = true;
                }
            } while (erreurSaisie == true);

            // Recherche de l'abandon
            if (coordTir.coordX == '@' && coordTir.coordY == '@')
            {
                abandon = true;
                break;
            }
            else
            {
                if (coordTir.coordX != '@' && coordTir.coordY == '@')
                {
                    afficherTexteEnCouleur("Erreur en 'X' !", rouge, true);
                    erreurSaisie = true;
                }
                else if (coordTir.coordX == '@' && coordTir.coordY != '@')
                {
                    afficherTexteEnCouleur("Erreur en 'Y' !", rouge, true);
                    erreurSaisie = true;
                }
            }
        } while (erreurSaisie == true);

        // Condition de sortie - cas de l'abandon
        if (abandon)
        {
            break;
        }

        // Rechercher si le joueur a déja tiré ici ou pas
        // Au debut on considère qu'il na pas joué à ces indices
        dejaJoue = false;

        if (plateau[coordonneeVersIndice(coordTir).coordY][coordonneeVersIndice(coordTir).coordX] == '.' 
            || plateau[coordonneeVersIndice(coordTir).coordY][coordonneeVersIndice(coordTir).coordX] == 'o')
        {
            dejaJoue = true;
        }

        if (!dejaJoue)
        {
            // Determiner si le tir touche le bateau ou non
            for (int i = 0; i < LONG_BATEAU; i++)
            {
                if (coordonneeVersIndice(coordTir).coordX == coordBateau[i].coordX && coordonneeVersIndice(coordTir).coordY == coordBateau[i].coordY)
                {
                    cout << "Touche !";
                    estTouche = true;
                    nbTouches++;
                }
            }

            // Marquer la grille
            if (estTouche)
            {
                plateau[coordonneeVersIndice(coordTir).coordY][coordonneeVersIndice(coordTir).coordX] = 'o';
            }
            else
            {
                plateau[coordonneeVersIndice(coordTir).coordY][coordonneeVersIndice(coordTir).coordX] = '.';
            }

            // Incrémentation du nombre de Tirs
            nbTirs++;
        }
        else
        {
            cout << "Vous avez deja tire ici !" << endl;
            pause(2);
        }
    }

    /********** FIN DE LA PARTIE **********/
    // Effacer l'ecran
    effacer();

    // Affichage de l'entête
    afficherRegles();

    // Afficher les coordonnées du bateau
    afficherCoordBateau(coordBateau, LONG_BATEAU);

    // Afficher la grille
    afficherGrille(plateau, NB_LIGNES, NB_COLONNES);

    if (abandon)
    {
        // Afficher le nombre de touches après un certain nombre de tirs si le joueur abandonne
        cout << "A B A N D O N - Bateau touche " << nbTouches << " fois sur " << nbTirs << ".";
    }
    else
    {
        // Afficher le nombre de tirs effectués pour couler le bateau
        cout << "B A T E A U  C O U L E en " << nbTirs << " tirs !" << endl;
    }

    return 0;
}
