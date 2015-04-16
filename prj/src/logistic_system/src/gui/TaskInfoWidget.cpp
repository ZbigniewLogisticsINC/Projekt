/*
 * TaskInfoWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "TaskInfoWidget.hpp"
#include "AddTaskDialog.hpp"
#include "TasksModel.hpp"

void TaskInfoWidget::init()
{
	m_ui.setupUi(this);
	connect(m_ui.addButton, SIGNAL(clicked()), this, SLOT(showAddTaskDialog()));
	TasksModel* model=new TasksModel();
	model->pushBack(Task(1,2));
	model->pushBack(Task(2,3));
	model->pushBack(Task(3,4));
	m_ui.tableView->setModel(model);
}

void TaskInfoWidget::showAddTaskDialog()
{
	AddTaskDialog addDialog(this);
	addDialog.exec();
}
