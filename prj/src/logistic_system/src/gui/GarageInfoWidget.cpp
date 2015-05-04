/*
 * GarageInfoWidget.cpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#include "GarageInfoWidget.hpp"
#include "AddGarageDialog.hpp"

void GarageInfoWidget::init()
{
  m_ui.setupUi(this);
  m_garageModel = new GarageModel(this);
  m_ui.garageTable->setModel(m_garageModel);
  m_ui.garageTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  connect(m_ui.addButton, SIGNAL(clicked()), this, SLOT(showAddGarageDialog()));
  connect(m_ui.garageTable->selectionModel(),
      SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex & )),
      this,
      SLOT(updateSelectedRowNumber(const QModelIndex &, const QModelIndex & )));
  connect(m_ui.removeButton, SIGNAL(clicked()), this, SLOT(removeSelected()));
}

void GarageInfoWidget::setRobotManagerData(RobotManagerData* managerData)
{
  m_garageModel->setRobotManagerData(managerData);
  DataManager::setRobotManagerData(managerData);
  updateTotalStorageNumber();
}

void GarageInfoWidget::showAddGarageDialog()
{
  AddGarageDialog addGarageDialog(this);
  if (addGarageDialog.exec() == QDialog::Accepted)
  {
    m_garageModel->addGarage(addGarageDialog.garage());
    updateTotalStorageNumber();
  }
}

void GarageInfoWidget::updateSelectedRowNumber(const QModelIndex & current,
    const QModelIndex & previous)
{
  m_selectedRow = current.row();
  if (!m_ui.removeButton->isEnabled())
    m_ui.removeButton->setEnabled(true);
}

void GarageInfoWidget::removeSelected()
{
  if (m_selectedRow != -1)
  {
    m_garageModel->removeGarageId(m_selectedRow + 1);
    updateTotalStorageNumber();
    if (m_managerData->garageVector().size() == 0)
      m_ui.removeButton->setEnabled(false);
  }
}
