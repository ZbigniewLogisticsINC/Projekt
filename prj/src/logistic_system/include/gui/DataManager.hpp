/*
 * DataManager.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef DATAMANAGER_HPP_
#define DATAMANAGER_HPP_

#include "RobotManagerDataObject.hpp"

class DataManager
{
  public:
    DataManager():m_managerDataObject(new RobotManagerDataObject()) {} //todo uwaga na wyciek pamięci - później poprawić
    void setRobotManagerData(RobotManagerData* managerData) { m_managerDataObject->setRobotManagerData(managerData); }
    const RobotManagerData* getRobotManagerData() const { return m_managerDataObject->getRobotManagerData(); }
  protected:
    RobotManagerDataObject* m_managerDataObject;
};

#endif /* DATAMANAGER_HPP_ */
