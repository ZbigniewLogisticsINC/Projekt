/*
 * RobotManagerDataObject.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#include "RobotManagerDataObject.hpp"

void RobotManagerDataObject::setRobotManagerData(RobotManagerData* managerData)
{
  m_managerData = managerData;

  emit dataUpdated();
}

