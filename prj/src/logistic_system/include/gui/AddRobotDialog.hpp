#ifndef ADD_ROBOT_DIALOG_HPP
#define ADD_ROBOT_DIALOG_HPP

#include <QDialog>
#include "ui_AddRobotDialog.h"
#include "RobotManagerDataObject.hpp"
#include "DataManager.hpp"

class AddRobotDialog: public QDialog, public DataManager
{
    Q_OBJECT

  public:
    AddRobotDialog(QWidget* parent = nullptr): QDialog(parent), m_managerDataObject(nullptr) { init(); }
    void setRobotManagerData(RobotManagerData* managerData);
    bool robotCorrect() const;
    const Robot& robot() const { return m_robot; }
  public slots:
    void refreshDataViewed();
  private slots:
    void setRobotInfo();
  private:
    void init();
    void fillGarageCombo();
    Robot m_robot;
    Ui::UiAddRobotDialog m_ui;
    RobotManagerDataObject* m_managerDataObject;
};

#endif
