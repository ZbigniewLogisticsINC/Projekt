/*
 * RobotManagerDataObject.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef ROBOTMANAGERDATAOBJECT_HPP_
#define ROBOTMANAGERDATAOBJECT_HPP_

#include <QObject>
#include "RobotManagerData.hpp"

/*!
 * \brief Klasa odpowiedzialna za połączenie danych dyspozytora z sygnalizacją ich zmiany
 */
class RobotManagerDataObject:public QObject
{
    Q_OBJECT

  public:
    /*!
     * \brief Konstruktor klasy RobotManagerDataObject
     *
     * \param parent - rodzic utworzonego obiektu
     */

    RobotManagerDataObject(QObject* parent = nullptr):QObject(parent), m_managerData(nullptr) { }

    /*!
     * \brief -Metoda pozwala ustawić wskaźnik na dane zarządcy
     * \param managerData
     */
    void setRobotManagerData(RobotManagerData* managerData );

    /*!
     * \brief Metoda pozwalająca dostać się do obiektu danych
     * \return Zwracany jest wskażnik do obiektu danych dyspozytora
     */
    RobotManagerData* getRobotManagerData() { return m_managerData; }


    //void update() { /*todo do zrobienia*/ }
  signals:

  /*!
   * \brief Sygnał, który jest emitowany, gdy dane są zaktualizowane
   */
    void dataUpdated();
  protected:

    /*!
     * \brief Wskaźnik na dane dyspozytora
     */
    RobotManagerData* m_managerData;
};

#endif /* ROBOTMANAGERDATAOBJECT_HPP_ */
