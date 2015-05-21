/*
 * GarageInfoWidget.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef GARAGEINFOWIDGET_HPP_
#define GARAGEINFOWIDGET_HPP_

#include <QWidget>
#include "ui_GarageInfoWidget.h"
#include "GarageModel.hpp"


class GarageInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT
  public:
    GarageInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent), m_selectedRow(-1) { init(); }
    void setRobotManagerData(RobotManagerData* managerData);
    public slots:
      void showAddGarageDialog();

    public slots:
      void refreshDataViewed();
    private slots:
      void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);
      void removeSelected();

    private:
      void init();
      void updateTotalStorageNumber()
        { m_ui.totalGarageNumberLabel->setText(tr("%1").arg(m_managerData->garageVector().size())); }
      Ui::UiGarageInfoWidget m_ui;
      GarageModel* m_garageModel;
      int m_selectedRow;
};

#endif /* GARAGEINFOWIDGET_HPP_ */
