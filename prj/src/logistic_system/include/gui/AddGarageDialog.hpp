/*
 * AddGarageDialog.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef ADDGARAGEDIALOG_HPP_
#define ADDGARAGEDIALOG_HPP_

#include <QDialog>
#include "DataManager.hpp"
#include "ui_AddGarageDialog.h"

class AddGarageDialog: public QDialog, public DataManager
{
    Q_OBJECT
  public:
    AddGarageDialog(QWidget* parent = nullptr): QDialog(parent) { init(); }
    const Garaz& garage() const { return m_garage; }
  private slots:
    void setGarageFromDialog();
  private:
    void init();
    Ui::UiAddGarageDialog m_ui;
    Garaz m_garage;
    static unsigned int s_id;
};

#endif /* ADDGARAGEDIALOG_HPP_ */
