/*
 * RobotModel.cpp
 *
 *  Created on: May 15, 2015
 *      Author: mochman
 */

#include "RobotModel.hpp"

void RobotModel::setRobotManagerData(RobotManagerData* data)
{
  beginResetModel();
  DataManager::setRobotManagerData(data);
  endResetModel();
}

bool RobotModel::addRobot(const Robot& robot)
{
  bool result = false;
  if (m_managerData != nullptr)
  {
    beginInsertRows(QModelIndex(), m_managerData->robotVector().size() + 1,
        m_managerData->storeVector().size() + 1);
    result = m_managerData->addRobot(robot);
    endInsertRows();
  }
  return result;
}

bool RobotModel::removeRobotId(unsigned int id)
{
  beginRemoveRows(QModelIndex(), id - 1, id - 1);
  m_managerData->removeRobotId(id);
  endRemoveRows();
}

int RobotModel::rowCount(const QModelIndex &parent) const
{
  return m_managerData != nullptr ? m_managerData->robotVector().size() : 0;
}

int RobotModel::columnCount(const QModelIndex &parent) const
{
  return 5;
}

QVariant RobotModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
  if (role == Qt::DisplayRole)
  {
    if (orientation == Qt::Horizontal)
    {
      QString columns[5] = { tr("id"), tr("y coordinate"), tr("x coordinate"),
          tr("is free"), tr("garage id") };
      if (section < 5)
        return columns[section];
    }
  }
  else
    if (orientation == Qt::Vertical)
      return section + 1;

  return QVariant();
}

QVariant RobotModel::data(const QModelIndex &index, int role) const
{
  if (m_managerData == nullptr)
    return QVariant();
  if (role == Qt::DisplayRole)
    switch (index.column())
    {
      case 0:
        return m_managerData->robotVector()[index.row()].WezRobotId();
      case 1:
        return m_managerData->robotVector()[index.row()].WezWspX();
      case 2:
        return m_managerData->robotVector()[index.row()].WezWspY();
      case 3:
        return
            m_managerData->robotVector()[index.row()].WezCzyWolny() ?
                tr("Yes") : tr("No");
      case 4:
        return m_managerData->robotVector()[index.row()].WezGarazId();
    }
  return QVariant();
}
