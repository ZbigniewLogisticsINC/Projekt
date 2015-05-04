/*
 * StoreModel.cpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#include "StorageModel.hpp"

void StorageModel::setRobotManagerData(RobotManagerData* data)
{
  beginResetModel();
  DataManager::setRobotManagerData(data);
  endResetModel();
}

bool StorageModel::addStore(const Magazyn& storage)
{
  bool result = false;
  if (m_managerData != nullptr)
  {
    beginInsertRows(QModelIndex(), m_managerData->storeVector().size() + 1,
        m_managerData->storeVector().size() + 1);
    result = m_managerData->addStore(storage);
    endInsertRows();
  }
  return result;
}

bool StorageModel::removeStoreId(unsigned int id)
{
  beginRemoveRows(QModelIndex(), id - 1, id - 1);
  m_managerData->removeStorageId(id);
  endRemoveRows();
}

int StorageModel::rowCount(const QModelIndex &parent) const
{
  return m_managerData != nullptr ? m_managerData->storeVector().size() : 0;
}

int StorageModel::columnCount(const QModelIndex &parent) const
{
  return 3;
}
QVariant StorageModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
  if (role == Qt::DisplayRole)
  {
    if (orientation == Qt::Horizontal)
    {
      switch (section)
      {
        case 0:
          return tr("id");
        case 1:
          return tr("y coordinate");
        case 2:
          return tr("x coordinate");
      }
    }
    else
      if (orientation == Qt::Vertical)
        return section + 1;
  }
  return QVariant();
}

QVariant StorageModel::data(const QModelIndex &index, int role) const
{
  if (m_managerData == nullptr)
    return QVariant();
  if (role == Qt::DisplayRole)
    switch (index.column())
    {
      case 0:
        return m_managerData->storeVector()[index.row()].WezMagazynId();
      case 1:
        return m_managerData->storeVector()[index.row()].WezWspX();
      case 2:
        return m_managerData->storeVector()[index.row()].WezWspY();
    }
  return QVariant();
}

