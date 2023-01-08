/*************************************************************************
                           Main  -  classe principale (Gestion)
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par  B3122 - EL KOURI Malak - LE POLLES Mayline 
                                    &    B3132 - BOUSSEAU Clément - LECLERCQ--CUVELIER Inès - VIGNERON Chloé
    e-mail               : malak.el-kouri@insa-lyon.fr - mayline.le-polles@insa-lyon.fr
                           clement.bousseau@insa-lyon.fr - ines.leclercq---cuvelier@insa-lyon.fr  - chloe.vigneron@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

//------------------------------------------------------ Include personnel
#include "Capteur.h"
#include "Client.h"
#include "Mesure.h"
#include "Attribut.h"
#include "Utilisateur.h"
#include "Gouvernement.h"
#include "Cleaner.h"
#include "Fournisseur.h"

///////////////////////////////////////////////////////////////////  PRIVE

//------------------------------------------------------ Fonctions privées
map <string,Client> chargerDonneesClient (string fileName)
// Mode d'emploi : 
// On parcourt le fichier users.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
//
// Algorithme : 
// Une map ayant pour clé l'id du capteur et son deuxième élément est le client
//
{
  ifstream file;
  file.open(fileName);
  map < string, Client > m;
  if (file.is_open()) 
  {
    string idUtilisateur;
    string idCapteur;
    while (!file.eof())
    {
      getline(file, idUtilisateur, ';');
      getline(file, idCapteur, ';');
      file.ignore(256, '\n');
      Client client = Client(idUtilisateur,idCapteur);
      m.insert({idCapteur,client});
    }
  }
  file.close();
  return m;
} //Fin de la méthode chargerDonneesClient

map <string,Fournisseur> chargerDonneesFournisseur (string fileName)
// Mode d'emploi : 
// On parcourt le fichier users.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
//
// Algorithme : 
// Une map ayant pour clé l'id du capteur et son deuxième élément est le fournisseur
//
{
  ifstream file;
  file.open(fileName);
  map < string, Fournisseur > m;
  if (file.is_open()) 
  {
    string idFournisseur;
    string idCleaner;
    while (!file.eof())
    {
      getline(file, idFournisseur, ';');
      getline(file, idCleaner, ';');
      file.ignore(256, '\n');
      Fournisseur fournisseur = Fournisseur(idFournisseur,idCleaner);
      m.insert({idFournisseur,fournisseur});
    }
  }
  file.close();
  return m;
} //Fin de la méthode chargerDonneesFournisseur

vector <Attribut> chargerDonneesAttribut (string fileName)
// Mode d'emploi :
// On parcourt le fichier attributes.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
// 
// Algorithme :
// Un vector ayant pour clé un Attribut
//
{
  ifstream file;
  file.open(fileName);
  vector <Attribut> m;
  if (file.is_open()) 
  {
    string idAttribut;
    string unite;
    string description;
    while (!file.eof())
    {
      getline(file, idAttribut, ';');
      getline(file, unite, ';');
      getline(file, description, ';');
      file.ignore(256, '\n');
      Attribut a =  Attribut (idAttribut,unite,description);
      m.push_back (a);
    }
  }
  file.close();
  return m;
} //Fin de la méthode chargerDonneesAttribut

map <string,Capteur> chargerDonneesCapteur (string fileName)
// Mode d'emploi :
// On parcourt le fichier sensors.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
// 
// Algorithme :
// Une map ayant pour clé l'id du capteur et son deuxième élément est le capteur
//
{
  ifstream file;
  file.open(fileName);
  map <string,Capteur> m;
  if (file.is_open()) 
  {
    string idCapteur;
    string latCapteur;
    string lngCapteur;
    while (!file.eof())
    {
      getline(file, idCapteur, ';');
      getline(file, latCapteur, ';');
      getline(file, lngCapteur, ';');
      file.ignore(256, '\n');
      double lat = stod(latCapteur);
      double lng = stod(lngCapteur);
      Capteur c =  Capteur (idCapteur,lat,lng);
      m.insert({idCapteur,c});
    }
  }
  file.close();
  return m;
} //Fin de la méthode chargerDonneesCapteur

map <string,Cleaner> chargerDonneesCleaner (string fileName)
// Mode d'emploi :
// On parcourt le fichier cleaners.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
// 
// Algorithme :
// Une map ayant pour clé l'id du cleaner et son deuxième élément est le cleaner
//
{
  ifstream file;
  file.open(fileName);
  map <string,Cleaner> m;
  if (file.is_open()) 
  {
    string idCleaner;
    string latCleaner;
    string lngCleaner;
    string dDebut;
    string dFin;
    while (!file.eof())
    {
      getline(file, idCleaner, ';');
      getline(file, latCleaner, ';');
      getline(file, lngCleaner, ';');

      getline(file, dDebut, ';');
      getline(file, dFin, ';');   
      file.ignore(256, '\n');
    
      double lat = stod(latCleaner);
      double lng = stod(lngCleaner);

      if(!dDebut.empty()){
        struct tm * dateDebut = new tm();
        dateDebut->tm_year = stoi(dDebut.substr(0,4));
        dateDebut->tm_mon = stoi(dDebut.substr(5,2));
        dateDebut->tm_mday = stoi(dDebut.substr(8,2));

        struct tm * dateFin = new tm();
        dateFin->tm_year = stoi(dFin.substr(0,4));
        dateFin->tm_mon = stoi(dFin.substr(5,2));
        dateFin->tm_mday = stoi(dFin.substr(8,2));
        Cleaner cleaner =  Cleaner (idCleaner,lat,lng,dateDebut,dateFin);
        m.insert({idCleaner,cleaner});
      }
    }
  }
  file.close();
  return m;
} //Fin de la méthode chargerDonneesCleaner

void chargerDonneesMesures (string fileName, map <string,Capteur> * capteurs)
// Mode d'emploi : 
// On parcourt le fichier measurments.csv ligne par ligne, 
// les données d'une ligne sont séparées par des points virgules
// 
// Algorithme : 
// Remplit la liste de mesures de chaque capteur
//
{
  ifstream file;
  file.open(fileName);
  if (file.is_open()) 
  {

    string idCapteur;
    string idAttribut;
    string valeur;

    string date;

    while (!file.eof())
    {

      getline(file, date, ';'); 
      getline(file, idCapteur, ';');
      getline(file, idAttribut, ';');
      getline(file, valeur, ';');
      file.ignore(256, '\n');
      double val = stod(valeur);

      if(!date.empty()){ 
        tm * dateM = new tm();
        dateM->tm_year = stoi(date.substr(0,4));
        dateM->tm_mon = stoi(date.substr(5,2));
        dateM->tm_mday = stoi(date.substr(8,2));

        Mesure  mesure = Mesure (idAttribut,dateM,val);
        map <string,Capteur>::iterator itCapteur = (*capteurs).find(idCapteur);
        (itCapteur->second).addListMesures(mesure);
      }
    }
  }
  file.close();
} //Fin de la méthode chargerDonneesMesures

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int affichage(map <string,Client>  donneesClients, map <string,Capteur> donneesCapteurs, map <string,Cleaner> donneesCleaners )
{
  int buffer;
  int bufferdeux;
  int buffertrois;
  int bufferquatre;
  int buffercinq;
  int buffersix;
  int buffersept;

  while(1)
  {
    cout << "************* AirWatcher *************" << endl;
    cout << "Vous êtes :" << endl
    << "\t1 Particulier" << endl
    << "\t2 Fournisseur" << endl
    << "\t3 Gouvernement" << endl
    << "\t4 -Quitter AirWatcher-" << endl << endl;
    cin >> buffer;

    switch(buffer)
    {
      case 1 :
      {
        bool boucle1 = true;
        while(boucle1)
        {
          cout << "Vous souhaitez : " << endl
          << "\t1 Rechercher et observer capteurs" << endl
          << "\t2 Consulter mes points" << endl
          << "\t3 Retour" <<endl << endl;
          cin >> bufferdeux;

          switch(bufferdeux)
          {
            case 1 :
            {
              bool boucle2 = true;
              while(boucle2)
              {
                cout << "Vous souhaitez : " << endl
                << "\t1 Voir les statistiques" << endl
                << "\t2 Faire une recherche specifique" << endl
                << "\t3 Trier les données" << endl
                << "\t4 Retour" <<endl << endl;
                cin >> buffertrois;

                switch(buffertrois)
                {
                  case 1 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 2 :
                  { 
                    Utilisateur u;
                    double latitude;
                    double longitude;
                    double rayon;
                    struct tm* date = new tm();
                    string sdate;
                    cout << "Latitude : " << endl;
                    cin >> latitude;
                    cout << "Longitude : " << endl;
                    cin >> longitude;
                    cout << "Rayon : " << endl;
                    cin >> rayon;
                    cout << "Date (format : DD:MM:YYYY) :" << endl;
                    cin >> sdate;
                    cout << "******************* TEST fonctionnalité 1 : observerLieuMoment *******************" << endl;
                    chrono::time_point<chrono::high_resolution_clock> start1 = chrono::high_resolution_clock::now(); //début du chrono
                    date->tm_mday = stoi(sdate.substr(0,2));
                    date->tm_mon = stoi(sdate.substr(3,2));
                    date->tm_year = stoi(sdate.substr(6,4));

                    u.observerLieuMoment(latitude, longitude, rayon, date, donneesCapteurs); 
                    chrono::time_point<chrono::high_resolution_clock> end1 = chrono::high_resolution_clock::now(); //fin du chrono
                    chrono::duration<double> duree1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1); // durée du test
                    cout << "Temps d'exécution du TEST fonctionnalité 1 : observerLieuMoment : " << duree1.count() << "s" << endl;
                    cout << endl;
                    cout << endl;
                  }
                  break;
                  case 3 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 4 : 
                  {
                  boucle2 = false;
                  }
                  break;
                }
              }
            }
            break;
            case 2 :
            {
              cout << "---------------------" << endl;
              cout << "Pas encore disponible" << endl;
              cout << "---------------------" << endl;
            }
            break;
            case 3 :
            {
            boucle1 = false;
            affichage(donneesClients, donneesCapteurs, donneesCleaners);
            }
            break;
          }
        }
      }
      break;
      case 2 :
      {
        bool boucle3 = true;
        while(boucle3)
        {
          cout << "Vous souhaitez : " << endl
          << "\t1 Rechercher et observer capteurs" << endl
          << "\t2 Observer l'impact des Cleaners" << endl
          << "\t3 Retour" << endl <<endl;
          cin >> bufferquatre;

          switch(bufferquatre)
          {
            case 1 :
            {
              bool boucle6 = true;
              while(boucle6)
              {
                cout << "Vous souhaitez : " << endl
                << "\t1 Voir les statistiques" << endl
                << "\t2 Faire une recherche specifique" << endl
                << "\t3 Trier les données" << endl
                << "\t4 Retour" << endl <<endl;
                cin >> buffersept;

                switch(buffersept)
                  {
                  case 1 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 2 :
                  { //observerLieuMoment
                    Utilisateur u;
                    double latitude;
                    double longitude;
                    double rayon;
                    struct tm* date = new tm();
                    string sdate;
                    cout << "Latitude : " << endl;
                    cin >> latitude;
                    cout << "Longitude : " << endl;
                    cin >> longitude;
                    cout << "Rayon : " << endl;
                    cin >> rayon;
                    cout << "Date (format : DD:MM:YYYY) :" << endl;
                    cin >> sdate;
                    cout << "******************* TEST fonctionnalité 1 : observerLieuMoment *******************" << endl;
                    chrono::time_point<chrono::high_resolution_clock> start1 = chrono::high_resolution_clock::now(); //début du chrono
                    date->tm_mday = stoi(sdate.substr(0,2));
                    date->tm_mon = stoi(sdate.substr(3,2));
                    date->tm_year = stoi(sdate.substr(6,4));

                    u.observerLieuMoment(latitude, longitude, rayon, date, donneesCapteurs); 
                    chrono::time_point<chrono::high_resolution_clock> end1 = chrono::high_resolution_clock::now(); //fin du chrono
                    chrono::duration<double> duree1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1); // durée du test
                    cout << "Temps d'exécution du TEST fonctionnalité 1 : observerLieuMoment : " << duree1.count() << "s" << endl;
                    cout << endl;
                    cout << endl;
                  }
                  break;
                  case 3 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 4 : 
                  {
                    boucle6 = false;
                  }
                  break;
                  }
              }
            }
            break;
            case 2 :
            { 
              cout << "Seul le gouvernement peut accéder à cette  information pour l'instant" << endl;
            }
            break;
            case 3 :
            {
              boucle3=false; 
              affichage(donneesClients, donneesCapteurs, donneesCleaners);
            }
            break;
          }
        }
      }
      break;
      case 3 :
      {
        bool boucle4 = true;
        while(boucle4)
        {
          cout << "Vous souhaitez : " << endl
          << "\t1 Rechercher et observer capteurs" << endl
          << "\t2 Observer l'impact des Cleaners" << endl
          << "\t3 Vérifier le fonctionnement des capteurs" << endl
          << "\t4 Gérer les utilisateurs" << endl
          << "\t5 Observer la performance des algorithmes" << endl
          << "\t6 Retour" << endl <<endl;
          cin >> buffercinq;

          switch(buffercinq)
          {
            case 1 :
            {
              bool boucle5 = true;
              while(boucle5)
              {
                cout << "Vous souhaitez : " << endl
                << "\t1 Voir les statistiques" << endl
                << "\t2 Faire une recherche specifique" << endl
                << "\t3 Trier les données" << endl
                << "\t4 Retour" << endl <<endl;
                cin >> buffersix;

                switch(buffersix)
                  {
                  case 1 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 2 :
                  { // ObserverLieuMoment
                    Utilisateur u;
                    double latitude;
                    double longitude;
                    double rayon;
                    struct tm* date = new tm();
                    string sdate;
                    cout << "Latitude : " << endl;
                    cin >> latitude;
                    cout << "Longitude : " << endl;
                    cin >> longitude;
                    cout << "Rayon : " << endl;
                    cin >> rayon;
                    cout << "Date (format : DD:MM:YYYY) :" << endl;
                    cin >> sdate;
                    cout << "******************* TEST fonctionnalité 1 : observerLieuMoment *******************" << endl;
                    chrono::time_point<chrono::high_resolution_clock> start1 = chrono::high_resolution_clock::now(); //début du chrono
                    date->tm_mday = stoi(sdate.substr(0,2));
                    date->tm_mon = stoi(sdate.substr(3,2));
                    date->tm_year = stoi(sdate.substr(6,4));

                    u.observerLieuMoment(latitude, longitude, rayon, date, donneesCapteurs); 
                    chrono::time_point<chrono::high_resolution_clock> end1 = chrono::high_resolution_clock::now(); //fin du chrono
                    chrono::duration<double> duree1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1); // durée du test
                    cout << "Temps d'exécution du TEST fonctionnalité 1 : observerLieuMoment : " << duree1.count() << "s" << endl;
                    cout << endl;
                    cout << endl;
                  }
                  break;
                  case 3 :
                  {
                    cout << "---------------------" << endl;
                    cout << "Pas encore disponible" << endl;
                    cout << "---------------------" << endl;
                  }
                  break;
                  case 4 : 
                  {
                    boucle5 = false;
                  }
                  break;
                  }
              }
            }
            break;
            case 2 :
            { //observerImpactCleaner
                
                Gouvernement gouv;
                string idCleaner;
                cout << "ID du cleaner :" << endl;
                cin >> idCleaner;
                cout << "******************* TEST fonctionnalité 2 : observerImpactCleaner *******************" << endl;
                chrono::time_point<chrono::high_resolution_clock> start1 = chrono::high_resolution_clock::now(); //début du chrono
                map <string,Cleaner>::iterator ite = donneesCleaners.find(idCleaner);
                Cleaner *cleaner = new Cleaner();
                cleaner=&(ite->second);

                gouv.observerImpactCleaner(*cleaner, donneesCapteurs);
                chrono::time_point<chrono::high_resolution_clock> end1 = chrono::high_resolution_clock::now(); //fin du chrono
                chrono::duration<double> duree1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1); // durée du test
                cout << "Temps d'exécution du TEST fonctionnalité 2 : observerImpactCleaner : " << duree1.count() << "s" << endl;
                
                cout << endl;
                cout << endl;
            }
            break;
            case 3 :
            {
              cout << "---------------------" << endl;
              cout << "Pas encore disponible" << endl;
              cout << "---------------------" << endl;
            }
            break;
            case 4 :
            {
              cout << "---------------------" << endl;
              cout << "Pas encore disponible" << endl;
              cout << "---------------------" << endl;
            }
            break;
            case 5 :
            {
              cout << "---------------------" << endl;
              cout << "Pas encore disponible" << endl;
              cout << "---------------------" << endl;
            }
            break;
            case 6 :
            {
            boucle4 = false;
            affichage(donneesClients, donneesCapteurs, donneesCleaners);
            }
            break;
          }
        }
        break;
      }
      case 4 :
      {
        return 0;
      }
      break;
    }
    break;
  }
  return 0;
}


int main ()
{
  chrono::time_point<chrono::high_resolution_clock> start, end;
  chrono::duration<double> duree;

  cout << "******************* TEST chargerDonneesClient *******************" << endl;
  start = chrono::high_resolution_clock::now(); //début du chrono
  map <string,Client>  donneesClients = chargerDonneesClient("users.csv");
  for(map <string,Client>::iterator it = donneesClients.begin ( ) ; it != donneesClients.end ( ) ; ++it) 
  {
      cout << "idUtilisateur : " << it->first << " idClient : " << it->second.getIdClient()  << " idCapteur : " << it->second.getIdCapteur()<< endl;
  }
  end = chrono::high_resolution_clock::now(); //fin du chrono
  duree = chrono::duration_cast<chrono::duration<double>>(end - start); // durée du test
  cout << "Temps d'exécution du TEST chargerDonneesClient : " << duree.count() << "s" << endl;

  cout << endl;
  cout << endl;

  cout << "******************* TEST chargerDonneesAttribut *******************" << endl;
  start = chrono::high_resolution_clock::now(); //début du chrono
  vector <Attribut> donneesAttributs = chargerDonneesAttribut("attributes.csv");
  for(vector<Attribut>::iterator it = donneesAttributs.begin ( ) ; it != donneesAttributs.end ( ) ; ++it) 
  {
      cout << (*it).getIdAttribut() << " " << (*it).getUnite() << " " << (*it).getDescription() << endl;
  }
  end = chrono::high_resolution_clock::now(); //fin du chrono
  duree = chrono::duration_cast<chrono::duration<double>>(end - start); // durée du test
  cout << "Temps d'exécution du TEST chargerDonneesAttribut : " << duree.count() << "s" << endl;

  cout << endl;
  cout << endl;

  cout << "******************* TEST chargerDonneesCapteur *******************" << endl;
  start = chrono::high_resolution_clock::now(); //début du chrono
  map <string,Capteur> donneesCapteurs = chargerDonneesCapteur("sensors.csv");
  /*for(map <string,Capteur>::iterator it = donneesCapteurs.begin ( ) ; it != donneesCapteurs.end ( ) ; ++it) 
  {
      cout << it->first << "  " << it->second.getLatCapteur()<< endl;
  }*/
  end = chrono::high_resolution_clock::now(); //fin du chrono
  duree = chrono::duration_cast<chrono::duration<double>>(end - start); // durée du test
  cout << "Temps d'exécution du TEST chargerDonneesCapteur : " << duree.count() << "s" << endl;

  cout << endl;
  cout << endl;

  cout << "******************* TEST chargerDonneesMesures *******************" << endl;
  start = chrono::high_resolution_clock::now(); //début du chrono
  chargerDonneesMesures ("measurements.csv",&donneesCapteurs);
