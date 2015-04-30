#include <iostream>
#include <QApplication>
#include "LogisticSystemMainWindow.hpp"
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <QTimer>

int main(int argc, char* argv[])
{

  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;

  QApplication app(argc, argv);
  RobotManagerData* data = new RobotManagerData;
  Magazyn m1, m2;
  Zadanie t1;
  m1.ZmienMagazynId(1);
  data->addStore(m1);

  m2.ZmienMagazynId(2);
  data->addTask(t1);
  data->addStore(m2);
  LogisticSystemMainWindow mainWindow;
  mainWindow.setRobotManagerData(data);
  mainWindow.show();

  return app.exec();
}
