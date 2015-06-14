/*
 * RobotInfoWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef ROBOTINFOWIDGET_HPP_
#define ROBOTINFOWIDGET_HPP_

#include <QWidget>
#include "ui_RobotInfoWidget.h"
#include "DataManager.hpp"
#include "RobotModel.hpp"

/*!
 * \brief Kontrolka odpowiedzialna za zarządzanie robotami
 */
class RobotInfoWidget: public QWidget, public DataManager
{
    Q_OBJECT

  public:

    /*!
     * \brief Konstruktor klasy RobotInfoWidget
     * \param parent - rodzic kontrolki
     */
    RobotInfoWidget(QWidget* parent = nullptr)
    : QWidget(parent)    { init(); }
    public slots:

    /*!
     * \brief Slot odpowiedzialny za obslugę aktualizacji danych
     */
      void refreshDataViewed();

      /*!
       * \brief Metoda pozwalająca ustawić wskaźnik na dane dyspozytora
       * \param managerData - wskaźnik na dane dyspozytora
       */
      void setRobotManagerData(RobotManagerData* managerData);
    private:

      /*!
       * \brief Obiekt przechowujący wskaźniki na obiekty graficzne kontrolki
       */
      Ui::UiRobotInfoWidget m_ui;

      /*!
       * \brief Metoda inicjująca kontrolkę
       */
      void init();

      /*!
       * \brief Wskaźnik na model robotów
       */
      RobotModel* m_robotModel;
    private slots:

    /*!
     * \brief SLot pokazujący okno dodania robota
     */
      void showAddDialog();
};

#endif /* ROBOTINFOWIDGET_HPP_ */
