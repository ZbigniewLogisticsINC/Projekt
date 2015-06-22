/*
 *   zadanie.hpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */

#ifndef ZADANIE_HPP
#define ZADANIE_HPP


/*!
 * \file
 * \brief Szablon klasy Zadanie.
 *
 *  Plik zawiera definicje klasy Zadanie oraz
 *  zapowiedzi funkcji przeciazania StrmWe i StrmWy
 *  dla klasy Zadanie.
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*! 
 * \brief Modeluje pojecie Zadanie.
 *
 * Szablon klasy modelujacej pojecie Zadanie
 * o okreslonej wartosci kazdej z trzech wspolrzednych:
 * start_magazyn_id, cel_magazyn_id, pref_robot.
 */
class Zadanie {
  public:

    /*!
     * \brief
     */
    enum Status
    {
      OCZEKIWANIE,//!< oczekiwanie
      W_TRAKCIE,  //!< w trakcie wykonywania
      UKONCZONO   //!< zakończono
    };

    /*!
     * \brief Domyślny konstruktor klasy Zadanie
     * \param idZadania - identyfikator zadania
     * \param startMagazyn - id magazynu początkowego
     * \param celMagazyn - id magazynu końcowego
     * \param preferowanyRobot - identyfikator preferowanego robota
     */
    Zadanie(int idZadania=-1,int startMagazyn=-1, int celMagazyn=-1,int preferowanyRobot=-1 )
      :id(idZadania), start_magazyn_id(startMagazyn), cel_magazyn_id(celMagazyn), pref_robot(preferowanyRobot),
       status(OCZEKIWANIE), robot(-1) { }

    enum TypDanych{ START_MAGAZYN_ID,CEL_MAGAZYN_ID,PREF_ROBOT};
    /*!
     * \brief Przeciazenie operatora indeksujacego dla struktury Zadanie.
     *
     * Umozliwia wywolanie wspolrzednych struktury Zadanie poprzez operator indeksujacy.
     */
    int operator [] (TypDanych dana) const { return dana == START_MAGAZYN_ID ? start_magazyn_id : dana == CEL_MAGAZYN_ID ? cel_magazyn_id : pref_robot; }

    /*!
     * \brief Przeciazenie operatora indeksujacego dla struktury Zadanie.
     *
     * Przeciazenie pozwalajace na prace na zwroconych argumentach struktury Zadanie.
     */
    int & operator [] (TypDanych dana) {  return dana == START_MAGAZYN_ID ? start_magazyn_id : dana == CEL_MAGAZYN_ID ? cel_magazyn_id : pref_robot; }

    /*!
     * \brief Metoda pozwalająca pobrać id magazynu początkowego
     * \return identyfikator magazynu początkowego
     */
    int WezStartMagazynId() const{ return start_magazyn_id; }

    /*!
     * \brief Metoda pozwalająca zmienić identyfikator magazynu początkowego
     * \param nowyId - nowy idetyfikator magazynu początkowego
     */
    void ZmienStartMagazynId(int nowyId) {  start_magazyn_id = nowyId; }

    /*!
     * \brief Metoda pozwalająca pobrać identyfikator magazynu celu
     * \return identyfikator magazynu celu
     */
    int WezCelMagazynId() const { return cel_magazyn_id; }

    /*!
     * \brief Metoda pozwalająca zmienić identyfikator magazynu końcowego
     * \param nowyId - nowy idetyfikator magazynu końcowego
     */
    void ZmienCelMagazynId(int nowyId) { cel_magazyn_id = nowyId; }

    /*!
     * \brief Metoda pozwalająca na pobranie identyfikatora preferowanego robota
     * \return identyfikator preferowanego robota
     */
    int WezPreferowanegoRobotaId() const { return pref_robot; }

    /*!
     * \brief Metoda pozwalająca na zmianę preferowanego robota
     * \param nowyId - identyfikator nowego preferowanego robota
     */
    void ZmienPreferowanegoRobotaId(int nowyId)  { pref_robot = nowyId; }

