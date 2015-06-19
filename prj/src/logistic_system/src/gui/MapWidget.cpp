/*
 * MapWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "MapWidget.hpp"
#include <QPaintEvent>
#include <cmath>

const double MapWidget::WIDTH = 5.0;
const double MapWidget::HEIGHT = 5.0;

void MapWidget::paintEvent(QPaintEvent* paintEvent)
{
  QPalette palette;
  palette.setColor(QPalette::Background, Qt::white);
  setAutoFillBackground(true);
  setPalette(palette);

  int width = this->width(), height = this->height();
  QPainter painter(this);

  if (getRobotManagerData() == nullptr)
  {
    painter.drawText(20, 20, tr("No data to show"));
    return;
  }

  drawAllRobot(painter);
  drawAllGarage(painter);
  drawAllStorage(painter);

  QWidget::paintEvent(paintEvent);
}

double MapWidget::getAngleInDegrees(double x1, double y1, double x2,
    double y2) const
{
  double angle;
  double h = y2 - y1, a = x2 - x1;
  if (a >= 1e-6 && a <= 1e-6)
  {
    if (h > 0)
      angle = -90;
    else
      angle = 90;
  }
  else
  {
    if (h > 0)
    {
      if (a > 0)
        angle = -90 + atan(h / a) * 180 / 3.14159265;
      else
        angle = atan(h / -a) * 180 / 3.14159265;
    }
    else
    {
      if (a > 0)
        angle = -90 - atan(-h / a) * 180 / 3.14159265;
      else
        angle = 90 + atan(h / a) * 180 / 3.14159265;
    }
  }
  std::cout << angle << std::endl;
  return angle;
}

void MapWidget::drawAllGarage(QPainter& painter)
{
  int width = this->width(), height = this->height();
  QPixmap garageIcon(":/icon/garage.png");
  for (const Garaz& garage : getRobotManagerData()->garageVector())
  {
    QPixmap scaledGarageIcon = garageIcon.scaledToWidth(0.3 / WIDTH * width);
    int x = garage.WezWspY() / WIDTH * width - 0.5 * scaledGarageIcon.width(),
        y = garage.WezWspX() / HEIGHT * height
            - 0.5 * scaledGarageIcon.height();

    double angle = getAngleInDegrees(garage.WezWspX(), garage.WezWspY(),
        garage.WezWspWejX(), garage.WezWspWejY());

    QMatrix transformMatrix;
    transformMatrix.translate(0.5 * scaledGarageIcon.width(),
        0.5 * scaledGarageIcon.height());
    transformMatrix.rotate(angle);

    scaledGarageIcon = scaledGarageIcon.transformed(transformMatrix);

    painter.drawPixmap(x, y, scaledGarageIcon);
    painter.drawText(x + 1.02 * scaledGarageIcon.width(),
        y + 1.02 * scaledGarageIcon.height(),
        QString("%1").arg(garage.WezGarazId()));
  }
}

void MapWidget::drawAllStorage(QPainter& painter)
{
  int width = this->width(), height = this->height();
  QPixmap storageIcon(":/icon/storage.png");
  for (const Magazyn& storage : getRobotManagerData()->storeVector())
  {
    QPixmap scaledStorageIcon = storageIcon.scaledToWidth(0.3 / WIDTH * width);
    double angle = getAngleInDegrees(storage.WezWspX(), storage.WezWspY(),
        storage.WezWspWejX(), storage.WezWspWejY());

    QMatrix transformMatrix;
    transformMatrix.translate(0.5 * scaledStorageIcon.width(),
        0.5 * scaledStorageIcon.height());
    transformMatrix.rotate(angle);

    int x = storage.WezWspY() / WIDTH * width - 0.5 * scaledStorageIcon.width(),
        y = storage.WezWspX() / HEIGHT * height
            - 0.5 * scaledStorageIcon.height();

    scaledStorageIcon = scaledStorageIcon.transformed(transformMatrix);
    painter.drawPixmap(x, y, scaledStorageIcon);
    painter.drawText(x + 1.05 * scaledStorageIcon.width(),
        y + 1.05 * scaledStorageIcon.height(),
        QString("%1").arg(storage.WezMagazynId()));
  }
}

void MapWidget::drawAllRobot(QPainter& painter)
{
  int width = this->width(), height = this->height();
  QPixmap robotIcon(":/icon/robotMap.png");
  for (const Robot& robot : getRobotManagerData()->robotVector())
  {
    QPixmap scaledRobotIcon = robotIcon.scaledToWidth(0.3 / WIDTH * width);
    painter.drawPixmap(robot.WezWspX() / WIDTH * width,
        robot.WezWspY() / HEIGHT * height, scaledRobotIcon);
  }
}

void MapWidget::refreshDataViewed()
{
  repaint();
}

