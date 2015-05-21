/*
 * AddGarageDialog.cpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#include "AddGarageDialog.hpp"

unsigned int AddGarageDialog::s_id = 1;

void AddGarageDialog::init()
{
  m_ui.setupUi(this);
  connect(this, SIGNAL(accepted()), this, SLOT(setGarageFromDialog()));
}

void AddGarageDialog::setGarageFromDialog()
{
  m_garage.ZmienGarazId(s_id++);
  m_garage.ZmienWspX(m_ui.xSpinBox->value());
  m_garage.ZmienWspY(m_ui.ySpinBox->value());
  m_garage.ZmienWspWejX(m_ui.xEntrySpinBox->value());
  m_garage.ZmienWspWejY(m_ui.yEntrySpinBox->value());
}
