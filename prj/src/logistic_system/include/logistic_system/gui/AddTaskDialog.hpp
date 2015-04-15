/*
 * AddTaskDialog.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ADDTASKDIALOG_HPP_
#define ADDTASKDIALOG_HPP_

#include <QDialog>
#include "ui_AddTaskDialog.h"

class AddTaskDialog: public QDialog
{
	Q_OBJECT
	public:
		AddTaskDialog(QWidget* parent = nullptr)
				: QDialog(parent)
		{
			init();
		}

	private:
		void init();
		Ui::UiAddTaskDialog m_ui;

};

#endif /* PRJ_SRC_LOGISTIC_SYSTEM_INCLUDE_LOGISTIC_SYSTEM_GUI_ADDTASKDIALOG_HPP_ */
