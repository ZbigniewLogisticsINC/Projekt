/*
 *   robot.cpp 
 *
 *   Created on : Apr 19, 2015
 *       Author : doziom2
 *
 */


/*!
 * \file
 * \brief Definicje przeciazen dla klasy Robot
 *
 * Zawiera definicje funkcji przeciazania operatorow wejscia
 * i wyjscia dla klasy Robot.
 */

#include "robot.hpp"

istream & operator >> ( istream & StrmWe, Robot & R)
{  
 double zm1;
 int zm2;
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe;  R.ZmienWspX(zm1);
    StrmWe >> zm1;
    if(StrmWe.fail()) return StrmWe;  R.ZmienWspY(zm1);
    StrmWe >> zm2;
    if(StrmWe.fail()) return StrmWe;  R.ZmienRobotId(zm2);
 
  return StrmWe;
}


ostream & operator << ( ostream & StrmWy, Robot R)
{
 double x, y;
 bool w;
 int i;
 x=R.WezWspX(); y=R.WezWspY(); w=R.WezCzyWolny(); i=R.WezRobotId();
  StrmWy << x << "  " << y << "  " << i << "  " << w;
  return StrmWy;
}
