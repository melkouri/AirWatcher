/*************************************************************************
                           Cleaner  -  Classe définissant les cleaners installés pour améliorer la qualité de l'air
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined (Cleaner_H)
#define Cleaner_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//  Définir les cleaners installés pour améliorer la qualité de l'air
//  Chaque Cleaner possède un id, une latitude, une longitude, une date de début et une date de fin
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        
        string getIdCleaner();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idCleaner
        double getLatCleaner();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut latCleaner
        double getLngCleaner();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut lngCleaner
        tm* getDateDebut();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut dateDebut
        tm* getDateFin();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut dateFin

//-------------------------------------------- Constructeurs - destructeur
        Cleaner(const Cleaner & unCleaner);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Cleaner

        Cleaner();
        // Mode d'emploi :
        // Constructeur par défaut de la classe Cleaner

        Cleaner(string id, double lat, double lng, tm* debut, tm* fin);
        // Mode d'emploi :
        // Constructeur de la classe Cleaner

        virtual ~Cleaner();
        // Mode d'emploi :
        // Destructeur de la classe Cleaner

//------------------------------------------------------------------ PRIVE

    private:

//----------------------------------------------------- Attributs privées
        string idCleaner; 
        double latCleaner;
        double lngCleaner;
        tm* dateDebut;
        tm* dateFin;
};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // Cleaner_H
