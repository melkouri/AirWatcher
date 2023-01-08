/*************************************************************************
                           Fournisseur  -  Classe définissant des utilisateurs qui peuvent accéder à l'application avec des droits spéciaux
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Fournisseur> (fichier Fournisseur.h) ----------------
#if ! defined (Fournisseur_H)
#define Fournisseur_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"

//------------------------------------------------------------------------
// Rôle de la classe <Fournisseur>
//  Définir les utilisateurs de type Fournisseur qui peuvent accéder à l'application avec des droits spéciaux
//  Chaque Fournisseur est un Utilisateur avec un idFournisseur et un idCleaner
//------------------------------------------------------------------------

class Fournisseur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        string getIdFournisseur();
        // Mode d'emploi :
        // Cette méthode renvoie idFournisseur
        string getIdCleaner();
        // Mode d'emploi :
        // Cette méthode renvoie idCleaner

//------------------------------------------------- Surcharge d'opérateurs
        bool operator == ( const Fournisseur & unFournisseur );
        // Mode d'emploi :
        // Permet de comparer deux objets Fournisseur
        // si les deux Fournisseurs sont égaux (tous leurs attributs sont égaux) la méthode renvoie true
        // sinon la méthode renvoie false

//-------------------------------------------- Constructeurs - destructeur
        Fournisseur (const Fournisseur & unFournisseur);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Fournisseur

        Fournisseur();
        // Mode d'emploi (constructeur par défaut) :
        // Constructeur par défaut de la classe Fournisseur

        Fournisseur (string unIdFournisseur, string unIdCleaner);
        // Mode d'emploi :
        // Constructeur de la classe Fournisseur

        //Fournisseur (string unNom, string unPrenom, string unMotDePasse, string unMail, string unIdFournisseur, string unIdCleaner);
        // Mode d'emploi :
        // Constructeur de la classe Fournisseur

        virtual ~Fournisseur();
        // Mode d'emploi :
        // Destructeur de la classe Fournisseur

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Méthodes protégées
        // bool observerImpactCleaner (int idCleaner);
        // Mode d'emploi :
        // Permet au fournisseur d'observer l'impact du cleaner sur la qualité de l'air
        // si la qualité de l'air s'est amélioré depuis que le cleaner est là, la méthode renvoie true
        // sinon elle renvoie false

//----------------------------------------------------- Attributs protégés
        string idFournisseur;
        string idCleaner;

};

//-------------------------------- Autres définitions dépendantes de <Fournisseur>

#endif // Fournisseur_H