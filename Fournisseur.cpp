/*************************************************************************
                           Fournisseur  -  Classe définissant des utilisateurs qui peuvent accéder à l'application avec des droits spéciaux
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Fournisseur.h"
#include "Utilisateur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Fournisseur::getIdFournisseur() 
{
    return idFournisseur;
} //Fin de la méthode getIdFournisseur

string Fournisseur::getIdCleaner()
{
    return idCleaner;
} //Fin de la méthode getIdCleaner

//------------------------------------------------- Surcharge d'opérateurs
bool Fournisseur::operator == ( const Fournisseur & unFournisseur )
// Algorithme : La comparaison de deux Fournisseurs se fait en fonction de leur id
//
{
    if(idFournisseur == unFournisseur.idFournisseur)
    {
        return true;
    } else
    {
        return false;
    }
} //Fin de operator ==


//-------------------------------------------- Constructeurs - destructeur
Fournisseur::Fournisseur (const Fournisseur & unFournisseur)
{
    idFournisseur = unFournisseur.idFournisseur,
    idCleaner = unFournisseur.idCleaner;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Fournisseur>" << endl;
    #endif
} //Fin de Fournisseur (constructeur de copie)

Fournisseur::Fournisseur()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Fournisseur>" << endl;
    #endif
} //Fin de Fournisseur (constructeur par défaut)

Fournisseur:: Fournisseur (string unIdFournisseur, string unIdCleaner)
{
    idFournisseur = unIdFournisseur,
    idCleaner = unIdCleaner;
    #ifdef MAP
        cout << "Appel au constructeur de <Fournisseur>" << endl;
    #endif
} //Fin de Fournisseur


/*Fournisseur::Fournisseur ( string unNom, string unPrenom, string unMotDePasse, string unMail, string unIdFournisseur, string unIdCleaner) : Utilisateur (unNom, unPrenom, unMotDePasse, unMail)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fournisseur>" << endl;
#endif
idFournisseur = unIdFournisseur,
idCleaner = unIdCleaner;

} //----- Fin de Fournisseur*/


Fournisseur::~Fournisseur()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Fournisseur>" << endl;
    #endif
} //Fin de ~Fournisseur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
// bool Fournisseur::observerImpactCleaner (int idCleaner)
//{
//} //Fin de observerImpactCleaner

//---------- Fin de la classe <Fournisseur> (fichier Fournisseur.cpp) ------------

