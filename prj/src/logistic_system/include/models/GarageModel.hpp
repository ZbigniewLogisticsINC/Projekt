/*
 * GarageModel.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef GARAGEMODEL_HPP_
#define GARAGEMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

class GarageModel: public QAbstractTableModel, public DataManager
{
  public:
    GarageModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }
    bool addGarage(const Garaz& garage);
    bool removeGarageId(unsigned int id);
    void setRobotManagerData(RobotManagerData* data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif /* GARAGEMODEL_HPP_ */
