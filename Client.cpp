/*************************************************************************
                           Client  -  Classe  définissant des utilisateurs qui peuvent accéder à l'application
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Client> (fichier Client.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Client.h"
#include "Utilisateur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Client::getIdClient() 
{
    return idClient;
} //Fin de la méthode getIdClient

string Client::getIdCapteur() 
{
    return idCapteur;
} //Fin de la méthode getIdCapteur

int Client::getPoints() 
{
    return points;
} //Fin de la méthode getPoints

bool Client::getFiabilite() 
{
    return fiabilite;
} //Fin de la méthode getFiabilite 

//------------------------------------------------- Surcharge d'opérateurs
bool Client::operator == (const Client & unClient)
// Algorithme : La comparaison de deux clients se fait en fonction de leur id
//
{
    if(idClient == unClient.idClient)
    {
        return true;
    } else
    {
        return false;
    }
} //Fin de operator ==

//-------------------------------------------- Constructeurs - destructeur
Client::Client (const Client & unClient)
{
    idClient = unClient.idClient,
    idCapteur = unClient.idCapteur;

    #ifdef MAP
        cout << "Appel au constructeur de copie de <Client>" << endl;
    #endif
} //Fin de Client (constructeur de copie)

Client::Client ()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Client>" << endl;
    #endif
} //Fin de Client (constructeur par défaut)

Client::Client ( string unIdClient, string unIdCapteur){
    idClient = unIdClient,
    idCapteur = unIdCapteur;
    #ifdef MAP
        cout << "Appel au constructeur de <Client>" << endl;
    #endif
}

/*Client::Client (string unNom, string unPrenom, string unMotDePasse, string unMail, string unIdClient, string unIdCapteur, int desPoints, bool uneFiabilite) : Utilisateur (unNom, unPrenom, unMotDePasse, unMail)
{
    idClient = unIdClient,
    idCapteur = unIdCapteur;
    points = desPoints;
    fiabilite = uneFiabilite;
    #ifdef MAP
        cout << "Appel au constructeur de <Client>" << endl;
    #endif
} //Fin de Client */


Client::~Client()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Client>" << endl;
    #endif
} //Fin de ~Client


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
// int Client::consulterPoints (Client client)
//{
//} //Fin de consulterPoints

//---------- Fin de la classe <Client> (fichier Client.cpp) ------------

