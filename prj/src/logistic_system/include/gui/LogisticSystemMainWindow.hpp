#ifndef LOGISTIC_SYSTEM_MAIN_WINDOW_HPP
#define LOGISTIC_SYSTEM_MAIN_WINDOW_HPP

#include <QMainWindow>
#include "ui_LogisticSystemMainWindow.h"

#include "RobotManagerDataObject.hpp"
#include "DataManager.hpp"

class LogisticSystemMainWindow: public QMainWindow, public DataManager
{
	Q_OBJECT

	public:
		LogisticSystemMainWindow(QWidget* parent = nullptr);
		void setRobotManagerData(RobotManagerData* managerData);
	public slots:
	    void refreshDataViewed();
	protected:
		void closeEvent(QCloseEvent* closeEvent);
	private:
		Ui::UiLogisticSystemMainWindow m_ui;
		void init();

	private slots:
		void showAboutWndDialog();
};

#endif
