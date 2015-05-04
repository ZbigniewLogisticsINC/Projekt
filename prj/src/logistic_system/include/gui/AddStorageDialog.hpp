/*
 * AddStorageDialog.hpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#ifndef ADDSTORAGEDIALOG_HPP_
#define ADDSTORAGEDIALOG_HPP_

#include <QDialog>
#include "DataManager.hpp"
#include "ui_AddStorageDialog.h"


class AddStorageDialog: public QDialog, public DataManager
{
    Q_OBJECT

  public:
    AddStorageDialog(QWidget* parent = nullptr): QDialog(parent) { init(); }
    const Magazyn& store() const { return m_store; }
  private slots:
    void setStorageFromDialog();
  private:
    void init();
    Ui::UiAddStorageDialog m_ui;
    Magazyn m_store;
    static unsigned int s_id;
};


#endif /* ADDSTORAGEDIALOG_HPP_ */
