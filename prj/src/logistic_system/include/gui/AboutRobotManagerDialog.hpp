/*
 * AboutRobotManagerDialog.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ABOUTROBOTMANAGERDIALOG_HPP_
#define ABOUTROBOTMANAGERDIALOG_HPP_

#include <QDialog>
#include "ui_AboutRobotManagerDialog.h"

/*!
 * \brief Okno prezentujące informacje o autorach programu
 */
class AboutRobotManagerDialog: public QDialog
{
	Q_OBJECT
	public:
	/*!
	 * \brief Kontruktor klasy AboutRobotManagerDialog
	 *
	 * \param parent - rodzic okna dialogowego
	 */
		AboutRobotManagerDialog(QWidget* parent = nullptr)
				: QDialog(parent) { m_ui.setupUi(this); }
	private:
		/*!
		 * \brief Pole przechowujące wskaźniki na obiekty wizualne okna dialogowego
		 */
		Ui::UiAboutRobotManagerDialog m_ui;
};

#endif /* ABOUTROBOTMANAGERDIALOG_HPP_ */
