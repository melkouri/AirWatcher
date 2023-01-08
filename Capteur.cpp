/*************************************************************************
                           Capteur  -  Classe définissant les capteurs utilisés pour relever la qualité de l'air
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

/* //INUTILE SI ON ENLEVE user DE CAPTEUR
void Capteur::SetUser (map<string,string> mapCapteurUser)
// Algorithme :
//
{
   typename map<string,string>:: iterator itUser=mapCapteurUser.find( this->idCapteur);
  if(itUser !=mapCapteurUser.end()){
    this->user=new Utilisateur(itUser->second);
    //constructeur par id de utilisateur
  }
} //----- Fin de Capteur
*/

string Capteur::getIdCapteur() 
{
    return idCapteur;
} //Fin de la méthode getIdCapteur

double Capteur::getLatCapteur() 
{
    return latCapteur;
} //Fin de la méthode getLatCapteur

double Capteur::getLngCapteur() 
{
    return lngCapteur;
} //Fin de la méthode getLngCapteur

list <Mesure> Capteur::getListMesures() 
{
    return listMesures;
} //Fin de la méthode getMesures

void Capteur::addListMesures(Mesure mesure)
{
    listMesures.push_back(mesure);
}
//-------------------------------------------- Constructeurs - destructeur
Capteur::Capteur (const Capteur & unCapteur)
{
    this->idCapteur = unCapteur.idCapteur;
    this->latCapteur = unCapteur.latCapteur;
    this->lngCapteur = unCapteur.lngCapteur;
    this->listMesures = unCapteur.listMesures ;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Capteur>" << endl;
    #endif
} //Fin de Capteur (constructeur de copie)

Capteur::Capteur(){
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Capteur>" << endl;
    #endif
} //Fin de Capteur (constructeur par défaut)

Capteur::Capteur (string idCapteur, double latCapteur,double lngCapteur )
{
    this->idCapteur = idCapteur;
    this->latCapteur = latCapteur;
    this->lngCapteur = lngCapteur;
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif
} //Fin de Capteur


Capteur::~Capteur()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Capteur>" << endl;
    #endif
} //Fin de ~Capteur

//---------- Fin de la classe <Capteur> (fichier Capteur.cpp) ------------

