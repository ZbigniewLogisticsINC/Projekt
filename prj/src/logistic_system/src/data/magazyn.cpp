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

istream & operator >>(istream & StrmWe, Magazyn & M)
{
  double zm1;
  int zm2;
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  M.ZmienWspX(zm1);
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  M.ZmienWspY(zm1);
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  M.ZmienWspWejX(zm1);
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  M.ZmienWspWejY(zm1);
  StrmWe >> zm2;
  if (StrmWe.fail())
    return StrmWe;
  M.ZmienMagazynId(zm2);

  return StrmWe;
}

ostream & operator <<(ostream & StrmWy, Magazyn M)
{
  bool w = M.WezCzyWolny();
  int i = M.WezMagazynId();
  double x = M.WezWspX(), y = M.WezWspY(), xwej = M.WezWspWejX(), ywej =
      M.WezWspWejY();
  StrmWy << x << "  " << y << "  " << xwej << "  " << ywej << "  " << i << "  "
      << w;
  return StrmWy;
}
