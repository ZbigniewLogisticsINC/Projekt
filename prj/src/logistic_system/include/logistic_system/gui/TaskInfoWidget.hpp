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

class TaskInfoWidget: public QWidget
{
	Q_OBJECT

	public:
		TaskInfoWidget(QWidget* parent = nullptr)
		{
			init();
		}

	private slots:
		void showAddTaskDialog();

	private:
		void init();
		Ui::UiTaskInfoWidget m_ui;

};

#endif /* TASKINFOWIDGET_HPP_ */
