/*
 *   magazyn.cpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */



/*!
 * \file
 * \brief Definicje przeciazen dla klasy Magazyn
 *
 * Zawiera definicje funkcji przeciazania operatorow wejscia
 * i wyjscia dla klasy Magazyn.
 */

#include "magazyn.hpp"

istream & operator >> ( istream & StrmWe, Magazyn & M)
{  
 double zm1;
 int zm2;
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe; M.ZmienWspX(&zm1);
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe; M.ZmienWspY(&zm1);
    StrmWe >> zm2;
    if(StrmWe.fail()) return StrmWe; M.ZmienMagazynId(&zm2);
 
  return StrmWe;
}


ostream & operator << ( ostream & StrmWy, Magazyn M)
{
double x, y;
bool w;
int i;
x=M.WezWspX(); y=M.WezWspY(); w=M.WezCzyWolny(); i=M.WezMagazynId();
  StrmWy << x << "  " << y << "  " << i << "  " << w;
  return StrmWy;
}
