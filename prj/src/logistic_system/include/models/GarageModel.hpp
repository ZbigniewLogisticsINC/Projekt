/*
 * GarageModel.hpp
 *
 *  Created on: May 2, 2015
 *      Author: mochman
 */

#ifndef GARAGEMODEL_HPP_
#define GARAGEMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

/*!
 * \brief Model danych garaży
 */
class GarageModel: public QAbstractTableModel, public DataManager
{
  public:

    /*!
     * \brief Model klasy GarageModel
     * \param parent - rodzic obiektu
     */
    GarageModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }

    /*!
     * \brief Metoda odpowiedzialna za dodawania garażu
     * \param garage - garaż, który ma zostać dodany
     * \return true jeśli dodawanie się powiodło, w.p.p. false
     */
    bool addGarage(const Garaz& garage);

    /*!
     * \brief Metoda odpowiedzialna za usuwanie garażu
     * \param id - identyfikator garażu
     * \return true jeśli się powiedzie, w.p.p. false
     */
    bool removeGarageId(unsigned int id);

    /*!
     * \brief Metoda ustawiająca wskaźnik na dane dyspozytora
     * \param data - wskaźnik na dane dyspozytora
     */
    void setRobotManagerData(RobotManagerData* data);

    /*!
     * \brief Metoda zwracająca ilość garaży
     * \param parent - indeks rodzica
     * \return Ilość garaży
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

#endif /* GARAGEMODEL_HPP_ */
