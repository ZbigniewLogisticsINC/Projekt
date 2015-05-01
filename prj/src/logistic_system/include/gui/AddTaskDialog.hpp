/*
 * AddTaskDialog.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ADDTASKDIALOG_HPP_
#define ADDTASKDIALOG_HPP_

#include <QDialog>
#include "ui_AddTaskDialog.h"
#include "DataManager.hpp"
#include "zadanie.hpp"

class AddTaskDialog: public QDialog, public DataManager
{
  Q_OBJECT
  public:
    AddTaskDialog(QWidget* parent = nullptr)
        : QDialog(parent) { init(); }
    void setRobotManagerData(RobotManagerData* managerData);
    const Zadanie& task() const { return m_task; }
  public slots:
    void refreshDataViewed();
    void refreshDestCombo(QString);
  private:
    void init();
    Ui::UiAddTaskDialog m_ui;
    Zadanie m_task;
    static unsigned int s_taskId;
  private slots:
    void setTaskFromDialog();
};

#endif /* ADDTASKDIALOG_HPP_ */