    /*!
     * \brief Metoda pozwalająca na pobranie identyfikatora zadania
     * \return identyfikator zadania
     */
    int WezId() const { return id; }

    /*!
     * \brief Metoda pozwalająca na pobranie identyfikatora robota, który wykonuje zadanie
     * \return identyfikator robota, który wykonuje zadanie, jeśli nie jest wykonywane zwraca -1
     */
    int WezRobot() const { return robot; }

    /*!
     * \brief Metoda pozwalające na przypisanie identyfikatora robota, który wykonuje zadanie
     * \param nowyIdRobot - nowy identyfikator robota, który wykonuje zadanie
     */
    void ZmienRobot(int nowyIdRobot) { robot = nowyIdRobot; }

    /*!
     * \brief Metoda pozwalająca na zmianę statusu zadania
     * @param nowyStatus - nowy status zadania
     */
    void ZmienStatus(Status nowyStatus) { status = nowyStatus; }

    /*!
     * \brief Metoda pozwalająca na pobranie statusu zadania
     * @return status zadania
     */
    Status WezStatus() const { return status; }

    /*!
     * \brief Metoda pozwalająca zmienić identyfikator zadania
     * \param nowyId - nowy identyfikator zadania
     */
    void ZmienId(int nowyId) { id = nowyId; }
  private:
    int start_magazyn_id; /*! zmienna typu int okreslajaca poczatkowy magazyn sciezki zadania */
    int cel_magazyn_id; /*! zmienna typu int okreslajaca koncowy magazyn sciezki zadania */
    int pref_robot; /*! zmienna typu int okreslajaca preferowanego robota do wykonania zadania */
    int id; /*! zmienna typu int okreslajaca identyfikator zadania */
    int robot; /*! zmienna typu int okreslajaca wykonującego zadanie robota */
    Status status; /*! zmienna typu bool określająca czy zadanie zostało już ukończone */
};

/*!
 * \brief Wczytuje strukture Zadanie przez stdin przeciazajac operator >>
 *
 *  funkcja pozwalajaca na wczytywanie zmiennych klasy Zadanie bezposrednio przez 
 *  funkcje cin przeciazajac operator >>. 
 *
 *  \param[in] StrmWe   -  parametr klasy istream
 *  \param[in]      Z   -  parametr klasy Zadanie
 *
 *   parametry StrmWe i Z musza byc przekazywane przez referencje
 *  
 *   operator >> dla pierwszego argumentu klasy istream umozliwi wczytanie wartosci
 *   klasy Zadanie z stdin.
 *   Wczytywany argument musi wygladac nastepujaco:
 \verbatim

    start_magazyn_id    cel_magazyn_id    pref_robot

 \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy istream
 */
istream & operator >> ( istream & StrmWe, Zadanie & Z);

/*!
 * \brief Wypisuje zadania na stdout przeciazajac operator <<
 *
 *  funkcja pozwalajaca na wypisywanie zmiennych klasy Zadanie bezposrednio przez 
 *  funkcje cout przeciazajac operator <<. 
 *
 *  \param[in] StrmWy   -  parametr klasy ostream
 *  \param[in]      Z   -  parametr klasy Zadanie
 *
 *   parametr StrmWy musi byc przekazywany przez referencje
 *   parametr Z musi byc zmienna klasy Zadanie
 * 
 *   operator << dla pierwszego argumentu klasy ostream umozliwi wypisanie wartosci
 *   klasy Zadanie na stdout.
 *   Wyswietlany argument wyglada nastepujaco:
  \verbatim

     start_magazyn_id    cel_magazyn_id    pref_robot

  \endverbatim
 *
 *   \return Zwraca referencje do pierwszego parametru klasy ostream
 *
 */
ostream & operator << ( ostream & StrmWy, Zadanie Z);

#endif 
