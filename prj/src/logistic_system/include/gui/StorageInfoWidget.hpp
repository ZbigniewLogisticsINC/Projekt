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
#include "StorageModel.hpp"

/*!
 * \brief Kontrolka odpowiedzialna za zarządzanie magazynami
 */
class StorageInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT
  public:
    /*!
     * \brief Konstruktor klasy StorageInfoWidget
     * \param parent - rodzic kontrolki
     */
    StorageInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent), m_selectedRow(-1) { init(); }

    /*!
     * \brief Metoda pozwalająca ustawić wskaźnik na dane dyspozytora
     * \param managerData - wskaźnik na dane dyspozytora
     */
    void setRobotManagerData(RobotManagerData* managerData);
    public slots:

    /*!
     * \brief Slot pokazujący okno dodawania magazynu
     */
      void showAddStorageDialog();

      /*!
       * \brief Slot obsługujący aktualizację danych
       */
      void refreshDataViewed();
    private slots:

    /*!
     * \brief Slot obsługujący zmianę zaznaczenia w tabeli magazynów
     */
      void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);

      /*!
       * \brief Slot obsługujący usuwanie magazynu
       */
      void removeSelected();
    private:

      /*!
       * \brief Metoda inicjująca kontrolkę
       */
      void init();

      /*!
       * \brief Metoda aktualizująca wyświetlaną liczbę magazynów
       */
      void updateTotalStorageNumber()
        { m_ui.totalStorageNumberLabel->setText(tr("%1").arg(m_managerData->storeVector().size())); }

      /*!
       * \brief Obiekt przechowujący wskaźniki do obiektów graficznych kontrolki
       */
      Ui::UiStorageInfoWidget m_ui;

      /*!
       * \brief Pole przechowujące wskaźnik na odel magazynów
       */
      StorageModel* m_storageModel;

      /*!
       * \brief Pole przechowujące indeks zaznaczonego magazynu w tabeli
       */
      int m_selectedRow;
};

#endif /* STORAGEINFOWIDGET_HPP_ */
