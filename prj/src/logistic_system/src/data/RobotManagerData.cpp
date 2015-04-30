/*
 * dane_zarzadcy_robotow.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#include "RobotManagerData.hpp"

RobotManagerData::RobotManagerData(QObject* parent) :
		QObject(parent)
{
	QTimer* timer = new QTimer(this);
	timer->setInterval(100);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start();
}

bool RobotManagerData::addRobot(const Robot& robot) {
	if (containsRobotId(robot.WezRobotId()))
		return false;
	m_robotList.push_back(robot);
	return true;
}

bool RobotManagerData::addStore(const Magazyn& magazyn) {
	if (containsStoreId(magazyn.WezMagazynId()))
		return false;
	m_storeList.push_back(magazyn);
	return true;
}

bool RobotManagerData::addGarage(const Garaz& garaz) {
	if (containsGarageId(garaz.WezGarazId()))
		return false;
	m_garageList.push_back(garaz);
	return true;
}

Robot* RobotManagerData::addRobotId(unsigned int id) {
	std::list<Robot>::iterator it = m_robotList.begin();
	for (; it != m_robotList.end(); it++)
		if (it->WezRobotId() == id)
			return &*it;
	return nullptr;
}

Magazyn* RobotManagerData::findStoreId(unsigned int id) {
	std::list<Magazyn>::iterator it = m_storeList.begin();
	for (; it != m_storeList.end(); it++)
		if (it->WezMagazynId() == id)
			return &*it;
	return nullptr;
}

Garaz* RobotManagerData::findGarageId(unsigned int id) {
	std::list<Garaz>::iterator it = m_garageList.begin();
	for (; it != m_garageList.end(); it++)
		if (it->WezGarazId() == id)
			return &*it;
	return nullptr;
}

bool RobotManagerData::containsRobotId(unsigned int id) const {
	std::list<Robot>::const_iterator it = m_robotList.begin();
	for (; it != m_robotList.end(); it++)
		if (it->WezRobotId() == id)
			return true;
	return false;
}

bool RobotManagerData::containsStoreId(unsigned int id) const {
	std::list<Magazyn>::const_iterator it = m_storeList.begin();
	for (; it != m_storeList.end(); it++)
		if (it->WezMagazynId() == id)
			return true;
	return false;
}

bool RobotManagerData::containsGarageId(unsigned int id) const {
	std::list<Garaz>::const_iterator it = m_garageList.begin();
	for (; it != m_garageList.end(); it++)
		if (it->WezGarazId() == id)
			return true;
	return false;
}
