/*
 * AddGarageDialog.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef ADDGARAGEDIALOG_HPP_
#define ADDGARAGEDIALOG_HPP_

#include <QDialog>
#include "DataManager.hpp"
#include "ui_AddGarageDialog.h"

/*!
 * \brief Okno dialogowego dodawania garażu
 */
class AddGarageDialog: public QDialog, public DataManager
{
    Q_OBJECT
  public:

    /*!
     * \brief Konstruktor klasy AddGarageDialog
     *
     * \param parent - rodzic okna dialogowego
     */
    AddGarageDialog(QWidget* parent = nullptr): QDialog(parent) { init(); }

    /*!
     * \brief Pozwala otrzymać obiekt garażu, który został wybrany przez użytkownika
     * \return
     */
    const Garaz& garage() const { return m_garage; }
  private slots:
  /*!
   * \brief Slot, który konstruuje obiekt po kliknięciu OK w oknie dialogowym
   */
    void setGarageFromDialog();
  private:
    /*!
     * \brief Metoda inicjująca okno dialogowe
     */
    void init();

    /*!
     * \brief Pole przechowujące wskaźniki do graficznych obiektów okna dialogowego
     */
    Ui::UiAddGarageDialog m_ui;
    /*!
     * \brief Pole przechowujące instancję garażu, który odzwierciedla wyspecyfikowany przez użytkownika garaż
     */
    Garaz m_garage;

    /*!
     * \brief Pole przechowujące id, które ma zostać przypisane garażowi
     */
    static unsigned int s_id;
};

#endif /* ADDGARAGEDIALOG_HPP_ */
