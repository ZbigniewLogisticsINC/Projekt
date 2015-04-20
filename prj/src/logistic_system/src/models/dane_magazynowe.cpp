/*
 *   dane_magazynowe.cpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

/*!
 * \file 
 * \brief Definicje funkcji dla klasy Dane_Magazynowe
 *
 *  Zawiera definicje funkcji wprowadzajacej nowy element
 *  do listy, funkcji czytajacej liste z pliku, funkcji
 *  wyswietlajacej liste, dodajaca nowy element na koniec listy,
 *  pobierajacej element z poczatku listy a takze pobierajaca
 *  element z konca listy.
 */
#include "dane_magazynowe.hpp"

using namespace std;

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Dodanie nowego elementu do listy

void Dane_Magazynowe::DodajZadanie(Zadanie & Z){ Lista_Zadan.push_back(Z); }
void Dane_Magazynowe::DodajRobota(Robot & R){ Lista_Robotow.push_back(R); }
void Dane_Magazynowe::DodajGaraz(Garaz & G){ Lista_Garazow.push_back(G); }
void Dane_Magazynowe::DodajMagazyn(Magazyn & M){ Lista_Magazynow.push_back(M); }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Pobranie ostatniego elementu z listy

Zadanie Dane_Magazynowe::PobierzOstatnieZadanie()
{
  list<Zadanie>::iterator wsk1;
  wsk1 = Lista_Zadan.end();	
  Lista_Zadan.pop_back();
  return *wsk1; }

Robot Dane_Magazynowe::PobierzOstatniegoRobota()
{
  list<Robot>::iterator wsk1;
  wsk1 = Lista_Robotow.end();	
  Lista_Robotow.pop_back();
  return *wsk1; }

Garaz Dane_Magazynowe::PobierzOstatniGaraz()
{
  list<Garaz>::iterator wsk1;
  wsk1 = Lista_Garazow.end();	
  Lista_Garazow.pop_back();
  return *wsk1; }

Magazyn Dane_Magazynowe::PobierzOstatniMagazyn()
{
  list<Magazyn>::iterator wsk1;
  wsk1 = Lista_Magazynow.end();	
  Lista_Magazynow.pop_back();
  return *wsk1; }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Pobranie pierwszego elementu z listy

Zadanie Dane_Magazynowe::PobierzPierwszeZadanie()
{
  list<Zadanie>::iterator wsk1;
  wsk1 = Lista_Zadan.begin();	
  Lista_Zadan.pop_front();
  return *wsk1; }

Robot Dane_Magazynowe::PobierzPierwszegoRobota()
{
  list<Robot>::iterator wsk1;
  wsk1 = Lista_Robotow.begin();	
  Lista_Robotow.pop_front();
  return *wsk1; }

Garaz Dane_Magazynowe::PobierzPierwszyGaraz()
{
  list<Garaz>::iterator wsk1;
  wsk1 = Lista_Garazow.begin();	
  Lista_Garazow.pop_front();
  return *wsk1; }

Magazyn Dane_Magazynowe::PobierzPierwszyMagazyn()
{
  list<Magazyn>::iterator wsk1;
  wsk1 = Lista_Magazynow.begin();	
  Lista_Magazynow.pop_front();
  return *wsk1; }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Wczytanie listy z pliku

bool Dane_Magazynowe::CzytajListeZadanZPliku(const char * sNazwaPliku)
{
  ifstream PlikWe(sNazwaPliku);
  cout << "  Czytanie danych z pliku " << sNazwaPliku << "..." << endl;
  if ( !PlikWe.is_open( ) ) {
    cerr << "Blad otwarcia pliku" << endl;
    return false; }
  Lista_Zadan.clear();

  Zadanie Z;  
  while ( !PlikWe.fail() ) { PlikWe >> Z; DodajZadanie(Z); }
  cout << "    operacja zakonczona powodzeniem." << endl <<endl;
  PlikWe.close();
  return true; }

