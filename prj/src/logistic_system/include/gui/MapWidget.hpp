/*
 * MapWidget.hpp
 *
 *  Created on: Apr 15, 2015
 *      Author: mochman
 */

#ifndef MAPWIDGET_HPP_
#define MAPWIDGET_HPP_

#include <QWidget>
#include <QPainter>
#include "DataManager.hpp"

/*!
 * \brief Kontrolka mapy
 */
class MapWidget: public QWidget, public DataManager
{
  Q_OBJECT
  public:

  /*!
   * Konstruktor klasy MapWidget
   * @param parent
   */
    MapWidget(QWidget* parent = nullptr)
        : QWidget(parent)
    {
    }

    /*!
     * \brief Pole statyczne określające szerokość sali w metrach
     */
    static const double WIDTH;

    /*!
     * \brief Pole statyczne określające szerokość sali w metrach
     */
    static const double HEIGHT;
  public slots:
  /*!
   * \brief Metoda aktualizujące dane wyświetlane przez kontrolkę
   */
    void refreshDataViewed();
  protected:

    /*!
     * \brief Metoda rysująca mapę
     * \param paintEvent - informacje o rysowaniu
     */
    void paintEvent(QPaintEvent* paintEvent);
  private:
    /*!
     * \brief Metoda pozwalająca określić o ile należy obrócić obrazek
     * \param x1 - współrzędna x położenia
     * \param y1 - współrzędna y położenia
     * \param x2 - współrzędna x wjazdu
     * \param y2 - współrzędna x wjazdu
     * \return Kąt obrotu wyrażony w stopniach
     */
    double getAngleInDegrees(double x1, double y1, double x2, double y2) const;

    /*!
     * \brief Metoda rysująca wszystkie garaże
     * \param painter - obiekt, przy pomocy który można rysować
     */
    void drawAllGarage(QPainter& painter);

    /*!
     * \brief Metoda rysująca wszystkie magazyny
     * \param painter - obiekt, przy pomocy który można rysować
     */
    void drawAllStorage(QPainter& painter);

    /*!
     * \brief Metoda rysująca wszystkie roboty
     * \param painter - obiekt, przy pomocy który można rysować
     */
    void drawAllRobot(QPainter& painter);
};

#endif /* MAPWIDGET_HPP_ */
