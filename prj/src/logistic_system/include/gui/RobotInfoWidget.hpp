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
#include "DataManager.hpp"

class RobotInfoWidget: public QWidget, public DataManager
{
	Q_OBJECT

	public:
		RobotInfoWidget(QWidget* parent = nullptr)
				: QWidget(parent)
		{
		  init();
		}

	public slots:
	    void refreshDataViewed();

	private:
		Ui::UiRobotInfoWidget m_ui;
  void init();
private slots:
  void showAddDialog();
};

#endif /* ROBOTINFOWIDGET_HPP_ */
