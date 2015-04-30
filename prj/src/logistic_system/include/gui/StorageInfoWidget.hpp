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
#include "DataManager.hpp"

class StorageInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT
	public:
		StorageInfoWidget(QWidget* parent = nullptr)
				: QWidget(parent)
		{
			init();
		}

	public slots:
	    void refreshDataViewed();

	private:
		void init();

		Ui::UiStorageInfoWidget m_ui;
};

#endif /* STORAGEINFOWIDGET_HPP_ */
