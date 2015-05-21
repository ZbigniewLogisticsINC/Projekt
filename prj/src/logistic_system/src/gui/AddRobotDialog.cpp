/*
 * AddRobotDialog.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#include "AddRobotDialog.hpp"

void AddRobotDialog::init()
{
  m_ui.setupUi(this);
  connect(this, SIGNAL(accepted()), this, SLOT(setRobotInfo()));
}

void AddRobotDialog::refreshDataViewed()
{

}

void AddRobotDialog::fillGarageCombo()
{
  for (int i = 0; i < m_managerData->garageVector().size(); i++)
  {
    std::cout << "wchodzi\n";
    QString text = QString("%1").arg(
        m_managerData->garageVector()[i].WezGarazId());
    m_ui.comboBox->addItem(text);
  }
}

void AddRobotDialog::setRobotManagerData(RobotManagerData* managerData)
{
  DataManager::setRobotManagerData(managerData);
  fillGarageCombo();
}

bool AddRobotDialog::robotCorrect() const
{
  bool isCorrect = true;
  for (int i = 0; i < m_managerData->robotVector().size() && isCorrect; i++)
  {
    if (m_managerData->robotVector()[i].WezRobotId() == m_ui.spinBox->value())
      isCorrect = false;
  }

  if (m_ui.comboBox->currentIndex() < 0)
    isCorrect = false;
  return isCorrect;
}

void AddRobotDialog::setRobotInfo()
{
  if (robotCorrect())
  {
    m_robot.ZmienCzyWolny(true);
    m_robot.ZmienRobotId(m_ui.spinBox->value());
    m_robot.ZmienGarazId(m_ui.comboBox->currentText().toInt());
  }
}
