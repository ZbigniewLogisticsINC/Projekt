/*
 * TaskThread.cpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#include "TaskThread.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

void TaskThread::run()
{

  std::ostringstream ossGoToStartCmd, ossGoToEndCmd;

  ossGoToStartCmd << "python " << " " << robotName << " " << xStart << " "
      << yStart << 1;

  ossGoToEndCmd << "python " << " " << robotName << " " << xEnd << " " << yEnd
      << 1;

  if (system(ossGoToStartCmd.str().c_str()) >= 0)
    system(ossGoToEndCmd.str().c_str());

  std::cout << "Started " << taskId << std::endl;
  QThread::sleep(10);
  std::cout << "Finished " << taskId << std::endl;
}

