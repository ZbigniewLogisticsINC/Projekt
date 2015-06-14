#ifndef ADD_ROBOT_DIALOG_HPP
#define ADD_ROBOT_DIALOG_HPP

#include <QDialog>
#include "ui_AddRobotDialog.h"
#include "RobotManagerDataObject.hpp"
#include "DataManager.hpp"

/*!
 * \brief Okno dialogowe dodawania robota
 */
class AddRobotDialog: public QDialog, public DataManager
{
    Q_OBJECT

  public:
    /*!
     * \brief Kontruktor klasy AddRobotDialog
     * \param parent - rodzic okna dialogowe
     */
    AddRobotDialog(QWidget* parent = nullptr): QDialog(parent), m_managerDataObject(nullptr) { init(); }

    /*!
     * \brief Metoda pozwalająca ustawić wskaźnik do danych dyspozytora
     * \param managerData
     */
    void setRobotManagerData(RobotManagerData* managerData);

    /*!
     * \brief - Metoda sprawdzająca czy wszystkie wybrane przez użytkownika pola są wybrane poprawnie
     * \return true jeśli wszystkie pola są wypełnione prawidłowo, w.p.p. false
     */
    bool robotCorrect() const;

    /*!
     * \brief Pozwala otrzymać obiekt robota, który został wybrany przez użytkownika
     * \return Obiekt robota wybranego przez użytkownika
     */
    const Robot& robot() const { return m_robot; }
  private slots:
  /*!
   * \brief Slot ustawia obiekt robota zgodnie z tym, co wybrał użytkownik
   *
   * Obiekt robota jest ustawiany, gdy wybrane dane przez użytkownika są poprawne
   */
    void setRobotInfo();
  private:

    /*!
     * \brief Metoda inicjująca okno dialogowe
     */
    void init();
    /*!
     * \brief Metoda odpowiedzialna za wypełnienie dostępnych garaży
     */
    void fillGarageCombo();

    /*!
     * \brief Pole prechowujące instancję robota zgodnego z tym, co wybrał użytkownik
     */
    Robot m_robot;

    /*!
     * \brief Pole przechowujące wskaźniki na obiekty graficzne okna
     */
    Ui::UiAddRobotDialog m_ui;

    /*!
     * \brief Pole przechowujące wskaźnik na obiekt informacji dyzpozytora
     */
    RobotManagerDataObject* m_managerDataObject;
};

#endif
