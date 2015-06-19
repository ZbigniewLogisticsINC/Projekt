/*
 * robot_manager_data.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef ROBOT_MANAGER_DATA_HPP_
#define ROBOT_MANAGER_DATA_HPP_

#include <QObject>
#include "zadanie.hpp"
#include "robot.hpp"
#include "magazyn.hpp"
#include "garaz.hpp"
#include <list>
#include <QTimer>
class RobotManagerData: public QObject
{
  Q_OBJECT
  public:
  RobotManagerData(QObject* parent = nullptr);
  bool addRobot(const Robot& robot);
  bool addStore(const Magazyn& magazyn);
  bool addGarage(const Garaz& garaz);
  bool addTask(const Zadanie& task);
  Robot* findRobotId(unsigned int id);
  Magazyn* findStoreId(unsigned int id);
  Garaz* findGarageId(unsigned int id);
  Zadanie* findTaskId(unsigned id);
  bool containsStoreId(unsigned int id) const;
  bool containsGarageId(unsigned int id) const;
  bool containsRobotId(unsigned int id) const;
  bool containsTaskId(unsigned int id) const;
  bool removeTaskId(unsigned int id);
  bool removeStorageId(unsigned int id);
  bool removeGarageId(unsigned int id);
  bool removeRobotId(unsigned int id);
  bool changeTaskStatusOnCompletedId(unsigned id);
  const std::vector<Zadanie>& tasksVector() const { return m_taskVector; }
  const std::vector<Magazyn>& storeVector() const { return m_storeVector; }
  const std::vector<Robot>& robotVector() const { return m_robotVector; }
  const std::vector<Garaz>& garageVector() const { return m_garageVector; }
  void setTaskStarted(unsigned taskId);
public slots:
  //void update() {  emit dataUpdated(); }
  void update(const std::string& dirPath);
signals:
  void dataUpdated();
private:
  std::vector<Zadanie> m_taskVector;
  std::vector<Magazyn> m_storeVector;
  std::vector<Garaz> m_garageVector;
  std::vector<Robot> m_robotVector;
};

#endif /* ROBOT_MANAGER_DATA_HPP_ */
