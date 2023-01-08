/*************************************************************************
                           Mesure  -  Classe définissant les mesures relevées par les capteurs
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "Attribut.h"
#include <string>
#include <ctime>

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//  Définir les mesures relevées par les capteurs en donnant
//  l'attribut mesuré, la date de la mesure et sa valeur
//------------------------------------------------------------------------

class Mesure 
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        double getValeur();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut valeur

        tm * getDate();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut date

        string getIdAttribut();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idAttribut

//-------------------------------------------- Constructeurs - destructeur
        Mesure (const Mesure & unMesure);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Mesure

        Mesure();
        // Mode d'emploi (constructeur par défaut) :
        // Constructeur par défaut de la classe Mesure

        Mesure (string idAttribut, tm* date, double valeur);
        // Mode d'emploi :
        // Constructeur de la classe Mesure

        virtual ~Mesure();
        // Mode d'emploi :
        // Destructeur de la classe Mesure

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Attributs protégés
        tm * date;
        double valeur;
        string idAttribut;
        
};

//-------------------------------- Autres définitions dépendantes de <Mesure>

#endif // MESURE_H

