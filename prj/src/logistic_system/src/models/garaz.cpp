/*
 *   garaz.cpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */


/*!
 * \file
 * \brief Definicje przeciazen dla klasy Garaz
 *
 * Zawiera definicje funkcji przeciazania operatorow wejscia
 * i wyjscia dla klasy Garaz.
 */

#include "garaz.hpp"

istream & operator >> ( istream & StrmWe, Garaz & G)
{  
 double zm1;
 int zm2;
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe;  G.ZmienWspX(&zm1);
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe;  G.ZmienWspY(&zm1);
    StrmWe >> zm2;
    if(StrmWe.fail()) return StrmWe;  G.ZmienGarazId(&zm2);
 
  return StrmWe;
}


ostream & operator << ( ostream & StrmWy, Garaz G)
{
double x, y;
int i;
x=G.WezWspX(); y=G.WezWspY(); i=G.WezGarazId();
  StrmWy << x << "  " << y << "  " << i;
  return StrmWy;
}
