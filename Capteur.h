/*************************************************************************
                           Capteur  -  Classe définissant les capteurs utilisés pour relever la qualité de l'air
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined (CAPTEUR_H)
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
#include <map>
#include <string>
#include <list>

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//  Définir les capteurs utilisés pour relever la qualité de l'air
//  Chaque Capteur possède un id, une latitude, une longitude et une liste de mesures
//------------------------------------------------------------------------

class Capteur 
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        string getIdCapteur();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idCapteur
        double getLatCapteur();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut latCapteur
        double getLngCapteur();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut lngCapteur
        list <Mesure> getListMesures();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut mesures
        void addListMesures(Mesure mesure);
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut mesures

//-------------------------------------------- Constructeurs - destructeur
        Capteur (const Capteur & unCapteur);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Capteur

        Capteur();
        // Mode d'emploi :
        // Constructeur par défaut de la classe Capteur

        Capteur (string idCapteur, double latCapteur,double lngCapteur );
        // Mode d'emploi :
        // Constructeur de la classe Capteur

        virtual ~Capteur();
        // Mode d'emploi :
        // Destructeur de la classe Capteur

//------------------------------------------------------------------ PRIVE

    protected:

//----------------------------------------------------- Attributs protégés

        string idCapteur;
        double latCapteur;
        double lngCapteur;
        list <Mesure> listMesures;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // Capteur_H

