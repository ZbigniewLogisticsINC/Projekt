/*
 * dane_zarzadcy_robotow.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#include "RobotManagerData.hpp"

RobotManagerData::RobotManagerData(QObject* parent)
    : QObject(parent)
{
  QTimer* timer = new QTimer(this);
  timer->setInterval(100);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start();
}

bool RobotManagerData::addRobot(const Robot& robot)
{
  if (containsRobotId(robot.WezRobotId()))
    return false;
  m_robotVector.push_back(robot);
  emit dataUpdated();
  return true;
}

bool RobotManagerData::addStore(const Magazyn& magazyn)
{
  if (containsStoreId(magazyn.WezMagazynId()))
    return false;
  m_storeVector.push_back(magazyn);
  emit dataUpdated();
  return true;
}

bool RobotManagerData::addGarage(const Garaz& garaz)
{
  if (containsGarageId(garaz.WezGarazId()))
    return false;
  m_garageVector.push_back(garaz);
  emit dataUpdated();
  return true;
}

bool RobotManagerData::addTask(const Zadanie& task)
{
  if (containsTaskId(task.WezId()))
    return false;
  m_taskVector.push_back(task);
  emit dataUpdated();
  return true;
}

Robot* RobotManagerData::findRobotId(unsigned int id)
{
  std::vector<Robot>::iterator it = m_robotVector.begin();
  for (; it != m_robotVector.end(); it++)
    if (it->WezRobotId() == id)
      return &*it;
  return nullptr;
}

Magazyn* RobotManagerData::findStoreId(unsigned int id)
{
  std::vector<Magazyn>::iterator it = m_storeVector.begin();
  for (; it != m_storeVector.end(); it++)
    if (it->WezMagazynId() == id)
      return &*it;
  return nullptr;
}

Garaz* RobotManagerData::findGarageId(unsigned int id)
{
  std::vector<Garaz>::iterator it = m_garageVector.begin();
  for (; it != m_garageVector.end(); it++)
    if (it->WezGarazId() == id)
      return &*it;
  return nullptr;
}

bool RobotManagerData::containsRobotId(unsigned int id) const
{
  std::vector<Robot>::const_iterator it = m_robotVector.begin();
  for (; it != m_robotVector.end(); it++)
    if (it->WezRobotId() == id)
      return true;
  return false;
}

bool RobotManagerData::containsStoreId(unsigned int id) const
{
  std::vector<Magazyn>::const_iterator it = m_storeVector.begin();
  for (; it != m_storeVector.end(); it++)
    if (it->WezMagazynId() == id)
      return true;
  return false;
}

bool RobotManagerData::containsGarageId(unsigned int id) const
{
  std::vector<Garaz>::const_iterator it = m_garageVector.begin();
  for (; it != m_garageVector.end(); it++)
    if (it->WezGarazId() == id)
      return true;
  return false;
}

bool RobotManagerData::containsTaskId(unsigned int id) const
{
  std::vector<Zadanie>::const_iterator it = m_taskVector.begin();
  for (; it != m_taskVector.end(); it++)
    if (it->WezId() == id)
      return true;
  return false;
}

bool RobotManagerData::removeTaskId(unsigned int id)
{
  std::vector<Zadanie>::iterator it = m_taskVector.begin();
  for (; it != m_taskVector.end(); it++)
    if (it->WezId() == id)
    {
      m_taskVector.erase(it, it + 1);
      return true;
    }

  return false;
}

bool RobotManagerData::removeStorageId(unsigned int id)
{
  std::vector<Magazyn>::iterator it = m_storeVector.begin();
  for (; it != m_storeVector.end(); it++)
    if (it->WezMagazynId() == id)
    {
      m_storeVector.erase(it, it + 1);
      return true;
    }
  return false;
}

bool RobotManagerData::removeGarageId(unsigned int id)
{
  std::vector<Garaz>::iterator it = m_garageVector.begin();
  for (; it != m_garageVector.end(); it++)
    if (it->WezGarazId() == id)
    {
      m_garageVector.erase(it, it + 1);
      return true;
    }
  return false;
}
