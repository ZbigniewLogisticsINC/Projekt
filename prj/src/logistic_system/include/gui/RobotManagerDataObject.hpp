/*
 * RobotManagerDataObject.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef ROBOTMANAGERDATAOBJECT_HPP_
#define ROBOTMANAGERDATAOBJECT_HPP_

#include <QObject>
#include "RobotManagerData.hpp"

class RobotManagerDataObject:public QObject
{
    Q_OBJECT

  public:
    RobotManagerDataObject(QObject* parent = nullptr):QObject(parent), m_managerData(nullptr) { }
    void setRobotManagerData(RobotManagerData* managerData );
    RobotManagerData* getRobotManagerData() { return m_managerData; }
    void update() { /*todo do zrobienia*/ }
  signals:
    void dataUpdated();
  protected:
    RobotManagerData* m_managerData;
};

#endif /* ROBOTMANAGERDATAOBJECT_HPP_ */
