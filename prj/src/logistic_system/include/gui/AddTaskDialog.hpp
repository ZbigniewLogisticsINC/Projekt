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

class AddTaskDialog: public QDialog, public DataManager
{
  Q_OBJECT
  public:
    AddTaskDialog(QWidget* parent = nullptr)
        : QDialog(parent)
    {
      init();
    }
    void setRobotManagerData(RobotManagerData* managerData);
  public slots:
    void refreshDataViewed();

  private:
    void init();
    Ui::UiAddTaskDialog m_ui;

};

#endif /* ADDTASKDIALOG_HPP_ */
