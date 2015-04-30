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

#include "zadanie.hpp"

class ZadanieModel: public QAbstractTableModel
{
    Q_OBJECT

  public:
    ZadanieModel(QObject* rodzic = nullptr)
    : QAbstractTableModel(rodzic)
    {
    }

    void pushBack(const Zadanie& zadanie)
    {
      m_listaZadan.push_back(zadanie);
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  private:
    QList<Zadanie> m_listaZadan;
};

#endif /* TASKSMODELS_HPP_ */
