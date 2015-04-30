#include <iostream>
#include <QApplication>
#include "LogisticSystemMainWindow.hpp"
#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  QApplication app(argc, argv);
  RobotManagerData data;
  LogisticSystemMainWindow mainWindow;
  mainWindow.setRobotManagerData(&data);
  mainWindow.show();

  return app.exec();
}
