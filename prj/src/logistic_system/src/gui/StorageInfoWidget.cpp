/*
 * StorageInfoWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "StorageInfoWidget.hpp"
#include "AddStorageDialog.hpp"

void StorageInfoWidget::init()
{
  m_ui.setupUi(this);
  m_storageModel = new StorageModel(this);
  m_ui.storesTable->setModel(m_storageModel);
  m_ui.storesTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  connect(m_ui.addButton, SIGNAL(clicked()), this,
      SLOT(showAddStorageDialog()));
  connect(m_ui.storesTable->selectionModel(),
      SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex & )),
      this,
      SLOT(updateSelectedRowNumber(const QModelIndex &, const QModelIndex & )));
  connect(m_ui.removeButton, SIGNAL(clicked()), this, SLOT(removeSelected()));
}

void StorageInfoWidget::setRobotManagerData(RobotManagerData* managerData)
{
  m_storageModel->setRobotManagerData(managerData);
  DataManager::setRobotManagerData(managerData);
  updateTotalStorageNumber();
}

void StorageInfoWidget::showAddStorageDialog()
{
  AddStorageDialog addStorageDialog(this);
  if (addStorageDialog.exec() == QDialog::Accepted)
  {
    m_storageModel->addStore(addStorageDialog.store());
    updateTotalStorageNumber();
  }
}

void StorageInfoWidget::updateSelectedRowNumber(const QModelIndex & current,
    const QModelIndex & previous)
{
  m_selectedRow = current.row();
  if (!m_ui.removeButton->isEnabled())
    m_ui.removeButton->setEnabled(true);
}

void StorageInfoWidget::removeSelected()
{
  if (m_selectedRow != -1)
  {
    m_storageModel->removeStoreId(m_selectedRow + 1);
    updateTotalStorageNumber();
    if (m_managerData->storeVector().size() == 0)
      m_ui.removeButton->setEnabled(false);
  }
}

void StorageInfoWidget::refreshDataViewed()
{

}
