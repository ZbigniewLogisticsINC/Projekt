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
  connect(m_managerDataObject, SIGNAL(dataUpdated()), this,
      SLOT(refreshDataViewed()));
}

void TaskInfoWidget::showAddTaskDialog()
{
  AddTaskDialog addDialog(this);
  addDialog.setRobotManagerData(m_managerDataObject->getRobotManagerData());
  addDialog.exec();
}

void TaskInfoWidget::refreshDataViewed()
{
  m_ui.tasksTable->clear();
  const RobotManagerData *data = getRobotManagerData();
  if (data == nullptr)
    return;

  int row = 0;
  m_ui.tasksTable->insertColumn(0);
  m_ui.tasksTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
  m_ui.tasksTable->insertColumn(1);
  m_ui.tasksTable->setHorizontalHeaderItem(1,
      new QTableWidgetItem("Destination"));
  m_ui.tasksTable->insertColumn(2);
  m_ui.tasksTable->setHorizontalHeaderItem(2,
      new QTableWidgetItem("Preffered Robot"));
  for (std::list<Zadanie>::const_iterator it = data->tasksList().begin();
      it != data->tasksList().end(); it++)
  {
    m_ui.tasksTable->insertRow(row);
    QTableWidgetItem *startStoreId = new QTableWidgetItem(
        tr("%1").arg(it->WezStartMagazynId()));
    m_ui.tasksTable->setItem(row, 0, startStoreId);
    QTableWidgetItem *destStoreId = new QTableWidgetItem(
        tr("%1").arg(it->WezCelMagazynId()));
    m_ui.tasksTable->setItem(row, 1, destStoreId);
    QTableWidgetItem *prefferedRobotId = new QTableWidgetItem(
        tr("%1").arg(it->WezPreferowanegoRobotaId()));
    m_ui.tasksTable->setItem(row, 2, prefferedRobotId);
    row++;
//    m_ui.startStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
//    m_ui.destinationStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
  }

}
