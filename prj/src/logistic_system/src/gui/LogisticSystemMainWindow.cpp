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
#include <thread>


LogisticSystemMainWindow::LogisticSystemMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
  init();
}

void LogisticSystemMainWindow::setRobotManagerData(
    RobotManagerData* managerData)
{
  m_ui.taskWidget->setRobotManagerData(managerData);
  m_ui.storageInfoWidget->setRobotManagerData(managerData);
  m_ui.garageInfoWidget->setRobotManagerData(managerData);
  m_ui.mapWidget->setRobotManagerData(managerData);
  m_ui.robotWidget->setRobotManagerData(managerData);
  DataManager::setRobotManagerData(managerData);
  connect(m_managerData, SIGNAL(dataUpdated()), 
	  this, SLOT(refreshDataViewed()));
}

void LogisticSystemMainWindow::refreshDataViewed()
{
  m_ui.mapWidget->refreshDataViewed();
  m_ui.taskWidget->refreshDataViewed();
  m_ui.robotWidget->refreshDataViewed();
  m_ui.storageInfoWidget->refreshDataViewed();
  m_ui.garageInfoWidget->refreshDataViewed();
}

void LogisticSystemMainWindow::init()
{
  m_ui.setupUi(this);
  m_rosTimer = new QTimer(this);
  connect(m_ui.actionAbout, SIGNAL(triggered()), this,
	  SLOT(showAboutWndDialog()));
  connect(m_rosTimer, SIGNAL(timeout()), this,
	  SLOT(onUpdateROS()));
  m_rosTimer->start(100);
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


void LogisticSystemMainWindow::onUpdateROS()
{
  //ros::spinOnce();
  m_managerData->update("asdads");
   
}
