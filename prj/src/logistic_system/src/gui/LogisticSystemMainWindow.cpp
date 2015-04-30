/*
 * LogisticSystemMainWindow.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "LogisticSystemMainWindow.hpp"
#include "AboutRobotManagerDialog.hpp"
#include <QMessageBox>
#include <QCloseEvent>

LogisticSystemMainWindow::LogisticSystemMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
  init();
}

void LogisticSystemMainWindow::refreshDataViewed()
{

}

void LogisticSystemMainWindow::init()
{
  m_ui.setupUi(this);
  connect(m_ui.actionAbout, SIGNAL(triggered()), this,
      SLOT(showAboutWndDialog()));
}

void LogisticSystemMainWindow::closeEvent(QCloseEvent* closeEvent)
{
  QMessageBox::StandardButtons chosenButton = QMessageBox::question(this,
      tr("Closing application"), tr("Do you really want to quit application"),
      QMessageBox::Yes | QMessageBox::No);

  if (chosenButton == QMessageBox::No)
    closeEvent->ignore();
}

void LogisticSystemMainWindow::showAboutWndDialog()
{
  AboutRobotManagerDialog dialog(this);
  dialog.exec();
}


