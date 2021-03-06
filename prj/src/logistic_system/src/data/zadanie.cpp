/*
 *  zadanie.cpp 
 *
 *  Created on : Apr 19, 2015
 *      Author : doziom2
 *
 */

/*!
 * \file
 * \brief Definicje przeciazen dla klasy Zadanie
 *
 * Zawiera definicje funkcji przeciazania operatorow wejscia
 * i wyjscia dla klasy Macierz.
 */

#include "zadanie.hpp"

istream & operator >>(istream & StrmWe, Zadanie & Z)
{
  int i;
  for (i = 0; i < 3; i++)
  {
    StrmWe >> Z[static_cast<Zadanie::TypDanych>(i)];
    if (StrmWe.fail())
      return StrmWe;
  }
  return StrmWe;
}

ostream & operator <<(ostream & StrmWy, Zadanie Z)
{
  StrmWy << Z[Zadanie::START_MAGAZYN_ID] << "  " << Z[Zadanie::CEL_MAGAZYN_ID]
      << "  " << Z[Zadanie::PREF_ROBOT];
  return StrmWy;
}
