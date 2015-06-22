/*
 * UpdateRobotDataThread.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#include "UpdateRobotDataThread.hpp"

void UpdateRobotDataThread::run()
{
  while (true)
  {
    QThread::msleep(waitTimeMs);
    if (m_managerData != nullptr)
      m_managerData->update(dirPath);
  }
}

