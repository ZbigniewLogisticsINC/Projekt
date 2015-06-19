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
#include <sstream>

std::string Robot::WezNazwe() const
{
  std::ostringstream ossName;

  ossName << "PIONIER" << WezRobotId();

  return ossName.str();
}

bool Robot::updateCoordsFromFile(std::ifstream& file)
{
  if (!file)
    return false;
  double x, y, orient;
  file >> x >> y >> orient;
  if (file)
  {
    wsp_x = x;
    wsp_y = y;
    orientacja = orient;
  }
  return file.good();
}

istream & operator >>(istream & StrmWe, Robot & R)
{
  double zm1;
  int zm2;
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  R.ZmienWspX(zm1);
  StrmWe >> zm1;
  if (StrmWe.fail())
    return StrmWe;
  R.ZmienWspY(zm1);
  StrmWe >> zm2;
  if (StrmWe.fail())
    return StrmWe;
  R.ZmienRobotId(zm2);

  return StrmWe;
}

ostream & operator <<(ostream & StrmWy, Robot R)
{
  double x, y;
  bool w;
  int i;
  x = R.WezWspX();
  y = R.WezWspY();
  w = R.WezCzyWolny();
  i = R.WezRobotId();
  StrmWy << x << "  " << y << "  " << i << "  " << w;
  return StrmWy;
}
