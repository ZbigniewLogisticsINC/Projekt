/*
 * MapWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef MAPWIDGET_HPP_
#define MAPWIDGET_HPP_

#include <QWidget>

class MapWidget: public QWidget
{
	public:
		MapWidget(QWidget* parent = nullptr)
				: QWidget(parent)
		{
		}

	protected:
		void paintEvent(QPaintEvent* paintEvent);
};

#endif /* PRJ_SRC_LOGISTIC_SYSTEM_INCLUDE_LOGISTIC_SYSTEM_GUI_MAPWIDGET_HPP_ */
