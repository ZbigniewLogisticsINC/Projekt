/*
 * TasksModels.hpp
 *
 *  Created on: Apr 16, 2015
 *      Author: mochman
 */

#ifndef TASKSMODELS_HPP_
#define TASKSMODELS_HPP_

#include <QAbstractTableModel>
#include <QList>
#include "DataManager.hpp"


/*!
 * \brief Model danych zadań
 */
class TaskModel: public QAbstractTableModel, public DataManager
{
  Q_OBJECT

  public:

  /*!
   * \brief Konstruktor klasy TaskModel
   * \param parent
   */
    TaskModel(QObject* parent = nullptr)
        : QAbstractTableModel(parent)
    {
      init();
    }

    /*!
     * \brief Metoda odpowiedzialna za dodawanie zadanie
     * \param task - zadanie do dodania
     */
    void addTask(const Zadanie& task);

    /*!
     * \brief Metoda ustawiająca wskaźnik na dane dyspozytora
     * \param data - wskaźnik na dane dyspozytora
     */
    void setRobotManagerData(RobotManagerData* data);

    /*!
     * \brief Metoda odpowiedzialna za usuwanie zadania
     * \param id - identyfikator zadania
     */
    void removeTaskId(int id);


    /*!
     * \brief Metoda zwracająca ilość zadań
     * \param parent - indeks rodzica
     * \return Ilość zadań
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    /*!
     * \brief Metoda zwracająca ilość kolumn
     * \param parent - indeks rodzica
     * \return Ilość kolumn
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    /*!
     * \brief Metoda określająca nagłówek tabeli
     * \param section - numer sekcji
     * \param orientation - rodzaj orientacji - poziomy lub pionowy
     * \param role - rodzaj danych
     * \return dane nagłówka tabeli określone przez parametry metody
     */
    QVariant headerData(int section, Qt::Orientation orientation,
        int role) const;

    /*!
     * \brief Metoda pobierająca odpowiednie dane z modelu
     * \param index - indeks danych
     * \param role - rodzaj danych
     * \return Dane określone przez indeks
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  private:
    void init();

};

#endif /* TASKSMODELS_HPP_ */
