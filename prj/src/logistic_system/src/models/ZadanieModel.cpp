/*
 * TasksModel.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#include "ZadanieModel.hpp"

int ZadanieModel::rowCount(const QModelIndex &parent) const
{
  return m_listaZadan.length();
}

int ZadanieModel::columnCount(const QModelIndex &parent) const
{
  return 3;
}

QVariant ZadanieModel::data(const QModelIndex &index, int role) const
{
  if (role == Qt::DisplayRole)
    switch (index.column())
    {
      case 0:
        return m_listaZadan[index.row()][Zadanie::TypDanych::START_MAGAZYN_ID];
      case 1:
        return m_listaZadan[index.row()][Zadanie::TypDanych::CEL_MAGAZYN_ID];
      case 2:
        return m_listaZadan[index.row()][Zadanie::TypDanych::PREF_ROBOT];
    }
  return QVariant();
}

QVariant ZadanieModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{
  if (role == Qt::DisplayRole)
  {
    if (orientation == Qt::Horizontal)
    {
      switch (section)
      {
        case 0:
          return tr("Start Storage");
        case 1:
          return tr("Destination Storage");
        case 2:
          return tr("Preffered Robot");
      }
    }
  }
  return QVariant();
}

