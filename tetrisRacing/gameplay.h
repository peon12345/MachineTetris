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
  Gameplay(const QSize& sizeRoad); //конструктор принимающий размер дороги
  ~Gameplay(); //деструктор
public slots:

  void startGame(); //запускает таймеры добавления новых машин и увеличения скорости
  void stopGame(); //остановка таймеров и удаление машин
private slots:
  void addCar(); //слот для добавления машин, вызывается каждый раз, когда таймер испускает сигнал timeout
private:
  void clearCars(); // удаление всех машин, вызывается в деструкторе и после проигрыша
private:
  QRandomGenerator *m_rg; //генератор случайных чисел, для случайного появления машин по координате X
  QSize m_sizeRoad; // размер дороги
  int m_currentSpeed; //текущая скорость, увеличивается каждые 10.000 мсек

  std::vector<Car*> m_cars; //созданные машины

  QTimer m_timerAddCar; //таймер для добавления машин
  static constexpr int MSEC_ADD_CAR_INTERVAL = 6000; //начальное время добавления машин
  int m_currentAddCarInterval; // текущее время добавления машин, для усложнения уменьшается каждые 10.000 сек

  QTimer m_timerSpeedChange; // таймер, чтобы менять скорость каждые 10 сек
  static constexpr int INTERVAL_LEVEL_COMPLICATION = 10000; //интервал усложнения, каждые 10 секунд увеличиваем скорость и частоту появления машин
signals:
  void addToScene(Car* car);// сигнал о необходимости добавления машины на сцену
};

#endif // GAMEPLAY_H
