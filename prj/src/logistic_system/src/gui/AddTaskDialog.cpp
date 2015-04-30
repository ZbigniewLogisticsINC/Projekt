/*
 * AddTaskDialog.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */


#include "AddTaskDialog.hpp"
#include <iostream>

void AddTaskDialog::init()
{
	m_ui.setupUi(this);
	connect(m_managerDataObject,SIGNAL(dataUpdated()),this,SLOT(refreshDataViewed()));
}

void AddTaskDialog::refreshDataViewed()
{
	std::cout<<"JEST\n";
	const RobotManagerData* data = getRobotManagerData();
	static int i = 1;
	m_ui.destinationStorageCombo->addItem(tr("Numer: %0").arg(i));
	i++;
}
