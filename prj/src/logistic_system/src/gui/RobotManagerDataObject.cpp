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
  connect(m_managerData, SIGNAL(dataUpdated()), this, SIGNAL(dataUpdated()));
  emit dataUpdated();
}
