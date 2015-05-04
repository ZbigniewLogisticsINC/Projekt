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
    DataManager():m_managerData(nullptr) { }
    virtual void setRobotManagerData(RobotManagerData* managerData) { m_managerData = managerData; }
    RobotManagerData* getRobotManagerData()  { return m_managerData; }
    virtual ~DataManager() { }
  protected:
    RobotManagerData* m_managerData;

};

#endif /* DATAMANAGER_HPP_ */
