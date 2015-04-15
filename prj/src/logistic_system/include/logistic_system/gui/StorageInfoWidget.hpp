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


class StorageInfoWidget: public QWidget
{
	public:
		StorageInfoWidget(QWidget* parent = nullptr)
				: QWidget(parent)
		{
			init();
		}

	private:
		void init();

		Ui::UiStorageInfoWidget m_ui;
};

#endif /* STORAGEINFOWIDGET_HPP_ */
