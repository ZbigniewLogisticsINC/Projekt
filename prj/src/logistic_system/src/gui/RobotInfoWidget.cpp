#include "RobotInfoWidget.hpp"
#include "AddRobotDialog.hpp"

void RobotInfoWidget::init()
{
  m_ui.setupUi(this);
  connect(m_ui.addButton,SIGNAL(clicked()), this, SLOT(showAddDialog()));
}


void RobotInfoWidget::showAddDialog()
{
  AddRobotDialog dialog(this);
  dialog.exec();
}

void RobotInfoWidget::refreshDataViewed()
{

}
