/*
 * MapWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef MAPWIDGET_HPP_
#define MAPWIDGET_HPP_

#include <QWidget>
#include <QPainter>
#include "DataManager.hpp"

class MapWidget: public QWidget, public DataManager
{
  Q_OBJECT
  public:
    MapWidget(QWidget* parent = nullptr)
        : QWidget(parent)
    {
    }
    static const double WIDTH;
    static const double HEIGHT;
  public slots:
    void refreshDataViewed();
  protected:
    void paintEvent(QPaintEvent* paintEvent);
  private:
    double getAngleInDegrees(double x1, double y1, double x2, double y2) const;
    void drawAllGarage(QPainter& painter);
    void drawAllStorage(QPainter& painter);
    void drawAllRobot(QPainter& painter);
};

#endif /* MAPWIDGET_HPP_ */
