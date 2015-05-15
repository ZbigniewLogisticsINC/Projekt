#include "RobotInfoWidget.hpp"
#include "AddRobotDialog.hpp"

void RobotInfoWidget::init()
{
  m_ui.setupUi(this);
  m_robotModel = new RobotModel(this);
  m_ui.tableView->setModel(m_robotModel);
  m_ui.tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
  connect(m_ui.addButton, SIGNAL(clicked()), this, SLOT(showAddDialog()));
}

void RobotInfoWidget::showAddDialog()
{
  AddRobotDialog dialog(this);
  dialog.setRobotManagerData(m_managerData);
  if (dialog.exec() == QDialog::Accepted && dialog.robotCorrect())
  {
    m_robotModel->addRobot(dialog.robot());

  }
}

void RobotInfoWidget::setRobotManagerData(RobotManagerData* managerData)
{
  DataManager::setRobotManagerData(managerData);
  m_robotModel->setRobotManagerData(managerData);
}

void RobotInfoWidget::refreshDataViewed()
{

}
