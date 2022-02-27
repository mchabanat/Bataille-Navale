/**
 * @file sousProgrammes.h
 * @author Matis CHABANAT et Arthur LE MENN 
 * @brief Nous certifions que ce document (fichier d'en-tête du module) a été réalisé par nous-même.
 *        Il a été réalisé dans le cadre de la SAE 1.02 Comparaison d'approches algorithmiques, lors 
 *        du semestre 1 du BUT informatique à Anglet, 2021-2022.
 * @date 2022-01-05
 */

#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;



/******** DECLARATION DE VARIABLES GLOBALES ********/
const unsigned short int NB_LIGNES = 9; // Représente le nombre de lignes du plateau de jeu pour la bataille navale
const unsigned short int NB_COLONNES = 9; // Représente le nombre de colonnes du plateau de jeu pour la bataille navale


/******** ENREGISTREMENTS ********/

// Creation de l'enregistrement IndiceCoordonnee qui représente l'indice d'une coordonnée dans le tableau 2 dimensions.
struct IndiceCoordonnee
{
    int coordX;
    int coordY;
};

// Creation de l'enregistrement Coordonnee qui représente les coordonnées saisies par le joueur.
struct Coordonnee
{
    char coordX;
    char coordY;
};


/******** SOUS-PROGRAMMES ********/

void afficherRegles();
// BUT : Afficher les règles du jeu

void afficherGrille(char tableau[NB_LIGNES][NB_COLONNES], unsigned int nbLigne, unsigned int nbColonne);
// BUT : Afficher une grille de jeu (c'est à dire un tableau bidimensionnel) 

void placerBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau, unsigned short int largeurPlateau, unsigned short int hauteurPlateau);
// BUT : Déterminer les coordonnées du bateau sur un plateau de largeurPlateau par hauteurPlateau

void afficherCoordBateau(IndiceCoordonnee tableau[], unsigned short int longueurBateau);
// BUT : Afficher les coordonnées du bateau grâce a ses indices de coordonnées (placés dans le tableau)
// Précondition : les coordonnées traitées sont des indices de coordonnées

Coordonnee indiceVersCoordonnee(IndiceCoordonnee indice);
// BUT : transformer une variable de type indiceCoordonnee en une variable de type Coordonnee

IndiceCoordonnee coordonneeVersIndice(Coordonnee coordonnee);
// BUT : transformer une variable de type Coordonnee en une variable de type indiceCoordonnee

#endif