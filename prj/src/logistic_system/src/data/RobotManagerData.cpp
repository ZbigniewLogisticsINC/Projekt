/*
 * dane_zarzadcy_robotow.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#include "RobotManagerData.hpp"
#include <cstdlib>
#include <sstream>

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

Zadanie* RobotManagerData::findTaskId(unsigned id)
{
  std::vector<Zadanie>::iterator it = m_taskVector.begin();
  for (; it != m_taskVector.end(); it++)
    if (it->WezId() == id)
      return &*it;
  return nullptr;
}

int RobotManagerData::findFreeRobotForTask(unsigned taskId)
{
  int ID = -1;
  Magazyn *magazyn, *cel;
  double najkrotsza_trasa = numeric_limits<double>::max(), trasa;

  const std::vector<Zadanie>& listazadan = tasksVector();
  const std::vector<Robot>& listarobotow = robotVector();

  for (std::vector<Zadanie>::const_iterator it1 = listazadan.begin();
      it1 != listazadan.end(); it1++)
  {
    if (it1->WezId() == taskId)
    {
      magazyn = findStoreId(it1->WezStartMagazynId());
      cel = findStoreId(it1->WezCelMagazynId());
      for (std::vector<Robot>::const_iterator it2 = listarobotow.begin();
          it2 != listarobotow.end(); it2++)
      {
        if (it2->WezCzyWolny())
        {
          trasa = pow(it2->WezWspX() - magazyn->WezWspX(), 2) // nie trzeba sqrt, tylko dodatkowe obliczenia
          + pow(it2->WezWspY() - magazyn->WezWspY(), 2)
              + pow(magazyn->WezWspX() - cel->WezWspX(), 2)
              + pow(magazyn->WezWspY() - cel->WezWspY(), 2);

          if (trasa < najkrotsza_trasa)
            ID = it2->WezRobotId();
        }   //if
      } //for
    }   //if
  } //for
  return ID;
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

bool RobotManagerData::removeRobotId(unsigned int id)
{
  std::vector<Robot>::iterator it = m_robotVector.begin();
  for (; it != m_robotVector.end(); it++)
    if (it->WezRobotId() == id)
    {
      m_robotVector.erase(it, it + 1);
      return true;
    }
  return false;
}

bool RobotManagerData::changeTaskStatusOnCompletedId(unsigned id)
{
  Zadanie* task = findTaskId(id);
  Robot* robot = findRobotId(task->WezRobot());
  if (task == nullptr || robot == nullptr)
    return false;

  task->ZmienStatus(Zadanie::UKONCZONO);
  task->ZmienRobot(-1);
  robot->ZmienCzyWolny(true);
  return true;
}

void RobotManagerData::runNextTasks(std::vector<unsigned>& runNextTasksId)
{
  for (int i = 0; i < m_taskVector.size(); i++)
  {
    Zadanie& task = m_taskVector[i];
    if (task.WezStatus() == Zadanie::OCZEKIWANIE)
    {
      int robotId = findFreeRobotForTask(task.WezId());
      std::cout << "Robot id: " << robotId << std::endl;
      if (robotId >= 0)
      {
        Robot* robot = findRobotId(robotId);
        if (robot != nullptr)
          robot->ZmienCzyWolny(false);
        runNextTasksId.push_back(task.WezId());
        task.ZmienRobot(robotId);
        task.ZmienStatus(Zadanie::W_TRAKCIE);
      }
    }
  }

  emit dataUpdated();
}

void RobotManagerData::update(const std::string& dirPath)
{
  for (int i = 0; i < m_robotVector.size(); i++)
  {
    const Robot& robot = m_robotVector[i];
    std::ostringstream ossCommand, ossOutputFile;
    ossOutputFile << dirPath << robot.WezNazwe();
    ossCommand
        << "python /home/mochman/politechnika/projekt_zespolowy/prj/src/logistic_system/python/zapisz_pozycje_robota.py "
        << robot.WezNazwe() << " " + ossOutputFile.str();
//    std::cout << ossOutputFile.str() << ":" << ossCommand.str() << ":"
//        << system(ossCommand.str().c_str()) << std::endl;
    system(ossCommand.str().c_str());
    std::ifstream file(ossOutputFile.str());
    m_robotVector[i].updateCoordsFromFile(file);
  }

  emit dataUpdated();
}
