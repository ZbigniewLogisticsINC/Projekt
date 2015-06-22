/*
 * TaskThread.hpp
 *
 *  Created on: Jun 18, 2015
 *      Author: mochman
 */

#ifndef TASKTHREAD_HPP_
#define TASKTHREAD_HPP_

#include <QThread>

/*!
 * \brief Wątek obsługi zadania
 */
class TaskThread: public QThread
{
    Q_OBJECT

  public:
    /*!
     * \brief Domyślny konstruktor klasy TaskThread
     * \param parent - rodzic wątku
     */
    TaskThread(QObject* parent = nullptr): QThread(parent), taskId(0) { connect(this,SIGNAL(finished()),this, SLOT(onFinished())); }

    /*!
     * \brief Pole określające identyfikator zadania
     */
    unsigned taskId;

    /*!
     * \brief Pole określające nazwę robota
     */
    std::string robotName;

    /*!
     * \brief Współrzedna x początkowego magazynu
     */
    double xStart;

    /*!
     * \brief Współrzedna y początkowego magazynu
     */
    double yStart;

    /*!
     * \brief Współrzedna x końcowego magazynu
     */
    double xEnd;

    /*!
     * \brief Współrzedna y końcowego magazynu
     */
    double yEnd;
  protected:

    /*!
     * \brief Metoda określająca, co będzie robić wątek
     */
    void run();
  signals:
  /*!
   * \brief Sygnał ukończenia zadania
   */
    void taskFinished(unsigned taskId);
  private slots:
  /*!
   * \brief Slot obsługujący zakończenie wątku
   */
    void onFinished() { emit taskFinished(taskId); }
};

#endif /* TASKTHREAD_HPP_ */
