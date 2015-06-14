/*
 * RobotModel.hpp
 *
 *  Created on: May 15, 2015
 *      Author: mochman
 */

#ifndef ROBOTMODEL_HPP_
#define ROBOTMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

/*!
 * \brief Model danych robota
 */
class RobotModel: public QAbstractTableModel, public DataManager
{
  public:

    /*!
     * \brief Konstruktor klasy RobotModel
     * \param parent
     */
    RobotModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }

    /*!
     * \brief Metoda odpowiedzialna za dodawanie robota
     * \param robot - robot, który ma zostać dodany
     * \return
     */
    bool addRobot(const Robot& robot);

    /*!
     * \brief Metoda odpowiedzialna za usuwanie robota
     * \param id - identyfikator robot, który ma zostać usunięty
     * \return true, jeśli wszystko się powiedzie, w.p.p.
     */
    bool removeRobotId(unsigned int id);

    /*!
     * \brief Metoda ustawiająca wskaźnik na dane dyspozytora
     * \param data - wskaźnik na dane dyspozytora
     */
    void setRobotManagerData(RobotManagerData* data);

    /*!
     * \brief Metoda zwracająca ilość robotów
     * \param parent - indeks rodzica
     * \return Ilość robotów
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
};



#endif /* ROBOTMODEL_HPP_ */
