/*
 * GarageModel.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#include "GarageModel.hpp"

void GarageModel::setRobotManagerData(RobotManagerData* data)
{
  beginResetModel();
  DataManager::setRobotManagerData(data);
  endResetModel();
}

bool GarageModel::addGarage(const Garaz& garaz)
{
  bool result = false;
  if (m_managerData != nullptr)
  {
    beginInsertRows(QModelIndex(), m_managerData->storeVector().size() + 1,
        m_managerData->storeVector().size() + 1);
    result = m_managerData->addGarage(garaz);
    endInsertRows();
  }
  return result;
}

bool GarageModel::removeGarageId(unsigned int id)
{
  beginRemoveRows(QModelIndex(), id - 1, id - 1);
  m_managerData->removeGarageId(id);
  endRemoveRows();
}

int GarageModel::rowCount(const QModelIndex &parent) const
{
  return m_managerData != nullptr ? m_managerData->garageVector().size() : 0;
}

int GarageModel::columnCount(const QModelIndex &parent) const
{
  return 3;
}
QVariant GarageModel::headerData(int section, Qt::Orientation orientation,
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

QVariant GarageModel::data(const QModelIndex &index, int role) const
{
  if (m_managerData == nullptr)
    return QVariant();
  if (role == Qt::DisplayRole)
    switch (index.column())
    {
      case 0:
        return m_managerData->garageVector()[index.row()].WezGarazId();
      case 1:
        return m_managerData->garageVector()[index.row()].WezWspX();
      case 2:
        return m_managerData->garageVector()[index.row()].WezWspY();
    }
  return QVariant();
}