bool Dane_Magazynowe::CzytajListeRobotowZPliku(const char * sNazwaPliku)
{
  ifstream PlikWe(sNazwaPliku);
  cout << "  Czytanie danych z pliku " << sNazwaPliku << "..." << endl;
  if ( !PlikWe.is_open( ) ) {
    cerr << "Blad otwarcia pliku" << endl;
    return false; }
  Lista_Robotow.clear();

  Robot R;  
  while ( !PlikWe.fail() ) { PlikWe >> R; DodajRobota(R); }
  cout << "    operacja zakonczona powodzeniem." << endl <<endl;
  PlikWe.close();
  return true; }

bool Dane_Magazynowe::CzytajListeGarazowZPliku(const char * sNazwaPliku)
{
  ifstream PlikWe(sNazwaPliku);
  cout << "  Czytanie danych z pliku " << sNazwaPliku << "..." << endl;
  if ( !PlikWe.is_open( ) ) {
    cerr << "Blad otwarcia pliku" << endl;
    return false; }
  Lista_Garazow.clear();

  Garaz G;  
  while ( !PlikWe.fail() ) { PlikWe >> G; DodajGaraz(G); }
  cout << "    operacja zakonczona powodzeniem." << endl <<endl;
  PlikWe.close();
  return true; }

bool Dane_Magazynowe::CzytajListeMagazynowZPliku(const char * sNazwaPliku)
{
  ifstream PlikWe(sNazwaPliku);
  cout << "  Czytanie danych z pliku " << sNazwaPliku << "..." << endl;
  if ( !PlikWe.is_open( ) ) {
    cerr << "Blad otwarcia pliku" << endl;
    return false; }
  Lista_Magazynow.clear();

  Magazyn M;  
  while ( !PlikWe.fail() ) { PlikWe >> M; DodajMagazyn(M); }
  cout << "    operacja zakonczona powodzeniem." << endl <<endl;
  PlikWe.close();
  return true; }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Wyswietlenie listy

void Dane_Magazynowe::WyswietlListeZadan()
{
  if(!(Lista_Zadan.empty())) {
    cout << " -----------------------------------------------------" << endl;
    for (list<Zadanie>::const_iterator Iter=Lista_Zadan.begin(); Iter!=Lista_Zadan.end(); ++Iter)
      { cout << setw(3) << right << *Iter << endl; }
    cout << " -----------------------------------------------------" << endl;  
  }
  else { 
    cerr << "lista zadan jest pusta" << endl;
  }
}
void Dane_Magazynowe::WyswietlListeRobotow()
{
  if(!(Lista_Robotow.empty())) {
    cout << " -----------------------------------------------------" << endl;
    for (list<Robot>::const_iterator Iter=Lista_Robotow.begin(); Iter!=Lista_Robotow.end(); ++Iter)
      { cout << setw(3) << right << *Iter << endl; }
    cout << " -----------------------------------------------------" << endl;  
  }
  else { 
    cerr << "lista robotow jest pusta" << endl;
  }
}
void Dane_Magazynowe::WyswietlListeGarazow()
{
  if(!(Lista_Garazow.empty())) {
    cout << " -----------------------------------------------------" << endl;
    for (list<Garaz>::const_iterator Iter=Lista_Garazow.begin(); Iter!=Lista_Garazow.end(); ++Iter)
      { cout << setw(3) << right << *Iter << endl; }
    cout << " -----------------------------------------------------" << endl;  
  }
  else { 
    cerr << "lista garazow jest pusta" << endl;
  }
}
void Dane_Magazynowe::WyswietlListeMagazynow()
{
  if(!(Lista_Magazynow.empty())) {
    cout << " -----------------------------------------------------" << endl;
    for (list<Magazyn>::const_iterator Iter=Lista_Magazynow.begin(); Iter!=Lista_Magazynow.end(); ++Iter)
      { cout << setw(3) << right << *Iter << endl; }
    cout << " -----------------------------------------------------" << endl;  
  }
  else { 
    cerr << "lista magazynow jest pusta" << endl;
  }
}

