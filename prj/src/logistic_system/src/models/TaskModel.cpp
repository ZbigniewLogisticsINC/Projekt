/*
 * TasksModel.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#include "TaskModel.hpp"

void TaskModel::init()
{

}

void TaskModel::addTask(const Zadanie& task)
{
  if (m_managerData != nullptr)
  {
    beginInsertRows(QModelIndex(), m_managerData->tasksVector().size() + 1,
        m_managerData->tasksVector().size() + 1);
    m_managerData->addTask(task);
    endInsertRows();
  }
}

void TaskModel::removeTaskId(int id)
{
  beginRemoveRows(QModelIndex(), id - 1, id - 1);
  m_managerData->removeTaskId(id);
  endRemoveRows();
}

void TaskModel::setRobotManagerData(RobotManagerData* data)
{
  beginResetModel();
  DataManager::setRobotManagerData(data);
  connect(m_managerData, SIGNAL(dataUpdated()), this, SLOT(onDataUpdated()));
  endResetModel();
}

int TaskModel::rowCount(const QModelIndex &parent) const
{
  if (m_managerData == nullptr)
    return 0;
  return m_managerData->tasksVector().size();
}

int TaskModel::columnCount(const QModelIndex &parent) const
{
  return 6;
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
  if (m_managerData == nullptr)
    return QVariant();
  if (role == Qt::DisplayRole)
    switch (index.column())
    {
      case 0:
        return m_managerData->tasksVector()[index.row()].WezId();
      case 1:
        return m_managerData->tasksVector()[index.row()].WezStartMagazynId();
      case 2:
        return m_managerData->tasksVector()[index.row()].WezCelMagazynId();
      case 3:
        return m_managerData->tasksVector()[index.row()].WezPreferowanegoRobotaId();
      case 4:
      {
        QString statusTab[] = { tr("Waiting"), tr("Running"), tr("Completed") };
        return statusTab[m_managerData->tasksVector()[index.row()].WezStatus()];
      }
      case 5:
      {
        int idRobot = m_managerData->tasksVector()[index.row()].WezRobot();
        if (idRobot >= 0)
          return idRobot;
        else
          return tr("None");
      }
    }
  return QVariant();
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
  if (role == Qt::DisplayRole)
  {
    if (orientation == Qt::Horizontal)
    {
      switch (section)
      {
        case 0:
          return tr("Id");
        case 1:
          return tr("Start Storage");
        case 2:
          return tr("Destination Storage");
        case 3:
          return tr("Preffered Robot");
        case 4:
          return tr("Status");
        case 5:
          return tr("Robot working");
      }
    }
    else
      if (orientation == Qt::Vertical)
        return section + 1;
  }
  return QVariant();
}

