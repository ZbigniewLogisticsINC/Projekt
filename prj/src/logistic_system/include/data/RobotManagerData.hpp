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
    Robot* addRobotId(unsigned int id);
    Magazyn* findStoreId(unsigned int id);
    Garaz* findGarageId(unsigned int id);
    bool containsStoreId(unsigned int id) const;
    bool containsGarageId(unsigned int id) const;
    bool containsRobotId(unsigned int id) const;
    const std::list<Zadanie> tasksList() const { return m_taskList; }
public slots:
    void update() { static int i=1;Robot r;r.ZmienRobotId(i);addRobot(r); emit dataUpdated(); }
signals:
  void dataUpdated();
private:
    std::list<Zadanie> m_taskList;
    std::list<Magazyn> m_storeList;
    std::list<Garaz> m_garageList;
    std::list<Robot> m_robotList;
};

#endif /* ROBOT_MANAGER_DATA_HPP_ */
