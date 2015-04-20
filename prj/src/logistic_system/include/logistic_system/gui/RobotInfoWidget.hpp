/*
 * RobotInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ROBOTINFOWIDGET_HPP_
#define ROBOTINFOWIDGET_HPP_

#include <QWidget>
#include "ui_RobotInfoWidget.h"

class RobotInfoWidget: public QWidget
{
	Q_OBJECT

	public:
		RobotInfoWidget(QWidget* parent = nullptr)
				: QWidget(parent)
		{
		  init();
		}

	private:
		Ui::UiRobotInfoWidget m_ui;
  void init();
private slots:
  void showAddDialog();
};

#endif /* ROBOTINFOWIDGET_HPP_ */
