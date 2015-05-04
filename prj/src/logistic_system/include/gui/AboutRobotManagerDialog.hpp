/*
 * AboutRobotManagerDialog.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ABOUTROBOTMANAGERDIALOG_HPP_
#define ABOUTROBOTMANAGERDIALOG_HPP_

#include <QDialog>
#include "ui_AboutRobotManagerDialog.h"

class AboutRobotManagerDialog: public QDialog
{
	Q_OBJECT
	public:
		AboutRobotManagerDialog(QWidget* parent = nullptr)
				: QDialog(parent) { m_ui.setupUi(this); }
	private:
		Ui::UiAboutRobotManagerDialog m_ui;
};

#endif /* ABOUTROBOTMANAGERDIALOG_HPP_ */
