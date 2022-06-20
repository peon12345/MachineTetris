#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include "car.h"
#include <QRandomGenerator>

class Gameplay : public QObject
{
  Q_OBJECT
public:
  Gameplay(const QSize& sizeRoad);
  ~Gameplay();
public slots:

  void startGame();
  void stopGame();
private slots:
  void addCar();
private:
  void clearCars();
private:
  QRandomGenerator *rg;
  QSize m_sizeRoad;
  int m_currentSpeed;

  std::vector<Car*> m_cars;

  QTimer m_timerAddCar;
  static constexpr int MSEC_ADD_CAR_INTERVAL = 6000;
  int m_currentAddCarInterval;

  QTimer m_timerSpeedChange; // таймер, чтобы менять скорость каждые 10 сек
  static constexpr int INTERVAL_LEVEL_COMPLICATION = 10000; //интервал усложнения, каждые 10 секунд увеличиваем скорость и частотут появления машин
signals:
  void addToScene(Car* car);
};

#endif // GAMEPLAY_H
