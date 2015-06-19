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
    : QMainWindow(parent), m_rosUpdateThread(new UpdateRobotDataThread(this))
{
  init();
}

void LogisticSystemMainWindow::setRobotManagerData(
    RobotManagerData* managerData)
{
  if (m_rosUpdateThread->isRunning())
    m_rosUpdateThread->terminate();
  m_ui.taskWidget->setRobotManagerData(managerData);
  m_ui.storageInfoWidget->setRobotManagerData(managerData);
  m_ui.garageInfoWidget->setRobotManagerData(managerData);
  m_ui.mapWidget->setRobotManagerData(managerData);
  m_ui.robotWidget->setRobotManagerData(managerData);
  DataManager::setRobotManagerData(managerData);
  connect(m_managerData, SIGNAL(dataUpdated()), this,
      SLOT(refreshDataViewed()));
  m_rosUpdateThread->setRobotManagerData(managerData);
  m_rosUpdateThread->dirPath = "/tmp/robot_manager/";
  m_rosUpdateThread->start();
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
  m_taskManagerTimer = new QTimer(this);
  connect(m_ui.actionAbout, SIGNAL(triggered()), this,
      SLOT(showAboutWndDialog()));
  connect(m_taskManagerTimer, SIGNAL(timeout()), this, SLOT(runNextTasks()));
  m_taskManagerTimer->start(100);
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
  m_managerData->update("/tmp/robot_manager/");
}

void LogisticSystemMainWindow::runNextTasks()
{

}

void LogisticSystemMainWindow::onTaskCompleted(unsigned taskId)
{
  QMap<unsigned, QThread*>::iterator it = m_taskThreadsMap.find(taskId);

  if (it != m_taskThreadsMap.end())
  {
    delete it.value();
    m_taskThreadsMap.remove(taskId);
    m_managerData->changeTaskStatusOnCompletedId(taskId);
  }

}
