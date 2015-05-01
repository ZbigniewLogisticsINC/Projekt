/*
 * AddStorageDialog.cpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#include "AddStorageDialog.hpp"

unsigned int AddStorageDialog::s_id = 1;

void AddStorageDialog::init()
{
  m_ui.setupUi(this);
  connect(this, SIGNAL(accepted()), this, SLOT(setStorageFromDialog()));
}

void AddStorageDialog::setStorageFromDialog()
{
  m_store.ZmienMagazynId(s_id++);
  m_store.ZmienCzyWolny(true);
  m_store.ZmienWspX(m_ui.xSpinBox->value());
  m_store.ZmienWspY(m_ui.ySpinBox->value());
}
