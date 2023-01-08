/*************************************************************************
                           Utilisateur  -  Classe mère définissant des utilisateurs de l'application
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ----------------
#if ! defined ( UTILISATEUR_H )
#define UTILISATEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <map>
#include <ctime>
#include "Capteur.h"

//------------------------------------------------------------------------
// Rôle de la classe <Utilisateur>
//  Définir les utilisateurs accédant à l'application
//  Chaque Utilisateur possède un nom, un prénom, un mail et un mot de passe lui permettant de se connecter
//------------------------------------------------------------------------

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC

    public:
//----------------------------------------------------- Méthodes publiques
        string getNom();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut nom
        string getPrenom();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut prenom
        string getMdp();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut mdp
        string getMail();
        // Mode d'emploi :
        // Cette méthode renvoie l'attribut mail

        int observerLieuMoment(double latitude,double longitude,double rayon,tm * date, map <string,Capteur> listCapteurs);
        // Mode d'emploi :
        // Cette méthode affiche les moyennes des différents attributs mesurés au lieu de coordonnées (latitude, longitude) et au moment date
        // Elle renvoie 0 si les moyennes ont bien été affichées, -1 sinon

        /*
        bool seConnecter(string mail, string mdp);
        // Mode d'emploi :
        // Cette méthode renvoie true si le mail et le mot de passe correspondent bien à un utilisateur
        // elle renvoie false sinon

        bool seDeconnecter();
        // Mode d'emploi :
        // Cette méthode renvoie true si l'utilisateur a été déconnecté, false sinon

        list<double> observerStatistiques(int idCapteur);
        // Mode d'emploi :
        // Cette méthode renvoie une liste de double contenant les moyennes des différents attributs mesurés
        // par le capteur d'id idCapteur

        list<double> observerStatistiquesLieu(double latitude, double longitude, int rayon);
        // Mode d'emploi :
        // Cette méthode renvoie une liste de double contenant les moyennes des différents attributs mesurés 
        // au lieu de coordonnées (latitude, longitude)

        list<double> observerStatistiquesMoment(tm* date);
        // Mode d'emploi :
        // Cette méthode renvoie une liste de double contenant les moyennes des différents attributs mesurés au moment date

        list<Capteur> TrierDonnees(int idCapteur);
        // Mode d'emploi :
        // Cette méthode renvoie une liste de capteur triées par similarité par rapport au capteur d'id idCapteur
        */

//-------------------------------------------- Constructeurs - destructeur
        Utilisateur (const Utilisateur & unUtilisateur);
        // Mode d'emploi (constructeur de copie) :
        // Constructeur de copie de la classe Utilisateur

        Utilisateur();
        // Mode d'emploi (constructeur par défaut) :
        // Constructeur par défaut de la classe Utilisateur

        Utilisateur (string n, string p, string m, string ma);
        // Mode d'emploi :
        // Constructeur de la classe Utilisateur

        virtual ~Utilisateur();
        // Mode d'emploi :
        // Destructeur de la classe Utilisateur

//------------------------------------------------------------------ PRIVE

    protected:

//----------------------------------------------------- Attributs protégés
        string nom, prenom, mdp, mail;

};

//-------------------------------- Autres définitions dépendantes de <Utilisateur>

#endif // Utilisateur_H

