/*************************************************************************
                           Utilisateur  -  Classe mère définissant des utilisateurs de l'application
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int Utilisateur::observerLieuMoment(double latitude,double longitude,double rayon,tm * date, map <string,Capteur> listCapteurs)
{
    map <string,Capteur> listCapteursProches;
    double moyenneO3 = 0;
    double moyenneNO2 = 0;
    double moyennePM10 = 0;
    double moyenneSO2 = 0;
    int nombreMesures = 0;

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
        for (map <string,Capteur>::iterator it = listCapteursProches.begin(); it != listCapteursProches.end(); ++it)
        {
            list <Mesure> mesures = it->second.getListMesures();
            
            for (list<Mesure>::iterator it = mesures.begin(); it != mesures.end(); it++)
            {
                tm * dateMesure = (*it).getDate();
                string typeMesure = (*it).getIdAttribut();
                if(dateMesure->tm_year == date->tm_year)
                {
                    if((dateMesure->tm_mon)<=(date->tm_mon +1) && (dateMesure->tm_mon)>=(date->tm_mon -1) && (dateMesure->tm_mday)<=(date->tm_mday +1) && (dateMesure->tm_mday)>=(date->tm_mday -1))
                    {
                        if(typeMesure == "NO2")
                        {
                            moyenneNO2 += (*it).getValeur();
                            nombreMesures++;
                        } if(typeMesure == "O3")
                        {
                            moyenneO3 += (*it).getValeur();
                        } if(typeMesure == "PM10")
                        {
                            moyennePM10 += (*it).getValeur();
                        } if(typeMesure == "SO2")
                        {
                            moyenneSO2 += (*it).getValeur();
                        } 
                    }
                }
            }
        }

        if(nombreMesures != 0){
            moyenneNO2 = (double) moyenneNO2/nombreMesures;
            moyenneO3 = (double) moyenneO3/nombreMesures;
            moyennePM10 = (double) moyennePM10/nombreMesures;
            moyenneSO2 = (double) moyenneSO2/nombreMesures;
            
        }
        cout << "***************** Observer statistiques "<< endl;
        cout << "***************** Plages de dates du " << date->tm_year << "-" << date->tm_mon << "-" << date->tm_mday -1 << "  au  " << date->tm_year << "-" << date->tm_mon << "-" << date->tm_mday +1 << endl;
        cout << "***************** dans la zone de latitude " << latitude << " et de longitude " << longitude << " avec un rayon de " << rayon << endl;
        cout << "***************** moyenneNO2: " << moyenneNO2 << " µg/m3" << endl;
        cout << "***************** moyenneO3: " << moyenneO3 << " µg/m3" << endl;
        cout << "***************** moyennePM10: " << moyennePM10 << " µg/m3" << endl;
        cout << "***************** moyenneSO2: " << moyenneSO2 << " µg/m3" << endl << endl;
        //cout << "nombre de mesures réalisées : " << nombreMesures << endl;
        int moyenne=0;
        if(moyenneO3>=0  && moyenneO3<=54){
            moyenne+=2;
        }
        if(moyenneO3>54  && moyenneO3<=104){
            moyenne+=1;
        }
        if(moyenneO3>129  && moyenneO3<=179){
            moyenne-=1;
        }
        if(moyenneO3>179){
            moyenne-=2;
        }

        if(moyenneSO2>=0  && moyenneSO2<=79){
            moyenne+=2;
        }
        if(moyenneSO2>79  && moyenneSO2<=159){
            moyenne+=1;
        }
        if(moyenneSO2>199  && moyenneSO2<=299){
            moyenne-=1;
        }
        if(moyenneSO2>299 ){
            moyenne-=2;
        }

        if(moyenneNO2>=0  && moyenneNO2<=54){
            moyenne+=2;
        }if(moyenneNO2>54  && moyenneNO2<=109){
            moyenne+=1;
        }if(moyenneNO2>134  && moyenneNO2<=199){
            moyenne-=1;
        }if(moyenneNO2>199){
            moyenne-=2;
        }

        if(moyennePM10>=0  && moyennePM10<=13){
            moyenne+=2;
        }if(moyennePM10>13  && moyennePM10<=27){
            moyenne+=1;
        }if(moyennePM10>34  && moyennePM10<=49){
            moyenne-=1;
        }if(moyennePM10>49){
            moyenne-=2;
        }
        
        if(moyenne>=5) cout << "***************** Niveau de qualite de l'air : Très Bon" << endl << endl;
        if(moyenne>=3 && moyenne<5) cout << "***************** Niveau de qualite de l'air :  Bon" << endl << endl;
        if(moyenne>=-3 && moyenne<3) cout << "***************** Niveau de qualite de l'air : Moyen" << endl << endl;
        if(moyenne>=-5 && moyenne<-3) cout << "***************** Niveau de qualite de l'air : Médiocre" << endl << endl;
        if(moyenne<-5) cout << "***************** Niveau de qualite de l'air : Mauvais" << endl << endl;
        return 0;
    }

} //Fin de la méthode observerLieuMoment

string Utilisateur::getNom()
{
    return nom;
} //Fin de la méthode getNom

string Utilisateur::getPrenom()
{
    return prenom;
} //Fin de la méthode getPrenom

string Utilisateur::getMdp()
{
    return mdp;
} //Fin de la méthode getMdp

string Utilisateur::getMail()
{
    return mail;
} //Fin de la méthode getMail

/*
bool seConnecter(string mail, string mdp) 
{
} //Fin de la méthode seConnecter

bool seDeconnecter() 
{
} //Fin de la méthode seDeconnecter

list<double> observerStatistiques(int idCapteur) 
{
} //Fin de la méthode observerStatistiques

list<double> observerStatistiquesLieu(double latitude, double longitude, int rayon)
{
} //Fin de la méthode observerStatistiquesLieu

list<double> observerStatistiquesMoment(tm* date)
{
} //Fin de la méthode observerStatistiquesMoment

list<Capteur> TrierDonnees(int idCapteur)
{
} //Fin de la méthode TrierDonnees
*/

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur (const Utilisateur & unUtilisateur)
{
    nom = unUtilisateur.nom;
    prenom = unUtilisateur.prenom;
    mdp = unUtilisateur.mdp;
    mail = unUtilisateur.mail;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
    #endif
} //Fin de Utilisateur (constructeur de copie)

Utilisateur::Utilisateur()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Utilisateur>" << endl;
    #endif
} //Fin de Utilisateur (constructeur par défaut)

Utilisateur::Utilisateur (string n, string p, string m, string ma)
{
    nom = n; 
    prenom = p;
    mdp = m;
    mail = ma;
    #ifdef MAP
        cout << "Appel au constructeur de <Utilisateur>" << endl;
    #endif
} //Fin de Utilisateur 


Utilisateur::~Utilisateur()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Utilisateur>" << endl;
    #endif
} //Fin de ~Utilisateur

//---------- Fin de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------
