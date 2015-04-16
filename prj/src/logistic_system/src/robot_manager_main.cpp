#include <iostream>
#include <QMessageBox>
#include <QApplication>
#include "LogisticSystemMainWindow.hpp"
#include <ros/ros.h>



int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  
  LogisticSystemMainWindow mainWindow;

  mainWindow.show();

  return app.exec();
}
