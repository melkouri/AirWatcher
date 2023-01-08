/*************************************************************************
                           Gouvernement  -  Classe définissant des utilisateurs qui peuvent accéder à l'application avec des droits spéciaux
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Gouvernement> (fichier Gouvernement.h) ----------------
#if ! defined ( GOUVERNEMENT_H )
#define GOUVERNEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Utilisateur.h"
#include "Cleaner.h"

//------------------------------------------------------------------------
// Rôle de la classe <Gouvernement>
//  La classe Gouvernement est une classe fille de Utilisateur 
//  Les utilisateurs de cette classe ont un accés sécurisé et ont des droits spéciaux
//  Ils peuvent gérer les utilisateurs ayant des capteurs et regarder l'impact des cleaners
//------------------------------------------------------------------------

class Gouvernement : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        bool observerImpactCleaner(Cleaner c, map <string,Capteur> listCapteurs);
        // Mode d'emploi : 
        // Cet algorithme cherche les capteurs situés autour d’un cleaner et fait la moyenne de leurs mesures actuelles.
        // Ensuite, l’algorithme cherche les données avant l’installation du cleaner et fait la moyenne également.
        // L’algorithme compare ensuite les moyennes : si la moyenne actuelle est inférieure à la moyenne passée on renvoie true, sinon false.

        // bool classifieFiabilite(bool fiable, Client client);
        // Mode d'emploi :
        // Cet algorithme permet au gouvernement de determiner si un client est fiable ou non 
        // et de le mettre en liste noire si il est jugé non fiable

        // int observerPerformancesAlgo();
        // Mode d'emploi :
        // Cet algorithme permet au gouvernement de juger de la performance de notre application en retournant un pourcentage

        // bool verifierFonctionnementCapteur(Capteur capteur);
        // Mode d'emploi :
        // Cet algorithme permet au gouvernement de comparer un capteur à ses voisins alentours avec un seuil fixe qu'on aura défini.

        string getIdGouv();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut idGouv

//-------------------------------------------- Constructeurs - destructeur
        Gouvernement (const Gouvernement & unGouvernement);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur par copie de la classe Gouvernement

        Gouvernement();
        // Mode d'emploi (constructeur par défaut) :
        // Constructeur par défaut de la classe Gouvernement

        Gouvernement (string idGouvernement, string unNom, string unPrenom, string unMotDePasse, string unMail);
        // Mode d'emploi :
        // Constructeur avec option de la classe Gouvernement


        virtual ~Gouvernement();
        // Mode d'emploi :
        // Destructeur de la classe Gouvernement


//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Attributs protégés
        string idGouv;
};

//-------------------------------- Autres définitions dépendantes de <Gouvernement>

#endif // Gouvernement_H

