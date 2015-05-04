/*
 * AddTaskDialog.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "AddTaskDialog.hpp"
#include <iostream>

unsigned int AddTaskDialog::s_taskId = 1;

void AddTaskDialog::init()
{
  m_ui.setupUi(this);
  connect(this, SIGNAL(accepted()), this, SLOT(setTaskFromDialog()));
  connect(m_ui.startStorageCombo, SIGNAL(currentIndexChanged(QString)), this,
      SLOT(refreshDestCombo(QString)));
}

void AddTaskDialog::setRobotManagerData(RobotManagerData* managerData)
{
  DataManager::setRobotManagerData(managerData);
  refreshDataViewed();
}

void AddTaskDialog::refreshDataViewed()
{
  m_ui.startStorageCombo->clear();
  m_ui.destinationStorageCombo->clear();
  const RobotManagerData *data = getRobotManagerData();
  if (data == nullptr)
    return;

  for (std::vector<Magazyn>::const_iterator it = data->storeVector().begin();
      it != data->storeVector().end(); it++)
    m_ui.startStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
}

void AddTaskDialog::refreshDestCombo(QString newValue)
{
  m_ui.destinationStorageCombo->clear();
  const RobotManagerData *data = getRobotManagerData();
  unsigned int newStartStoreId = newValue.toUInt();
  for (std::vector<Magazyn>::const_iterator it = data->storeVector().begin();
      it != data->storeVector().end(); it++)
    if (it->WezMagazynId() != newStartStoreId)
      m_ui.destinationStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
}

void AddTaskDialog::setTaskFromDialog()
{
  m_task.ZmienPreferowanegoRobotaId(
      m_ui.robotCombo->currentText().toInt(&m_taskCorrect));
  if (!m_taskCorrect)
    return;
  m_task.ZmienId(s_taskId++);
  m_task.ZmienCelMagazynId(
      m_ui.destinationStorageCombo->currentText().toInt(&m_taskCorrect));
  if (!m_taskCorrect)
    return;
  m_task.ZmienStartMagazynId(
      m_ui.startStorageCombo->currentText().toInt(&m_taskCorrect));
}
