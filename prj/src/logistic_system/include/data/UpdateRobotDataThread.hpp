/*
 * UpdateRobotDataThread.hpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#ifndef UPDATEROBOTDATATHREAD_HPP_
#define UPDATEROBOTDATATHREAD_HPP_

#include <QThread>
#include "DataManager.hpp"
#include <iostream> // todo usunąć


class UpdateRobotDataThread: public QThread, public DataManager
{
  public:
    UpdateRobotDataThread(QObject* parent = nullptr): QThread(parent), waitTimeMs(1000) { }
    void run();
    unsigned waitTimeMs;
    std::string dirPath;
};

#endif /* UPDATEROBOTDATATHREAD_HPP_ */
