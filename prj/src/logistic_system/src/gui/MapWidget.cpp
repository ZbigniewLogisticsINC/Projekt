/*
 * MapWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "MapWidget.hpp"
#include <QPainter>
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

  QPixmap robotIcon(":/icon/robotMap.png");
  for (const Robot& robot : getRobotManagerData()->robotVector())
  {
    QPixmap scaledRobotIcon = robotIcon.scaledToWidth(0.3 / WIDTH * width);
    painter.drawPixmap(robot.WezWspY() / WIDTH * width,
        robot.WezWspX() / HEIGHT * height, scaledRobotIcon);
  }

  QPixmap garageIcon(":/icon/garage.png");
  for (const Garaz& garage : getRobotManagerData()->garageVector())
  {
    QPixmap scaledGarageIcon = garageIcon.scaledToWidth(0.3 / WIDTH * width);
    int x = garage.WezWspY() / WIDTH * width - 0.5 * scaledGarageIcon.width(),
        y = garage.WezWspX() / HEIGHT * height
            - 0.5 * scaledGarageIcon.height();
    painter.drawPixmap(x, y, scaledGarageIcon);
    painter.drawText(x + 1.02 * scaledGarageIcon.width(),
        y + 1.02 * scaledGarageIcon.height(),
        QString("%1").arg(garage.WezGarazId()));
  }

  QPixmap storageIcon(":/icon/storage.png");
  for (const Magazyn& storage : getRobotManagerData()->storeVector())
  {
    QPixmap scaledStorageIcon = storageIcon.scaledToWidth(0.3 / WIDTH * width);
    double angle = atan(
        (storage.WezWspWejY() - storage.WezWspY())
            / (storage.WezWspWejX() - storage.WezWspX())) * 180 / 3.14159265;
    QMatrix transformMatrix;
    transformMatrix.translate(0.5 * scaledStorageIcon.width(),
        0.5 * scaledStorageIcon.height());
    transformMatrix.rotate(-90 - angle);

    int x = storage.WezWspY() / WIDTH * width - 0.5 * scaledStorageIcon.width(),
        y = storage.WezWspX() / HEIGHT * height
            - 0.5 * scaledStorageIcon.height();

    scaledStorageIcon = scaledStorageIcon.transformed(transformMatrix);
    painter.drawPixmap(x, y, scaledStorageIcon);
    painter.drawText(x + 1.05 * scaledStorageIcon.width(),
        y + 1.05 * scaledStorageIcon.height(),
        QString("%1").arg(storage.WezMagazynId()));
    std::cout << angle << std::endl;
  }

  QWidget::paintEvent(paintEvent);
}

void MapWidget::refreshDataViewed()
{

}
