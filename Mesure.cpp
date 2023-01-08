/*************************************************************************
                           Mesure  -  Classe définissant les mesures relevées par les capteurs
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Mesure::getIdAttribut()
{
    return idAttribut;
} //Fin de la méthode getIdAttribut

tm* Mesure::getDate()
{
    return date;
} //Fin de la méthode getDate 

double Mesure::getValeur()
{
    return valeur;
} //Fin de la méthode getValeur 

//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure (const Mesure & unMesure)
{
    this->idAttribut = unMesure.idAttribut;
    this->date = unMesure.date;
    this->valeur = unMesure.valeur;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Mesure>" << endl;
    #endif
} //Fin de Mesure (constructeur de copie)

Mesure::Mesure()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Mesure>" << endl;
    #endif
} //Fin de Mesure (constructeur par défaut)

Mesure::Mesure (string idAttribut, tm* date, double valeur)
{
    this->idAttribut = idAttribut;
    this->date = date;
    this->valeur = valeur;
    #ifdef MAP
        cout << "Appel au constructeur de <Mesure>" << endl;
    #endif
} //Fin de Mesure


Mesure::~Mesure()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Mesure>" << endl;
    #endif
} //Fin de ~Mesure

//---------- Fin de la classe <Mesure> (fichier Mesure.cpp) ------------
