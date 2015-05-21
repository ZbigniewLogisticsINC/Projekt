/*
 * TaskInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef TASKINFOWIDGET_HPP_
#define TASKINFOWIDGET_HPP_

#include <QWidget>
#include "ui_TaskInfoWidget.h"
#include "DataManager.hpp"
#include "TaskModel.hpp"

class TaskInfoWidget: public QWidget, public DataManager
{
	Q_OBJECT

	public:
		TaskInfoWidget(QWidget* parent = nullptr): QWidget(parent), m_currentRowSelected(-1) { init(); }
		void setRobotManagerData(RobotManagerData* managerData);

	public slots:
	    void refreshDataViewed();
	private slots:
		void showAddTaskDialog();
		void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);
		void removeSelected();


	private:
		void init();
		void updateTotalTasksNumber()
		      { m_ui.totalTasksNumberLabel->setText(tr("%1").arg(m_managerData->tasksVector().size())); }
		Ui::UiTaskInfoWidget m_ui;
		TaskModel* m_taskModel;
		int m_currentRowSelected;
};

#endif /* TASKINFOWIDGET_HPP_ */
