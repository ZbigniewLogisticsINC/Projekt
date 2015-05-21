/*
 * StorageInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef STORAGEINFOWIDGET_HPP_
#define STORAGEINFOWIDGET_HPP_

#include <QWidget>
#include "ui_StorageInfoWidget.h"
#include "StorageModel.hpp"

class StorageInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT
  public:
    StorageInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent), m_selectedRow(-1) { init(); }
    void setRobotManagerData(RobotManagerData* managerData);
    public slots:
      void showAddStorageDialog();
      void refreshDataViewed();
    private slots:
      void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);
      void removeSelected();
    private:
      void init();
      void updateTotalStorageNumber()
        { m_ui.totalStorageNumberLabel->setText(tr("%1").arg(m_managerData->storeVector().size())); }
      Ui::UiStorageInfoWidget m_ui;
      StorageModel* m_storageModel;
      int m_selectedRow;
};

#endif /* STORAGEINFOWIDGET_HPP_ */
