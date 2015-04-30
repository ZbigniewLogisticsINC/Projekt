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

  connect(m_managerDataObject, SIGNAL(dataUpdated()), this,
      SLOT(refreshDataViewed()));
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

  for (std::list<Magazyn>::const_iterator it = data->storeList().begin();
      it != data->storeList().end(); it++)
  {
    m_ui.startStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
    m_ui.destinationStorageCombo->addItem(tr("%0").arg(it->WezMagazynId()));
  }
}
