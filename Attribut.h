/*************************************************************************
                           Attribut  -  Classe permettant de définir les composants de l'air étudiés
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ----------------
#if ! defined (ATTRIBUT_H)
#define ATTRIBUT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Attribut>
//  Définir les différents composants de l'air étudiés
//  Chaque Attribut possède un id, une unité et une description
//------------------------------------------------------------------------

class Attribut 
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        string getIdAttribut();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut de type string idAttribut

        string getUnite();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut de type string unite

        string getDescription();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut de type string description

//-------------------------------------------- Constructeurs - destructeur
        Attribut (const Attribut & unAttribut);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Attribut

        Attribut();
        // Mode d'emploi :
        // Constructeur par défaut de la classe Attribut

        Attribut (string idAttribut, string unite, string description);
        // Mode d'emploi :
        // Constructeur de la classe Attribut

        virtual ~Attribut();
        // Mode d'emploi :
        // Destructeur de la classe Attribut

//------------------------------------------------------------------ PRIVE

    protected:

//----------------------------------------------------- Attributs protégés
        string idAttribut;
        string unite;
        string description;
};

//-------------------------------- Autres définitions dépendantes de <Attribut>

#endif // ATTRIBUT_H

