/*************************************************************************
                           Cleaner  -  Classe définissant les cleaners installés pour améliorer la qualité de l'air
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Cleaner::getIdCleaner() 
{
    return idCleaner;
} //Fin de la méthode getIdCleaner

double Cleaner::getLatCleaner() 
{
    return latCleaner;
} //Fin de la méthode getLatCleaner

double Cleaner::getLngCleaner() 
{
    return lngCleaner;
} //Fin de la méthode getLngCleaner

tm* Cleaner::getDateDebut() 
{
    return dateDebut;
} //Fin de la méthode getDateDebut

tm* Cleaner::getDateFin() 
{
    return dateFin;
} //Fin de la méthode getDateFin

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner (const Cleaner & unCleaner)
{
    idCleaner = unCleaner.idCleaner;
    latCleaner = unCleaner.latCleaner;
    lngCleaner = unCleaner.lngCleaner;
    dateDebut = unCleaner.dateDebut;
    dateFin = unCleaner.dateFin;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cleaner>" << endl;
    #endif
} //Fin de Cleaner (constructeur de copie)


Cleaner::Cleaner()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Cleaner>" << endl;
    #endif
} //Fin de Cleaner (constructeur par défaut)

Cleaner::Cleaner (string id, double lat, double lng, tm* debut, tm* fin)
{
    idCleaner = id;
    latCleaner = lat;
    lngCleaner = lng;
    dateDebut = debut;
    dateFin = fin;
    #ifdef MAP
        cout << "Appel au constructeur de <Cleaner>" << endl;
    #endif
} //Fin de Cleaner


Cleaner::~Cleaner()
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //Fin de ~Cleaner

//---------- Fin de la classe <Cleaner> (fichier Cleaner.cpp) ------------