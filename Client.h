 /*************************************************************************
                           Client  -  Classe  définissant des utilisateurs qui peuvent accéder à l'application
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Client> (fichier Client.h) ----------------
#if ! defined (CLIENT_H)
#define CLIENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"

//------------------------------------------------------------------------
// Rôle de la classe <Client>
//  Définir les utilisateurs de type client qui peuvent accéder à l'application
//  Chaque Client est un Utilisateur avec un id, un idCapteur, un nombre de points et un statut de fiabilité
//------------------------------------------------------------------------

class Client : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        string getIdClient();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idClient
        string getIdCapteur();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idCapteur
        int getPoints();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut points
        bool getFiabilite();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut fiabilite

//------------------------------------------------- Surcharge d'opérateurs
        bool operator == ( const Client & unClient );
        // Mode d'emploi :
        // Permet de comparer deux objets Client
        // si les deux Clients sont égaux (tous leurs attributs sont égaux) la méthode renvoie true
        // sinon la méthode renvoie false

//-------------------------------------------- Constructeurs - destructeur
        Client ( const Client & unClient );
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Client

        Client();
        // Mode d'emploi (constructeur par défaut) :
        // Constructeur par défaut de la classe Client

        //Client ( string unNom, string unPrenom, string unMotDePasse, string unMail, string unIdClient, string unIdCapteur, int desPoints, bool uneFiabilite );
        // Mode d'emploi :
        // Constructeur de la classe Client

        Client ( string unIdClient, string unIdCapteur);
        // Mode d'emploi :
        // Constructeur de la classe Client

        virtual ~Client ( );
        // Mode d'emploi :
        // Destructeur de la classe Client

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Méthodes protégées
        // int consulterPoints (client Client);
        // Mode d'emploi :
        // Cette méthode permet au client de pouvoir consulter son solde de points

//----------------------------------------------------- Attributs protégés
        string idClient;
        string idCapteur;
        int points;
        bool fiabilite;

};

//-------------------------------- Autres définitions dépendantes de <Client>

#endif // Client_H

