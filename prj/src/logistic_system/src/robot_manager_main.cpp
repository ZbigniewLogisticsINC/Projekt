#include <iostream>
#include <ros/ros.h>
#include <QMessageBox>
#include <QApplication>
#include "LogisticSystemMainWindow.hpp"


int main(int argc, char* argv[])
{

  QApplication app(argc, argv);
  //QMessageBox::information(nullptr, "System ROS", "Witaj w systemie ROS!");
  
  LogisticSystemMainWindow mainWindow;

  mainWindow.show();

  return app.exec();
}
