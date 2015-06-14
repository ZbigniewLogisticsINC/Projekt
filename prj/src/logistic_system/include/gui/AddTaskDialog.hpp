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
#include "DataManager.hpp"
#include "zadanie.hpp"

/*!
 * \brief Okno odpowiedzialne za dodawanie zadań
 */
class AddTaskDialog: public QDialog, public DataManager
{
  Q_OBJECT
  public:
  /*!
   * \brief Konstruktor klasy AddTaskDialog
   * \param parent - rodzic okna
   */
    AddTaskDialog(QWidget* parent = nullptr)
        : QDialog(parent), m_taskCorrect(false) { init(); }

    /*!
     * \brief Metoda pozwalająca ustawić wskaźnik do informacji dyspozytora
     * \param managerData - wskaźnik, który ma zostać ustawiony
     */
    void setRobotManagerData(RobotManagerData* managerData);

    /*!
     * \brief Metoda pozwalająca otrzymać obiekt zadania zgodny z tym, co wybrał użytkownik
     * \return obiekt zadania zgodny z tym, co wybrał użytkownik
     */
    const Zadanie& task() const { return m_task; }

    /*!
     * \brief Metoda sprawdza czy wyspecyfikowane prez użytkownika zadanie jest poprawne
     * \return true jeśl zadanie jest poprawne, w.p.p false
     */
    bool taskCorrect() const { return m_taskCorrect; }
  public slots:
  /*!
   * \brief Slot wywoływany wtedy, gdy dane dyspozytora się zmienią
   */
    void refreshDataViewed();

    /*!
     * \brief Slot obsługi aktualizacji magazynów docelowych
     * \param startStoreId - łańcuch znaków określający id magazynu skąd ma wystartować robot
     */
    void refreshDestCombo(QString startStoreId);
  private:
    /*!
     * \brief Metoda inicjująca okno dialogowe
     */
    void init();

    /*!
     * \brief Obiekt przechowujące wskaźniki do obiektó© graficznych okna dialogowego
     */
    Ui::UiAddTaskDialog m_ui;

    /*!
     * \brief Pole przechowujące instancję zadania, które jest zgodne
     */
    Zadanie m_task;

    /*!
     * \brief Pole statyczne przechowujące, jakie id powinno mieć kolejne zadanie
     */
    static unsigned int s_taskId;

    /*!
     * \brief Pole przechowujące informacje o poprawności zadania wyspecyfikowanego przez użytkownika
     */
    bool m_taskCorrect;
  private slots:

  /*!
   * \brief Slot ustawiający instancję zadania, zgodną z tym, co wybrał użytkownik
   */
    void setTaskFromDialog();
};

#endif /* ADDTASKDIALOG_HPP_ */
