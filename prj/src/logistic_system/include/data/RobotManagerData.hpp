/*
 * robot_manager_data.hpp
 *
 *  Created on: Apr 29, 2015
 *      Author: mochman
 */

#ifndef ROBOT_MANAGER_DATA_HPP_
#define ROBOT_MANAGER_DATA_HPP_

#include <QObject>
#include "zadanie.hpp"
#include "robot.hpp"
#include "magazyn.hpp"
#include "garaz.hpp"
#include <list>
#include <QTimer>

/*!
 * \brief Klasa odpowiedzialna za zarządzanie danymi o systemie logistycznym
 */
class RobotManagerData: public QObject
{
  Q_OBJECT
  public:
  /*!
   * \brief Domyślny konstruktor klasy RobotManagerData
   * \param parent - rodzic obiektu
   */
  RobotManagerData(QObject* parent = nullptr);

  /*!
   * \brief Metoda pozwalająca dodać robota
   * \param robot - robot, który ma zostać dodany
   * \return true, jeśli dodano robota, w.p.p. false
   */
  bool addRobot(const Robot& robot);

  /*!
   * \brief Metoda pozwalająca dodać magazyn
   * \param magazyn - magazyn, który ma zostać dodany
   * \return true, jeśli dodano magazyn, w.p.p. false
   */
  bool addStore(const Magazyn& magazyn);

  /*!
   * \brief Metoda pozwalająca dodać garaż
   * \param garaz - garaż, który ma zostać dodany
   * \return true, jeśli dodano garaż, w.p.p. false
   */
  bool addGarage(const Garaz& garaz);

  /*!
   * \brief Metoda pozwalająca dodać zadanie
   * \param task - zadanie, któ©e ma zostać dodane
   * \return true, jeśli dodano zadanie, w.p.p. false
   */
  bool addTask(const Zadanie& task);

  /*!
   * \brief Metoda pozwalająca znaleźć robota po identyfikatorze
   * @param id - identyfikator
   * @return wskaźnik na robota
   */
  Robot* findRobotId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca znaleźć magazyn po identyfikatorze
   * \param id - identyfikator
   * \return wskaźnik na magazyn
   */
  Magazyn* findStoreId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca znaleźć garaż po identyfikatorze
   * \param id - identyfikator
   * \return wskaźnik na garaż
   */
  Garaz* findGarageId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca znaleźć zadanie po identyfikatorze
   * \param id - identyfikator
   * \return wskaźnik na zadanie
   */
  Zadanie* findTaskId(unsigned id);

  /*!
   * \brief Metoda pozwalająca znaleźć wolnego robota dla podanego zadania
   * \param taskId -identyfikator zadania
   * \return identyfikator robota, jeśli nie znaleziono takiego robota to -1
   */
  int findFreeRobotForTask(unsigned taskId);

  /*!
   * \brief Metoda pozwalająca na sprawdzenie czy istnieje magazyn o podanym id
   * \param id - identyfikator
   * \return true, jeśli istnieje, w.p.p. false
   */
  bool containsStoreId(unsigned int id) const;

  /*!
   * \brief Metoda pozwalająca na sprawdzenie czy istnieje garaż o podanym id
   * \param id - identyfikator
   * \return true, jeśli istnieje, w.p.p. false
   */
  bool containsGarageId(unsigned int id) const;

  /*!
   * \brief Metoda pozwalająca na sprawdzenie czy istnieje robot o podanym id
   * \param id - identyfikator
   * \return true, jeśli istnieje, w.p.p. false
   */
  bool containsRobotId(unsigned int id) const;

  /*!
   * \brief Metoda pozwalająca na sprawdzenie czy istnieje zadanie o podanym id
   * \param id - identyfikator
   * \return true, jeśli istnieje, w.p.p. false
   */
  bool containsTaskId(unsigned int id) const;

  /*!
   * \brief Metoda pozwalająca usunąć zdaanie o określonym id
   * \param id - identyfikator
   * \return - true, jeśli się usunięcie się powiedzie, w.p.p. false (również, gdy nie ma takiego id)
   */
  bool removeTaskId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca usunąć magazyn o określonym id
   * \param id - identyfikator
   * \return - true, jeśli się usunięcie się powiedzie, w.p.p. false (również, gdy nie ma takiego id)
   */
  bool removeStorageId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca usunąć garaż o określonym id
   * \param id - identyfikator
   * \return - true, jeśli się usunięcie się powiedzie, w.p.p. false (również, gdy nie ma takiego id)
   */
  bool removeGarageId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca usunąć robota o określonym id
   * \param id - identyfikator
   * \return - true, jeśli się usunięcie się powiedzie, w.p.p. false (również, gdy nie ma takiego id)
   */
  bool removeRobotId(unsigned int id);

  /*!
   * \brief Metoda pozwalająca zmienić informacje na zdarzenie jego zakończenia
   * \param id - identyfikator ukończonego zadania
   * \return true, jeśli się powiedzie, w.p.p. false
   */
  bool changeTaskStatusOnCompletedId(unsigned id);

  /*!
   * \brief Metoda pozwalająca uruchomić kolejne zadania
   * \param runNextTasksId [out] - wektor identyfikatorów zadań, które mogą zostać rozpoczęte
   */
  void runNextTasks(std::vector<unsigned>& runNextTasksId);

  /*!
   * \brief Metoda pozwalająca otrzymać wektor zadań
   * \return wektor zadań
   */
  const std::vector<Zadanie>& tasksVector() const { return m_taskVector; }

  /*!
   * \brief Metoda pozwalająca otrzymać wektor magazynów
   * \return wektor magazynów
   */
  const std::vector<Magazyn>& storeVector() const { return m_storeVector; }

  /*!
   * \brief Metoda pozwalająca otrzymać wektor robotów
   * \return wektor robotów
   */
  const std::vector<Robot>& robotVector() const { return m_robotVector; }

  /*!
   * \brief Metoda pozwalająca otrzymać wektor garaży
   * \return wektor garaży
   */
  const std::vector<Garaz>& garageVector() const { return m_garageVector; }
public slots:

/*!
 * \brief Metoda aktualizująca dane z pliku
 * \param dirPath - katalog, w którym są pliki potrzebne do aktualizacji
 */
  void update(const std::string& dirPath);
signals:
/*!
 * \brief Sygnał ozaczający aktualizację danych
 */
  void dataUpdated();
private:
  /*!
   * \brief Wektor zadań
   */
  std::vector<Zadanie> m_taskVector;

  /*!
   * \brief Wektor magazynów
   */
  std::vector<Magazyn> m_storeVector;

  /*!
   * \brief Wektor garaży
   */
  std::vector<Garaz> m_garageVector;

  /*!
   * \brief Wektor robotów
   */
  std::vector<Robot> m_robotVector;
};

#endif /* ROBOT_MANAGER_DATA_HPP_ */
