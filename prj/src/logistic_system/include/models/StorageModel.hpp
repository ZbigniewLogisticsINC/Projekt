/*
 * StorageModel.hpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#ifndef STORAGEMODEL_HPP_
#define STORAGEMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

class StorageModel: public QAbstractTableModel, public DataManager
{
  public:
    StorageModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }
    bool addStore(const Magazyn& storage);
    bool removeStoreId(unsigned int id);
    void setRobotManagerData(RobotManagerData* data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation,
        int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif /* STORAGEMODEL_HPP_ */
