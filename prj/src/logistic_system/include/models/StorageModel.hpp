/*
 * StorageModel.hpp
 *
 *  Created on: May 1, 2015
 *      Author: mochman
 */

#ifndef STORAGEMODEL_HPP_
#define STORAGEMODEL_HPP_

#include <QAbstractTableModel>
#include "DataManager.hpp"

/*!
 * \brief Model danych magazynu
 */
class StorageModel: public QAbstractTableModel, public DataManager
{
  public:

    /*!
     * \brief Konstruktor klasy StorageModel
     * \param parent - rodzic modelu
     */
    StorageModel(QObject* parent = nullptr):QAbstractTableModel(parent) { }

    /*!
     * \brief Metoda odpowiedzialna za dodawanie magazynu
     * \param storage - magazyn, który ma zostać dodany
     * \return true, jeśli dodanie się powiedzie, w.p.p. false
     */
    bool addStore(const Magazyn& storage);

    /*!
     * \brief Metoda odpowiedzialna za usuwanie magazynu
     * \param id - identyfikator magazynu
     * \return true, jeśli dodanie się powiedzie, w.p.p. false
     */
    bool removeStoreId(unsigned int id);

    /*!
     * \brief Metoda ustawiająca wskaźnik na dane dyspozytora
     * \param data - wskaźnik na dane dyspozytora
     */
    void setRobotManagerData(RobotManagerData* data);


    /*!
     * \brief Metoda zwracająca ilość magazynów
     * \param parent - indeks rodzica
     * \return Ilość magazynów
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

#endif /* STORAGEMODEL_HPP_ */
