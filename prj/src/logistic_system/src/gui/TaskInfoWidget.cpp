/*
 * TaskInfoWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "TaskInfoWidget.hpp"
#include "AddTaskDialog.hpp"
#include "ZadanieModel.hpp"

void TaskInfoWidget::init()
{
	m_ui.setupUi(this);
	connect(m_ui.addButton, SIGNAL(clicked()), this, SLOT(showAddTaskDialog()));
}

void TaskInfoWidget::showAddTaskDialog()
{
	AddTaskDialog addDialog(this);
	addDialog.setRobotManagerData(m_managerDataObject->getRobotManagerData());
	addDialog.exec();
}

void TaskInfoWidget::refreshDataViewed()
{
}
