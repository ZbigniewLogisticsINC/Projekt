/*
 * TasksModels.hpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#ifndef TASKSMODELS_HPP_
#define TASKSMODELS_HPP_

#include <QAbstractTableModel>
#include <QList>
#include "DataManager.hpp"

class TaskModel: public QAbstractTableModel, public DataManager
{
  Q_OBJECT

  public:
    TaskModel(QObject* parent = nullptr)
        : QAbstractTableModel(parent)
    {
      init();
    }
    void addTask(const Zadanie& task);
    void setRobotManagerData(RobotManagerData* data);
    void removeTaskId(int id);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  private:
    void init();

};

#endif /* TASKSMODELS_HPP_ */
