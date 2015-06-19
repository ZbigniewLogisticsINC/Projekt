/*
 * TaskThread.hpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#ifndef TASKTHREAD_HPP_
#define TASKTHREAD_HPP_

#include <QThread>

class TaskThread: public QThread
{
  public:
    TaskThread(QObject* parent = nullptr): QThread(parent), taskId(0) { connect(this,SIGNAL(finished()),this, SLOT(onFinished())); }
    unsigned taskId;
    std::string robotName;
  protected:
    void run();
  signals:
    void taskFinished(unsigned taskId);
  private slots:
    void onFinished() { emit taskFinished(taskId); }
};

#endif /* TASKTHREAD_HPP_ */
