/*
 *   garaz.hpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

#ifndef GARAZ_HPP
#define GARAZ_HPP

/*!
 * \file
 * \brief definicja klasy Garaz.
 *
 *  Plik zawiera definicje klasy Garaz
 *  jej konstruktor, destruktor i funkcje
 *  dostepu i zmiany parametrow klasy. 
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

/*! 
 * \brief Modeluje pojecie Garaz.
 *
 * Definicja struktury modelujacej pojecie Garaz
 * o okreslonym  numerze identyfikacyjnym ID oraz
 * wspolrzednych x i y.  
 * 
 */

class Garaz {
double wsp_x;  /*! zmienna typu double przechowujaca informacje o wsp. x garazu */
double wsp_y;  /*! zmienna typu double przechowujaca informacje o wsp. y garazu */
double wspWej_x; /*! zmienna typu double przechowująca informacje o współrzednej x wejścia garażu */
double wspWej_y; /*! zmienna typu double przechowująca informacje o współrzednej y wejścia garażu */
int id;  /*! zmienna typu int przechowujaca identyfikator garazu */
  
public :
	
/*! 
 * \brief Konstruktor elementow dla struktury Garaz.
 *
 * Wstepnie deklaruje wartosci zapisane do parametrow struktury Garaz
 * 0 dla zmiennych typu double oraz dla zmiennej typu int
 */
  Garaz() { wsp_x = wsp_y = 0; id = 0;}

	
//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
//Funkcje dostepu do zmiennych struktury Garaz

/*! 
 * \brief Umozliwia dostep do prywatnego argumentu (typu duoble) wsp_x struktury Garaz.
 *
 * \return zwraca wsp x danego garazu.
 */
  const double & WezWspX() const { return wsp_x; }

/*! 
 * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_y struktury Garaz.
 *
 * \return zwraca wsp y danego garazu. 
 */
  const double & WezWspY() const { return wsp_y; }


  /*!
   * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_y struktury Garaz.
   *
   * \return zwraca wsp y danego garazu.
   */
  const double & WezWspWejX() const { return wspWej_x; }


  /*!
   * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_y struktury Garaz.
   *
   * \return zwraca wsp y danego garazu.
   */
  const double & WezWspWejY() const { return wspWej_y; }

/*! 
 * \brief zwraca identyfikator (typu int) danego garazu.
 *
 * \return Umozliwia dostep do numeru identyfikacyjnego danego garazu.
 */
  const int & WezGarazId() const { return id; }

//WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
// Funkcje zmieniajace wartosci zmiennych w strukturze Garaz

/*! 
 * \brief zmienia wartosc pola wsp_x struktury Garaz.
 *
 * \param      x  -  staly wskaznik typu double do argumentu wsp_x
 *
 */
  void ZmienWspX(const double x)
  { wsp_x = x;}

/*! 
 * \brief zmienia wartosc pola wsp_y struktury Garaz.
 *
 * \param      y  -  staly wskaznik typu double do argumentu wsp_y
 *
 */
  void ZmienWspY(const double y)
  { wsp_y = y;}

  /*!
   * \brief Metoda pozwalająca zmienić współrzędną x garażu
   * \param x - nowa współrzędna x garażu
   */
  void ZmienWspWejX(const double x)
    { wspWej_x = x;}

  /*!
   * \brief Metoda pozwalająca zmienić współrzędną y garażu
   * \param y - nowa współrzędna y garażu
   */
  void ZmienWspWejY(const double y)
    { wspWej_y = y;}

/*! 
 * \brief zmienia wartosc pola id struktury Garaz.
 *
 * \param Id - argument id
 *
 */
  void ZmienGarazId(const int Id)
  { id = Id;}

};


/*!
 * \brief Wczytuje strukture Garaz przez stdin przeciazajac operator >>
 *
 *  funkcja pozwalajaca na wczytywanie zmiennych klasy Garaz bezposrednio przez 
 *  funkcje cin przeciazajac operator >>. 
 *
 *  \param[in] StrmWe   -  parametr klasy istream
 *  \param[in]      G   -  parametr klasy Garaz
 *
 *   parametry StrmWe i G musza byc przekazywane przez referencje
 *  
 *   operator >> dla pierwszego argumentu klasy istream umozliwi wczytanie wartosci
 *   klasy Garaz z stdin.
 *   Wczytywany argument musi wygladac nastepujaco:
 \verbatim

    wsp_x   wsp_y   id 

 \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy istream
 */
istream & operator >> ( istream & StrmWe, Garaz & G);

/*!
 * \brief Wypisuje dane garazu na stdout przeciazajac operator <<
 *
 *  funkcja pozwalajaca na wypisywanie zmiennych klasy Garaz bezposrednio przez 
 *  funkcje cout przeciazajac operator <<. 
 *
 *  \param[in] StrmWy   -  parametr klasy ostream
 *  \param[in]      G   -  parametr klasy Garaz
 *
 *   parametr StrmWy musi byc przekazywany przez referencje
 *   parametr G musi byc zmienna klasy Garaz
 * 
 *   operator << dla pierwszego argumentu klasy ostream umozliwi wypisanie wartosci
 *   klasy Garaz na stdout.
 *   Wyswietlany argument wyglada nastepujaco:
  \verbatim

    wsp_x   wsp_y   id   

  \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy ostream
 *
 */
ostream & operator << ( ostream & StrmWy, Garaz G);


#endif