/*  for(map <string,Capteur>::iterator it = donneesCapteurs.begin ( ) ; it != donneesCapteurs.end ( ) ; ++it) 
  {
      //cout << it->first << endl;
      list <Mesure> mesures=it->second.getListMesures();
      for(list<Mesure>::iterator itt=mesures.begin();itt!=mesures.end();itt++)
      {
        cout << it->first << "*********" << (*itt).getValeur() << endl;
      }
  }*/
  end = chrono::high_resolution_clock::now(); //fin du chrono
  duree = chrono::duration_cast<chrono::duration<double>>(end - start); // durée du test
  cout << "Temps d'exécution du TEST chargerDonneesMesures : " << duree.count() << "s" << endl;

  cout << endl;
  cout << endl;

  cout << "******************* TEST chargerDonneesCleaner *******************" << endl;
  start = chrono::high_resolution_clock::now(); //début du chrono
  map <string,Cleaner> donneesCleaners = chargerDonneesCleaner("cleaners.csv");
  /* // Test fonctionnement du chargement des valeurs
  for(map <string,Cleaner>::iterator it = donneesCleaners.begin(); it != donneesCleaners.end(); ++it)
  {
    cout <<"idCleaner  "<< it->first <<"     datecleaner  " << it->second.getDateDebut()->tm_year << "/" << it->second.getDateDebut()->tm_mon << endl;
  }
  */
  end = chrono::high_resolution_clock::now(); //fin du chrono
  duree = chrono::duration_cast<chrono::duration<double>>(end - start); // durée du test
  cout << "Temps d'exécution du TEST chargerDonneesCleaner : " << duree.count() << "s" << endl;

  cout << endl;
  cout << endl;  

  affichage(donneesClients, donneesCapteurs, donneesCleaners);
} //Fin de main

