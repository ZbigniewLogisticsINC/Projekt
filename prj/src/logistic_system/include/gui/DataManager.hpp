/*
 * DataManager.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef DATAMANAGER_HPP_
#define DATAMANAGER_HPP_

#include "RobotManagerDataObject.hpp"

/*!
 * \brief Klasa odpowiedzialna za zarządzanie danymi dyspozytora
 *
 * Jest przeznaczona o dziedziczenia w kontrolkach i okienkach aplikacji dyspozytora
 */
class DataManager
{
  public:

    /*!
     * \brief Konstruktor klasy DataManager
     */
    DataManager():m_managerData(nullptr) { }

    /*!
     * \brief Metoda pozwalająca ustawić wskaźnik na dane dyspozytora
     * \param managerData - wskaźnik na dane dyspozytora
     */
    virtual void setRobotManagerData(RobotManagerData* managerData) { m_managerData = managerData; }

    /*!
     * \brief Metoda pozwalająca na pobranie wskaźnika do danych dyspozytora
     * \return
     */
    RobotManagerData* getRobotManagerData()  { return m_managerData; }

    /*!
     * \brief Wirtualny destruktor klasy DataManager
     */
    virtual ~DataManager() { }
  protected:

    /*!
     * \brief Pole przechowujące wskaźnik na dane dyspozytora
     */
    RobotManagerData* m_managerData;
};

#endif /* DATAMANAGER_HPP_ */
