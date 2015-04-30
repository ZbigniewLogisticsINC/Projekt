#ifndef ADD_ROBOT_DIALOG_HPP
#define ADD_ROBOT_DIALOG_HPP

#include <QDialog>
#include "ui_AddRobotDialog.h"
#include "RobotManagerDataObject.hpp"

class AddRobotDialog: public QDialog, public DataManager
{
    Q_OBJECT

  public:
    AddRobotDialog(QWidget* parent = nullptr): QDialog(parent), m_managerDataObject(nullptr) { init(); }
  public slots:
    void refreshDataViewed();
  private:
    void init();
    Ui::UiAddRobotDialog m_ui;
    RobotManagerDataObject* m_managerDataObject;
};

#endif
