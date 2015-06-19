/*
 *   robot.hpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

#ifndef ROBOT_HPP
#define ROBOT_HPP

/*!
 * \file
 * \brief definicja klasy Robot.
 *
 *  Plik zawiera definicje klasy Robot
 *  jej konstruktor, destruktor i funkcje
 *  dostepu i zmiany parametrow klasy. 
 */

#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

/*! 
 * \brief Modeluje pojecie Robot.
 *
 * Definicja struktury modelujacej pojecie Robot
 * o okreslonych bierzacych wspolrzednych robota 
 * numeru identyfikacyjnego ID oraz dostepnosci.
 */

class Robot {
  double wsp_x;  /*! zmienna typu double przechowujaca informacje o biezacej wsp. x robota */
  double wsp_y;  /*! zmienna typu double przechowujaca informacje o biezacej wsp. y robota */
  double orientacja;
  int id;  /*! zmienna typu int przechowujaca identyfikator robota */
  bool czy_wolny; /*! zmienna typu bool przechowujaca informacje o dostepnosci danego robota */
  int garazId;
public :

  /*! 
   * \brief Konstruktor elementow dla struktury Robot.
   *
   * Wstepnie deklaruje wartosci zapisane do parametrow struktury Robot
   * 0 dla zmiennych typu double i int oraz TRUE dla zmiennej typu bool
   */
  Robot() { wsp_x = wsp_y = 0; id = 0; czy_wolny = 1;garazId = 0;}

  //WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
  //Funkcje dostepu do zmiennych struktury Robot

  /*! 
   * \brief Umozliwia dostep do prywatnego argumentu (typu double) wsp_x struktury Robot.
   *
   * \return zwraca biezaca wsp x robota.
   */
  const double & WezWspX() const { return wsp_x; }

  /*! 
   * \brief Umozliwia dostep do prywatnego argumentu (typu duoble) wsp_y struktury Robot.
   *
   * \return zwraca biezaca wsp y robota. 
   */
  const double & WezWspY() const { return wsp_y; }

  /*! 
   * \brief Umozliwia dostep do prywatnego argumentu (typu bool) czy_wolny struktury Robot.
   *
   * \return zwraca parametr dostepnosci danego robota. 
   */
  const bool & WezCzyWolny() const { return czy_wolny; }

  /*! 
   * \brief zwraca identyfikator (typu int) danego robota.
   *
   * \return Umozliwia dostep do numeru identyfikacyjnego danego robota.
   */
  const int & WezRobotId() const { return id; }


  const int& WezGarazId() const { return garazId; }

  std::string WezNazwe() const;

  //WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW
  // Funkcje zmieniajace wartosci zmiennych w strukturze Robot

  /*! 
   * \brief zmienia wartosc pola wsp_x struktury Robot.
   *
   * \param      x  -  staly wskaznik typu double do argumentu wsp_x
   *
   */
  void ZmienWspX(const double& x)
  { wsp_x = x;}

  /*! 
   * \brief zmienia wartosc pola wsp_y struktury Robot.
   *
   * \param      y  -  staly wskaznik typu double do argumentu wsp_y
   *
   */
  void ZmienWspY(const double& y)
  { wsp_y = y;}

  /*! 
   * \brief zmienia wartosc pola czy_wolny struktury Robot.
   *
   * \param      wsp  -  staly wskaznik typu bool do argumentu czy_wolny 
   *
   */
  void ZmienCzyWolny(const bool wsp)
  { czy_wolny = wsp;}

  /*! 
   * \brief zmienia wartosc pola id struktury Robot.
   *
   * \param Id  -  nowy identyfikator robota
   *
   */
  void ZmienRobotId(const int& Id)
  { id = Id;}


  void ZmienGarazId(const int& id) { garazId = id; }

  /*!
   * \brief Metoda pozwalająca aktualizować dane robota na podstawie pliku
   * 
   */

  bool updateCoordsFromFile(std::ifstream& file);
};


/*!
 * \brief Wczytuje strukture Robot przez stdin przeciazajac operator >>
 *
 *  funkcja pozwalajaca na wczytywanie zmiennych klasy Robot bezposrednio przez 
 *  funkcje cin przeciazajac operator >>. 
 *
 *  \param[in] StrmWe   -  parametr klasy istream
 *  \param[in]      R   -  parametr klasy Robot
 *
 *   parametry StrmWe i R musza byc przekazywane przez referencje
 *  
 *   operator >> dla pierwszego argumentu klasy istream umozliwi wczytanie wartosci
 *   klasy Robot z stdin.
 *   Wczytywany argument musi wygladac nastepujaco:
 \verbatim

 wsp_x   wsp_y   id 

 \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy istream
 */
istream & operator >> ( istream & StrmWe, Robot & R);

/*!
 * \brief Wypisuje dane robotow na stdout przeciazajac operator <<
 *
 *  funkcja pozwalajaca na wypisywanie zmiennych klasy Robot bezposrednio przez 
 *  funkcje cout przeciazajac operator <<. 
 *
 *  \param[in] StrmWy   -  parametr klasy ostream
 *  \param[in]      R   -  parametr klasy Robot
 *
 *   parametr StrmWy musi byc przekazywany przez referencje
 *   parametr R musi byc zmienna klasy Robot
 * 
 *   operator << dla pierwszego argumentu klasy ostream umozliwi wypisanie wartosci
 *   klasy Robot na stdout.
 *   Wyswietlany argument wyglada nastepujaco:
 \verbatim

 wsp_x   wsp_y   id   czy_wolny

 \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy ostream
 *
 */
ostream & operator << ( ostream & StrmWy, Robot R);


#endif
