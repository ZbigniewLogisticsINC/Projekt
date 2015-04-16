#ifndef ADD_ROBOT_DIALOG_HPP
#define ADD_ROBOT_DIALOG_HPP

#include <QDialog>
#include "ui_AddRobotDialog.h"


class AddRobotDialog: public QDialog
{
  Q_OBJECT

public:
  AddRobotDialog(QWidget* parent = nullptr): QDialog(parent) { init(); }
private:
  void init();
  Ui::UiAddRobotDialog m_ui;
};

#endif
