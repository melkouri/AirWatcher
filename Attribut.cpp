/*************************************************************************
                           Attribut  -  Classe permettant de définir les composants de l'air étudiés
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Attribut::getIdAttribut()
{
    return idAttribut;
} //Fin de la méthode getIdAttribut

string Attribut::getUnite()
{
    return unite;
} //Fin de la méthode getUnite

string Attribut::getDescription()
{
    return description;
} //Fin de la méthode getDescription

//-------------------------------------------- Constructeurs - destructeur
Attribut::Attribut (const Attribut & unAttribut)
{
    this->idAttribut = unAttribut.idAttribut;
    this->unite = unAttribut.unite;
    this->description = unAttribut.description;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Attribut>" << endl;
    #endif
} //Fin de Attribut (constructeur de copie)

Attribut::Attribut() 
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Attribut>" << endl;
    #endif
} //Fin de Attribut (constructeur par défaut)

Attribut::Attribut (string idAttribut, string unite, string description)
{
    this->idAttribut = idAttribut;
    this->unite = unite;
    this->description = description;
    #ifdef MAP
        cout << "Appel au constructeur de <Attribut>" << endl;
    #endif
} //Fin de Attribut


Attribut::~Attribut()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Attribut>" << endl;
    #endif
} //Fin de ~Attribut

//---------- Fin de la classe <Attribut> (fichier Attribut.cpp) ------------