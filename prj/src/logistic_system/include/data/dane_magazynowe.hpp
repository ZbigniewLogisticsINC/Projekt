/*
 *   dane_magazynowe.hpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

#ifndef DANE_MAGAZYNOWE_HPP
#define DANE_MAGAZYNOWE_HPP

/*!
 * \file
 * \brief Deklaracja klasy Dane_Magazynowe.
 *
 *  Plik zawiera definicje klasy Dane_Magazynowe, zawierajaca
 *  listy zadan, robotow, garazow i magazynow, deklaracje
 *  metod klasy takich jak czytania listy z pliku,
 *  dodania elementu do listy, usuwania i pobrania elementu
 *  ostatniego i pierwszego  oraz wyswietlania listy na stdout
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <list>
#include "zadanie.hpp"
#include "robot.hpp"
#include "garaz.hpp"
#include "magazyn.hpp"

using namespace std;

/*! 
 * \brief Modeluje pojecie Dane_Magazynowe.
 *
 * Klasa modelujaca pojecie Dane_Magazynowe
 * zawierajaca:
 *   - liste zadan do wykonania,
 *   - liste dostepnych robotow,
 *   - liste dostepnych garazow,
 *   - liste dostepnych magazynow.
 */

class Dane_Magazynowe {
  list <Zadanie> Lista_Zadan; /*! lista zadan utworzona na bazie struktury Zadanie  */
  list <Robot> Lista_Robotow; /*! lista robotow utworzona na bazie struktury Robot  */
  list <Garaz> Lista_Garazow; /*! lista garazy utworzona na bazie struktury Garaz  */
  list <Magazyn> Lista_Magazynow; /*! lista magazynow utworzona na bazie struktury Magazyn  */
public:
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Dodanie nowego elementu do listy

/*! 
 * \brief dodaje nowy element do listy zadan.
 *
 *  Metoda dodajaca nowy element do listy Lista_Zadan zawierajacy informacje
 *  o id magazynu startowego, id magazynu docelowego i preferowanym numerze
 *  robota do wykonania zadania.
 *
 * \param    Z  -  argument struktury Zadanie zawierajacy pelna informacje o jednym zadaniu
 */
  void DodajZadanie(Zadanie & Z);

/*! 
 * \brief dodaje nowy element do listy robotow.
 *
 *  Metoda dodajaca nowy element do listy Lista_Robotow zawierajacy informacje
 *  o wspolrzednych x oraz y robota numerze id oraz zmiennej dostepnosci robota.
 *
 * \param    R  -  argument struktury Robot zawierajacy pelna informacje o jednym robocie
 */
  void DodajRobota(Robot & R);

/*! 
 * \brief dodaje nowy element do listy garazy.
 *
 *  Metoda dodajaca nowy element do listy Lista_Garazow zawierajacy informacje
 *  o wspolrzednych x oraz y garazu i numerze id garazu.
 *
 * \param    G  -  argument struktury Garaz zawierajacy pelna informacje o jednym garazu
 */
  void DodajGaraz(Garaz & G);

/*! 
 * \brief dodaje nowy element do listy magazynow.
 *
 *  Metoda dodajaca nowy element do listy Lista_Magazynow zawierajacy informacje
 *  o wspolrzednych x oraz y magazynu, numerze id oraz zmiennej dostepnosci magazynu.
 *
 * \param    M  -  argument struktury Magazyn zawierajacy pelna informacje o jednym magazynie
 */
  void DodajMagazyn(Magazyn & M);

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Pobranie ostatniego elementu z listy

/*! 
 * \brief usuwa ostatni element z listy zadan i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca ostatni element z listy Lista_Zadan zawierajacy informacje
 *  o id magazynu startowego, id magazynu docelowego i preferowanym numerze
 *  robota do wykonania zadania.
 * 
 * \return Zwraca wskaznik na strukture Wektor z danymi ostatniego zadania na liscie
 */
  Zadanie PobierzOstatnieZadanie();

/*! 
 * \brief usuwa ostatni element z listy robotow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca ostatni element z listy Lista_Robotow zawierajacy informacje
 *  o wspolrzednych x oraz y robota numerze id oraz zmiennej dostepnosci robota.
 * 
 * \return Zwraca wskaznik na strukture Robot z danymi ostatniego robota na liscie
 */
  Robot PobierzOstatniegoRobota();

/*! 
 * \brief usuwa ostatni element z listy garazow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca ostatni element z listy Lista_Garazow zawierajacy informacje
 *  o wspolrzednych x oraz y garazu i numerze id garazu.
 * 
 * \return Zwraca wskaznik na strukture Garaz z danymi ostatniego garazu na liscie
 */
  Garaz PobierzOstatniGaraz();

/*! 
 * \brief usuwa ostatni element z listy magazynow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca ostatni element z listy Lista_Magazynow zawierajacy informacje
 *  o wspolrzednych x oraz y magazynu, numerze id oraz zmiennej dostepnosci magazynu.
 * 
 * \return Zwraca wskaznik na strukture Magazyn z danymi ostatniego magazynu na liscie
 */
  Magazyn PobierzOstatniMagazyn();

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Pobranie pierwszego elementu z listy

/*! 
 * \brief usuwa pierwszy element z listy zadan i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca pierwszy element z listy Lista_Zadan zawierajacy informacje
 *  o id magazynu startowego, id magazynu docelowego i preferowanym numerze
 *  robota do wykonania zadania.
 * 
 * \return Zwraca strukture Zadanie z danymi pierwszego zadania na liscie
 */
  Zadanie PobierzPierwszeZadanie();

/*! 
 * \brief usuwa pierwszy element z listy robotow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca pierwszy element z listy listy Lista_Robotow zawierajacy informacje
 *  o wspolrzednych x oraz y robota numerze id oraz zmiennej dostepnosci robota.
 * 
 * \return Zwraca strukture Robot z danymi pierwszego robota na liscie
 */
  Robot PobierzPierwszegoRobota();

/*! 
 * \brief usuwa pierwszy element z listy garazow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca pierwszy element z listy Lista_Garazow zawierajacy informacje
 *  o wspolrzednych x oraz y garazu i numerze id garazu.
 * 
 * \return Zwraca strukture Garaz z danymi pierwszego garazu na liscie
 */
  Garaz PobierzPierwszyGaraz();

/*! 
 * \brief usuwa pierwszy element z listy magazynow i zwraca jego zawartosc.
 *
 *  Metoda usuwajaca pierwszy element z listy Lista_Magazynow zawierajacy informacje
 *  o wspolrzednych x oraz y magazynu, numerze id oraz zmiennej dostepnosci magazynu.
 * 
 * \return Zwraca strukture Magazyn z danymi pierwszego magazynu na liscie
 */
  Magazyn PobierzPierwszyMagazyn();

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Wczytywanie danych z pliku do listy

/*! 
 * \brief wczytuje dane do listy zadan.
 *
 * Metoda czytajaca kolejne linie z pliku podane w argumencie funkcji i zapisuje
 * informacje do listy Lista_Zadan
 *
 * \param sNazwaPliku  -  staly wskaznik typu char do nazwy pliku wejsciowego
 *
 * \return Zwraca true jesli uda sie wczytac dane i false w przeciwnym wypadku.
 */
  bool CzytajListeZadanZPliku(const char* sNazwaPliku);

/*! 
 * \brief wczytuje dane do listy robotow.
 *
 * Metoda czytajaca kolejne linie z pliku podane w argumencie funkcji i zapisuje
 * informacje do listy Lista_Robotow
 *
 * \param sNazwaPliku  -  staly wskaznik typu char do nazwy pliku wejsciowego
 *
 * \return Zwraca true jesli uda sie wczytac dane i false w przeciwnym wypadku.
 */
  bool CzytajListeRobotowZPliku(const char* sNazwaPliku);

/*! 
 * \brief wczytuje dane do listy garazow.
 *
 * Metoda czytajaca kolejne linie z pliku podane w argumencie funkcji i zapisuje
 * informacje do listy Lista_Garazow
 *
 * \param sNazwaPliku  -  staly wskaznik typu char do nazwy pliku wejsciowego
 *
 * \return Zwraca true jesli uda sie wczytac dane i false w przeciwnym wypadku.
 */
  bool CzytajListeGarazowZPliku(const char* sNazwaPliku);

/*! 
 * \brief wczytuje dane do listy magazynow.
 *
 * Metoda czytajaca kolejne linie z pliku podane w argumencie funkcji i zapisuje
 * informacje do listy Lista_Magazynow
 *
 * \param sNazwaPliku  -  staly wskaznik typu char do nazwy pliku wejsciowego
 *
 * \return Zwraca true jesli uda sie wczytac dane i false w przeciwnym wypadku.
 */
  bool CzytajListeMagazynowZPliku(const char* sNazwaPliku);

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Wyswietlanie listy

/*! 
 * \brief wyswietla liste zadan.
 *
 *  Metoda wyswietlajaca na stdout liste zadan. Jesli lista jest pusta zwracany jest
 *  odpowieni komunikat.
 * 
 */
  void WyswietlListeZadan();

/*! 
 * \brief wyswietla liste robotow.
 *
 *  Metoda wyswietlajaca na stdout liste robotow. Jesli lista jest pusta zwracany jest
 *  odpowieni komunikat.
 * 
 */
  void WyswietlListeRobotow();

/*! 
 * \brief wyswietla liste garazow.
 *
 *  Metoda wyswietlajaca na stdout liste garazow. Jesli lista jest pusta zwracany jest
 *  odpowieni komunikat.
 * 
 */
  void WyswietlListeGarazow();

/*! 
 * \brief wyswietla liste magazynow.
 *
 *  Metoda wyswietlajaca na stdout liste magazynow. Jesli lista jest pusta zwracany jest
 *  odpowieni komunikat.
 * 
 */
  void WyswietlListeMagazynow();

};


#endif 
