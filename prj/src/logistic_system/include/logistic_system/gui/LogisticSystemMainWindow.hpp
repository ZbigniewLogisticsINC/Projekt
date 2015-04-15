#ifndef LOGISTIC_SYSTEM_MAIN_WINDOW_HPP
#define LOGISTIC_SYSTEM_MAIN_WINDOW_HPP

#include <QMainWindow>
#include "ui_LogisticSystemMainWindow.h"

class LogisticSystemMainWindow: public QMainWindow
{
	Q_OBJECT

	public:
		LogisticSystemMainWindow(QWidget* parent = nullptr);
	private:
		Ui::UiLogisticSystemMainWindow m_ui;
		void init();
	private slots:
		void showAboutWndDialog();

};

#endif
