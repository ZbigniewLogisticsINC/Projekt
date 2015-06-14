/*
 * TaskInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef TASKINFOWIDGET_HPP_
#define TASKINFOWIDGET_HPP_

#include <QWidget>
#include "ui_TaskInfoWidget.h"
#include "DataManager.hpp"
#include "TaskModel.hpp"

/*!
 * \brief Kontrolka odpowiedzialna za zarządzanie zadaniami
 */
class TaskInfoWidget: public QWidget, public DataManager
{
	Q_OBJECT

	public:

	/*!
	 * \brief Konstruktor klasy TaskInfoWidget
	 * \param parent - rodzic kontrolki
	 */
		TaskInfoWidget(QWidget* parent = nullptr): QWidget(parent), m_currentRowSelected(-1) { init(); }

		/*!
		 * \brief Metoda pozwalająca na ustawienie wskaźnika do danych dyspozytora
		 * \param managerData
		 */
		void setRobotManagerData(RobotManagerData* managerData);

	public slots:

	/*!
	 * \brief Slot obsługujący aktualizację danych
	 */
	    void refreshDataViewed();
	private slots:

	/*!
	 * \brief Slot obsługujący wyświetlenie okna dodawania zadania
	 */
      void showAddTaskDialog();

      /*!
       * \brief Slot obsługi zmiany wyboru zadania
       * \param current - aktualnie wybrany indeks
       * \param previous - poprzednio wybrany indeks
       */
      void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);

      /*!
       * \brief Slot obsługujący żadanie usunięcia zadania
       */
      void removeSelected();


	private:

      /*!
       * \brief Metoda inicjująca kontrolkę
       */
		void init();

		/*!
		 * \brief Slot aktualizujący wyświetlaną całkowitą liczbę zadań
		 */
		void updateTotalTasksNumber()
		      { m_ui.totalTasksNumberLabel->setText(tr("%1").arg(m_managerData->tasksVector().size())); }

		/*!
		 * \brief Obiekt przechowujący wskaźniki do obiektów graficznych kontrolki
		 */
		Ui::UiTaskInfoWidget m_ui;

		/*!
		 * \brief Wskaźnik na model zadań
		 */
		TaskModel* m_taskModel;

		/*!
		 * \brief Indeks zaznaczonego zadania w tabeli
		 */
		int m_currentRowSelected;
};

#endif /* TASKINFOWIDGET_HPP_ */
