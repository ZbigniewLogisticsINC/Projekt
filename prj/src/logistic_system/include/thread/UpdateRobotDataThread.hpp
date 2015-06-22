/*
 * UpdateRobotDataThread.hpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#ifndef UPDATEROBOTDATATHREAD_HPP_
#define UPDATEROBOTDATATHREAD_HPP_

#include <QThread>
#include "DataManager.hpp"
#include <iostream> // todo usunąć

/*!
 * \brief Wątek obsługujący aktualizację danych o robotach
 */
class UpdateRobotDataThread: public QThread, public DataManager
{
  public:
    /*!
     * \brief Domyślny konstruktor klasy UpdateRobotDataThread
     * \param parent - rodzic wątku
     */
    UpdateRobotDataThread(QObject* parent = nullptr): QThread(parent), waitTimeMs(1000) { }

    /*!
     * \brief Metoda określająca co będzie wykonywać wątek
     */
    void run();

    /*!
     * \brief Pole określające co ile ms mają być aktualizowane dane
     */
    unsigned waitTimeMs;

    /*!
     * \brief Pole określające ścieżkę do folderu danych, w którym mają zostać zapisane dane
     */
    std::string dirPath;
};

#endif /* UPDATEROBOTDATATHREAD_HPP_ */
