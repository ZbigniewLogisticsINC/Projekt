/*
 * TaskInfoWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "TaskInfoWidget.hpp"
#include "AddTaskDialog.hpp"

void TaskInfoWidget::init()
{
  m_ui.setupUi(this);
  connect(m_ui.addButton, SIGNAL(clicked()), this, SLOT(showAddTaskDialog()));
  m_taskModel = new TaskModel(this);
  m_ui.tasksTable->setModel(m_taskModel);
  m_ui.tasksTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  connect(m_ui.tasksTable->selectionModel(),
      SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)), this,
      SLOT(updateSelectedRowNumber(const QModelIndex &, const QModelIndex &)));
  connect(m_ui.removeButton, SIGNAL(clicked()), this, SLOT(removeSelected()));
}

void TaskInfoWidget::setRobotManagerData(RobotManagerData* managerData)
{
  m_taskModel->setRobotManagerData(managerData);
  DataManager::setRobotManagerData(managerData);
}

void TaskInfoWidget::showAddTaskDialog()
{
  AddTaskDialog addDialog(this);
  addDialog.setRobotManagerData(getRobotManagerData());
  if (addDialog.exec() == QDialog::Accepted && addDialog.taskCorrect())
  {
    m_taskModel->addTask(addDialog.task());
    updateTotalTasksNumber();
  }
}

void TaskInfoWidget::removeSelected()
{
  m_taskModel->removeTaskId(m_currentRowSelected + 1);
  updateTotalTasksNumber();
  if (m_managerData->tasksVector().size() == 0)
    m_ui.removeButton->setEnabled(false);
}

void TaskInfoWidget::updateSelectedRowNumber(const QModelIndex & current,
    const QModelIndex & previous)
{
  m_currentRowSelected = current.row();
  if (!m_ui.removeButton->isEnabled())
    m_ui.removeButton->setEnabled(true);
}

