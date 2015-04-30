/*
 * MapWidget.cpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#include "MapWidget.hpp"
#include <QPainter>
#include <QPaintEvent>

void MapWidget::paintEvent(QPaintEvent* paintEvent)
{
	QPalette palette;
	palette.setColor(QPalette::Background, Qt::white);
	setAutoFillBackground(true);
	setPalette(palette);

	QPainter painter(this);
	painter.drawText(20, 20, tr("Map hasn't been finished yet"));
	//todo zaimplementować mapę
}

void MapWidget::refreshDataViewed()
{

}
