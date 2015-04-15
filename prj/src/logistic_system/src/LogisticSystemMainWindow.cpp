/*
 * LogisticSystemMainWindow.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "LogisticSystemMainWindow.hpp"
#include "AboutRobotManagerDialog.hpp"


LogisticSystemMainWindow::LogisticSystemMainWindow(QWidget* parent)
		: QMainWindow(parent)
{
	m_ui.setupUi(this);
	init();
}

void LogisticSystemMainWindow::init()
{
	connect(m_ui.actionAbout,SIGNAL(triggered()),this,SLOT(showAboutWndDialog()));
}

void LogisticSystemMainWindow::showAboutWndDialog()
{
	AboutRobotManagerDialog dialog(this);
	dialog.exec();
}
