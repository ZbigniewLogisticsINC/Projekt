/*
 *   magazyn.hpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

#ifndef MAGAZYN_HPP
#define MAGAZYN_HPP

/*!
 * \file
 * \brief definicja klasy Magazyn.
 *
 *  Plik zawiera definicje klasy Magazyn
 *  jej konstruktor, destruktor i funkcje
 *  dostepu i zmiany parametrow klasy. 
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*! 
 * \brief Modeluje pojecie Magazyn.
 *
 * Definicja struktury modelujacej pojecie Magazyn
 * o okreslonym  numerze identyfikacyjnym ID,
 * wspolrzednych x i y oraz parametrze dostepnosci  
 * 
 */

class Magazyn {
double wsp_x;  /*! zmienna typu double przechowujaca informacje o wsp. x magazynu */
double wsp_y;  /*! zmienna typu double przechowujaca informacje o wsp. y magazynu */
bool czy_wolny; /*! zmienna typu bool przechowujaca informacje o dostepnosci danego magazynu */
int id;   /*! zmienna typu int przechowujaca identyfikator danego magazynu */
  
public :
		
/*! 
 * \brief Konstruktor elementow dla struktury Magazyn.
 *
 * Wstepnie deklaruje wartosci zapisane do parametrow struktury Magazyn
 * 0 dla zmiennych typu double i int oraz TRUE dla zmiennej typu bool
 */
  Magazyn() { wsp_x = wsp_y = 0; id = 0; czy_wolny = 1;}

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Funkcje dostepu do zmiennych struktury Magazyn

/*! 
 * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_x struktury Magazyn.
 *
 * \return zwraca wsp x danego magazynu.
 */
  const double & WezWspX() const { return wsp_x; }

/*! 
 * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_y struktury Magazyn.
 *
 * \return zwraca wsp y danego magazynu. 
 */
  const double & WezWspY() const { return wsp_y; }

/*! 
 * \brief Umozliwia dostep do prywatnego argumentu (typu bool) czy_wolny struktury Magazyn.
 *
 * \return zwraca parametr dostepnosci danego magazynu. 
 */
  const bool & WezCzyWolny() const { return czy_wolny; }

/*! 
 * \brief zwraca identyfikator (typu int) danego magazynu.
 *
 * \return Umozliwia dostep do numeru identyfikacyjnego danego magazynu.
 */
  const int & WezMagazynId() const { return id; }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
// Funkcje zmieniajace wartosci zmiennych w strukturze Magazyn

/*! 
 * \brief zmienia wartosc pola wsp_x struktury Magazyn.
 *
 * \param      x  -  staly wskaznik typu double do argumentu wsp_x
 *
 */
  void ZmienWspX(const double& x)
  { wsp_x = x;}

/*! 
 * \brief zmienia wartosc pola wsp_y struktury Magazyn.
 *
 * \param      y  -  staly wskaznik typu double do argumentu wsp_y
 *
 */
  void ZmienWspY(const double y)
  { wsp_y = y;}

/*! 
 * \brief zmienia wartosc pola czy_wolny struktury Magazyn.
 *
 * \param      wsp  -  staly wskaznik typu bool do argumentu czy_wolny danego magazynu
 *
 */
  void ZmienCzyWolny(const bool& wsp)
  { czy_wolny = wsp;}

/*! 
 * \brief zmienia wartosc pola id struktury Magazyn.
 *
 * \param      b  -  staly wskaznik typu int do argumentu id
 *
 */
  void ZmienMagazynId(const int &Id)
  { id = Id;}

};

/*!
 * \brief Wczytuje strukture Magazyn przez stdin przeciazajac operator >>
 *
 *  funkcja pozwalajaca na wczytywanie zmiennych klasy Magazyn bezposrednio przez 
 *  funkcje cin przeciazajac operator >>. 
 *
 *  \param[in] StrmWe   -  parametr klasy istream
 *  \param[in]      M   -  parametr klasy Magazyn
 *
 *   parametry StrmWe i M musza byc przekazywane przez referencje
 *  
 *   operator >> dla pierwszego argumentu klasy istream umozliwi wczytanie wartosci
 *   klasy Magazyn z stdin.
 *   Wczytywany argument musi wygladac nastepujaco:
 \verbatim

    wsp_x   wsp_y   id 

 \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy istream
 */
istream & operator >> ( istream & StrmWe, Magazyn & M);

/*!
 * \brief Wypisuje dane magazynu na stdout przeciazajac operator <<
 *
 *  funkcja pozwalajaca na wypisywanie zmiennych klasy Magazyn bezposrednio przez 
 *  funkcje cout przeciazajac operator <<. 
 *
 *  \param[in] StrmWy   -  parametr klasy ostream
 *  \param[in]      M   -  parametr klasy Magazyn
 *
 *   parametr StrmWy musi byc przekazywany przez referencje
 *   parametr M musi byc zmienna klasy Magazyn
 * 
 *   operator << dla pierwszego argumentu klasy ostream umozliwi wypisanie wartosci
 *   klasy Magazyn na stdout.
 *   Wyswietlany argument wyglada nastepujaco:
  \verbatim

    wsp_x   wsp_y   id   czy_wolny

  \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy ostream
 *
 */
ostream & operator << ( ostream & StrmWy, Magazyn M);

#endif
