/*
 * MapWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef MAPWIDGET_HPP_
#define MAPWIDGET_HPP_

#include <QWidget>
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
};

#endif /* MAPWIDGET_HPP_ */
