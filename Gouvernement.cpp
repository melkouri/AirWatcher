/*************************************************************************
                           Gouvernement  -  Classe définissant des utilisateurs qui peuvent accéder à l'application avec des droits spéciaux
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <list>

//------------------------------------------------------ Include personnel
#include "Gouvernement.h"
#include "Cleaner.h"
#include "Client.h"
#include "Capteur.h"
#include "Mesure.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Gouvernement::observerImpactCleaner (Cleaner c, map <string,Capteur> listCapteurs)
{
    double rayon=1; // rayon imposé
    int nombreMesureAv = 0; // compte le nombre de valeurs prises dans les moyennes
    int nombreMesureAp = 0; 
    double moyenneAv = 0; // Moyenne avant l'installation du cleaner (dans le même mois)
    double moyenneAp = 0; // Moyenne aujourd'hui (dans le même mois)
    tm * dateAvant = c.getDateDebut();
    tm * dateApres = c.getDateFin();
    
    double latitude = c.getLatCleaner();
    double longitude = c.getLngCleaner();

    map <string,Capteur> listCapteursProches;
    // Trouver les capteurs proches de c et les rentrer dans la liste capteurProches
    for (map <string,Capteur>::iterator it = listCapteurs.begin(); it != listCapteurs.end(); ++it)
    {
        double latCapteur = it->second.getLatCapteur();
        double lngCapteur = it->second.getLngCapteur();
        if(latCapteur<=(latitude+rayon) && latCapteur>=(latitude-rayon))
        {
            if(lngCapteur<=(longitude+rayon) && lngCapteur>=(longitude-rayon))
            {
                listCapteursProches.insert({it->first,it->second});
            }
        }
    }
    
    if(listCapteursProches.empty())
    {
        cout << "*****************  Augmentez votre rayon de recherche!" << endl;
        return -1;
    } else 
    {
        for (map <string,Capteur>::iterator itc = listCapteursProches.begin(); itc != listCapteursProches.end(); ++itc)
        {
            list <Mesure> mesures = itc->second.getListMesures();
            
            for(list<Mesure>::iterator it = mesures.begin(); it != mesures.end(); it++)
            {
                tm * dateMesure = (*it).getDate();
                if((dateMesure->tm_mon)<=(dateAvant->tm_mon +1) && (dateMesure->tm_mon)>=(dateAvant->tm_mon -1)){ //prise de valeur sur 3 mois pour avoir un meilleur aperçu

                    moyenneAv += (*it).getValeur();
                    ++nombreMesureAv;
                    
                } else if((dateMesure->tm_mon)<=(dateApres->tm_mon +1) && (dateMesure->tm_mon)>=(dateApres->tm_mon -1))
                {
                    moyenneAp += (*it).getValeur();
                    ++nombreMesureAp;
                    
                }
            }
        }

        if(nombreMesureAv!=0 && nombreMesureAp!=0)
        {
            moyenneAv = (double) moyenneAv/nombreMesureAv;
            moyenneAp = (double) moyenneAp/nombreMesureAp;
            
        }else{
            moyenneAv = 0;
            moyenneAv = 0;
        }
        cout << "***************** Observer l'impact d'un cleaner " <<endl;
        cout << "***************** Valeurs moyennes relevées par les capteurs autour du cleaner sélectionné : " << endl;
        cout << "***************** Moyenne avant l'installation du cleaner : " << moyenneAv << endl;
        cout << "***************** Moyenne à la fin de service du cleaner : " << moyenneAp << endl;
        
        if(moyenneAp-moyenneAv < 0){
            cout << "***************** Conclusion : le cleaner a amélioré la qualité de l'air." << endl << endl;
            return 1;
        }else{
            cout << "***************** Conclusion : le cleaner n'a pas amélioré la qualité de l'air." << endl << endl;
            return 0;
        }
        return 0;
    }
} //Fin de la méthode observerImpactCleaner

/*bool Gouvernement::classifieFiabilite(bool fiable, Client client)
{
} //Fin de la méthode classifieFiabilite

int Gouvernement::observerPerformancesAlgo()
{
} //Fin de la méthode observerPerformancesAlgo

bool Gouvernement::verifierFonctionnementCapteur(Capteur capteur)
{
} //Fin de la méthode verifierFonctionnementCapteur */

string Gouvernement::getIdGouv() 
{
    return idGouv;
} //Fin de la méthode getIdGouv

//-------------------------------------------- Constructeurs - destructeur
Gouvernement::Gouvernement (const Gouvernement & unGouvernement)
{
    this->idGouv = unGouvernement.idGouv;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Gouvernement>" << endl;
    #endif
} //Fin de Gouvernement (constructeur de copie)

Gouvernement::Gouvernement()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Gouvernement>" << endl;
    #endif
} //Fin de Gouvernement (constructeur par défaut)

Gouvernement::Gouvernement (string idGouvernement, string unNom, string unPrenom, string unMotDePasse, string unMail) :
 Utilisateur (unNom, unPrenom, unMotDePasse, unMail)
{
    this->idGouv = idGouvernement;
    #ifdef MAP
        cout << "Appel au constructeur de <Gouvernement>" << endl;
    #endif
} //Fin de Gouvernement

Gouvernement::~Gouvernement()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Gouvernement>" << endl;
    #endif
} //Fin de ~Gouvernement

//---------- Fin de la classe <Gouvernement> (fichier Gouvernement.cpp) ------------


