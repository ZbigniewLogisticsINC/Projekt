/*
 * AddStorageDialog.hpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#ifndef ADDSTORAGEDIALOG_HPP_
#define ADDSTORAGEDIALOG_HPP_

#include <QDialog>
#include "DataManager.hpp"
#include "ui_AddStorageDialog.h"

/*!
 * \brief Okno dialogowe odpowiedzialne za dodawanie magazynu
 */
class AddStorageDialog: public QDialog, public DataManager
{
    Q_OBJECT

  public:
    /*!
     * \brief Domyślny konstruktor okna dialogowego
     * \param parent - rodzic okna dialogowego
     */
    AddStorageDialog(QWidget* parent = nullptr): QDialog(parent) { init(); }

    /*!
     * \brief Metoda pozwalająca otrzymać obiekt magazynu na podstawie wybranych pól przez użytkownika
     * \return obiekt magazynu ustawiony przez użytkownika
     */
    const Magazyn& store() const { return m_store; }
  private slots:

  /*!
   * \brief Slot obsługujący akceptację danych okna
   */
    void setStorageFromDialog();

  private:

    /*!
     * \brief Metoda inicjująca szatę graficzną okna
     */
    void init();

    /*!
     * \brief Pole przechowujące wskaźniki na obiekty graficzne okna
     */
    Ui::UiAddStorageDialog m_ui;

    /*!
     * \brief Obiekt magazynu
     */
    Magazyn m_store;

    /*!
     * \brief Zmienna określająca, jaki identyfikator będzie mieć kolejny dodany magazyn
     */
    static unsigned int s_id;
};


#endif /* ADDSTORAGEDIALOG_HPP_ */
