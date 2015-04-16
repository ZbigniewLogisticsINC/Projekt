/*
 * TasksModel.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#include "TasksModel.hpp"

int TasksModel::rowCount(const QModelIndex &parent) const
{
	return m_taskList.length();
}

int TasksModel::columnCount(const QModelIndex &parent) const
{
	return 3;
}

QVariant TasksModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole)
		switch (index.column())
		{
			case 0:
				return m_taskList[index.row()].startStorageId();
			case 1:
				return m_taskList[index.row()].desinationStorageId();
			case 2:
				return m_taskList[index.row()].prefferedRobotId();
		}
	return QVariant();
}

QVariant TasksModel::headerData(int section, Qt::Orientation orientation,
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

