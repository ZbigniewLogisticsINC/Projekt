/*
 * GarageInfoWidget.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef GARAGEINFOWIDGET_HPP_
#define GARAGEINFOWIDGET_HPP_

#include <QWidget>
#include "ui_GarageInfoWidget.h"
#include "GarageModel.hpp"

/*!
 * \brief Kontrolka odpowiadająca za zarządzanie garażami
 */
class GarageInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT
  public:
    /*!
     * \brief Konstruktor klasy GarageInfoWidget
     * \param parent - rodzic okna dialogowego
     */
    GarageInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent), m_selectedRow(-1) { init(); }

    /*!
     * \brief Metoda pozwalająca określić wskaźnik na dane dyzpozytora
     * \param managerData - wskaźnik na dane dyspozytora, który ma zostać ustawiony
     */
    void setRobotManagerData(RobotManagerData* managerData);
    public slots:
    /*!
     * \brief Metoda wyświetlająca okno dodawania garażu
     */
      void showAddGarageDialog();

    public slots:
    /*!
     * \brief Metoda obsługująca aktualizację danych dyspozytora
     */
      void refreshDataViewed();
    private slots:
    /*!
     * \brief Metoda obsługująca zmianę wyboru garażu w tabeli
     */
      void updateSelectedRowNumber(const QModelIndex & current, const QModelIndex & previous);

      /*!
       * \brief Slot obsługujący usunięcie garażu
       */
      void removeSelected();

    private:
      /*!
       * \brief Metoda inicjująca kontrolkę
       */
      void init();

      /*!
       * \brief Metoda aktualizująca wyświetlanie ilośći wszystkich garaży
       */
      void updateTotalStorageNumber()
        { m_ui.totalGarageNumberLabel->setText(tr("%1").arg(m_managerData->garageVector().size())); }

      /*!
       * \brief Obiekt, który przechowuje wskaźniki do obiektów graficznych okna
       */
      Ui::UiGarageInfoWidget m_ui;

      /*!
       * \brief Wskaźnik do modelu garażu
       */
      GarageModel* m_garageModel;

      /*!
       * \brief Pole określające indeks zaznaczonego garażu w tabeli
       */
      int m_selectedRow;
};

#endif /* GARAGEINFOWIDGET_HPP_ */
