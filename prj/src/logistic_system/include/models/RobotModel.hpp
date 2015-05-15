/*
 * RobotModel.hpp
 *
 *  Created on: May 15, 2015
 *      Author: mochman
 */

#ifndef ROBOTMODEL_HPP_
#define ROBOTMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

class RobotModel: public QAbstractTableModel, public DataManager
{
  public:
    RobotModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }
    bool addRobot(const Robot& Robot);
    bool removeRobotId(unsigned int id);
    void setRobotManagerData(RobotManagerData* data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};



#endif /* ROBOTMODEL_HPP_ */
