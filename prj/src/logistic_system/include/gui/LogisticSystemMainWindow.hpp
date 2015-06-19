#ifndef LOGISTIC_SYSTEM_MAIN_WINDOW_HPP
#define LOGISTIC_SYSTEM_MAIN_WINDOW_HPP

#include <QMainWindow>
#include <ros/ros.h>
#include "ui_LogisticSystemMainWindow.h"

#include "RobotManagerDataObject.hpp"
#include "DataManager.hpp"
#include "UpdateRobotDataThread.hpp"

/*!
 * \brief Główne okno aplikacji dyspozytora
 */
class LogisticSystemMainWindow: public QMainWindow, public DataManager
{
  Q_OBJECT

  public:

  /*!
   * \brief Konstruktor klasy
   * \param parent - rodzic
   */
  LogisticSystemMainWindow(QWidget* parent = nullptr);

  /*!
   * \brief Metoda pozwalająca ustawić wskaźnik na dane dyspozytora
   * \param managerData - wskaźnik na dane dyspozytora
   */
  void setRobotManagerData(RobotManagerData* managerData);
public slots:

  /*!
   * \brief Slot obsługującey aktualizację danych dyspozytora
   */
  void refreshDataViewed();
protected:

  /*!
   * \brief Metoda obsługująca zdarzenie zamykania okna
   * \param closeEvent - informacje o zdarzeniu zamykania okna
   */
  void closeEvent(QCloseEvent* closeEvent);
private:

  /*!
   * \brief Obiekt przechowujący wskaźniki na obiekty graficzne okna
   */
  Ui::UiLogisticSystemMainWindow m_ui;

  /*!
   * \brief Metoda inicjująca okno
   */
  void init();
  /*!
   * \brief Timer wywołujący zdarzenie aktualizacji danych z ROS
   */
  QTimer* m_rosTimer;

  QTimer* m_taskManagerTimer;

  //ros::NodeHandle nh;

  UpdateRobotDataThread* m_rosUpdateThread;

  QMap<unsigned, QThread* > m_taskThreadsMap;

private slots:

  /*!
   * \brief Slot wyświetlający okno "O programie"
   */
  void showAboutWndDialog();

  /*!
   * \brief Slot wywoływany aby zaktualizować rzeczy z ROS
   */
  void onUpdateROS();

  void runNextTasks();

  void onTaskCompleted(unsigned taskId);
};

#endif
