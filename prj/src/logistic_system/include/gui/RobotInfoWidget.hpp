/*
 * RobotInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ROBOTINFOWIDGET_HPP_
#define ROBOTINFOWIDGET_HPP_

#include <QWidget>
#include "ui_RobotInfoWidget.h"
#include "DataManager.hpp"
#include "RobotModel.hpp"

class RobotInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT

  public:
    RobotInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent)    { init(); }
    public slots:
    void refreshDataViewed();
    void setRobotManagerData(RobotManagerData* managerData);
    private:
      Ui::UiRobotInfoWidget m_ui;
      void init();
      RobotModel* m_robotModel;
    private slots:
      void showAddDialog();
};

#endif /* ROBOTINFOWIDGET_HPP_ */
