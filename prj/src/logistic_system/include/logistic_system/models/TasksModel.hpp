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

#include "Task.hpp"

class TasksModel: public QAbstractTableModel
{
	Q_OBJECT

	public:
		TasksModel(QObject* parent = nullptr)
				: QAbstractTableModel(parent)
		{
		}

		void pushBack(const Task& task)
		{
			m_taskList.push_back(task);
		}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	private:
		QList<Task> m_taskList;
};

#endif /* PRJ_SRC_LOGISTIC_SYSTEM_INCLUDE_LOGISTIC_SYSTEM_MODELS_TASKSMODELS_HPP_ */
