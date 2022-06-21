#include "gameplay.h"
#include <QDebug>

Gameplay::Gameplay(const QSize& sizeRoad) : m_sizeRoad(sizeRoad)
{
  m_rg = QRandomGenerator::global();
  connect(&m_timerAddCar,&QTimer::timeout,this,&Gameplay::addCar); // по истечению таймера добавляем машины

  connect(&m_timerSpeedChange,&QTimer::timeout,[&currentSpeed = m_currentSpeed , // по истечению таймера меняем скорость и время добавления новых машин
          &currentAddCarInterval = m_currentAddCarInterval
          ,&timerAddCar = m_timerAddCar] () {

      currentSpeed++; //увеличиваем скорость
      if(currentAddCarInterval > 2000){ //если интервал добавления больше 2000 секнуд, продолжаем уменьшать
          currentAddCarInterval -= 400; //уменьшение итервала добавления новых машин на 400мсек
          timerAddCar.setInterval(currentAddCarInterval);//меняем интервал таймера добавления машин
        }
    } );

}

Gameplay::~Gameplay()
{
  clearCars(); //удаление машин
}

void Gameplay::startGame()
{
  m_currentAddCarInterval = MSEC_ADD_CAR_INTERVAL; //устанавливаем начальный интервал добавления новых машин
  m_currentSpeed = 4; //устанавливаем начальную скорость новых машин
  m_timerAddCar.start(MSEC_ADD_CAR_INTERVAL); // запуск таймера добавления машин
  m_timerSpeedChange.start(INTERVAL_LEVEL_COMPLICATION); //запуск таймера изменения скорости
}

void Gameplay::stopGame()
{
  m_timerAddCar.stop(); //остановка таймера добавления машин
  m_timerSpeedChange.stop();//остановка таймера изменения скорости
  clearCars(); //удаление машин
}

void Gameplay::addCar()
{
  int randomX = m_rg->bounded(0,m_sizeRoad.width()); //получим случайное число от 0 до макс. ширины дороги
  Car* car = new Car; //создание машины
  car->initCar(); //инициализация
  car->setPos(randomX,-100); //установка позиции, x - случайное число , y - (-100) для создания машины чуть выше видимой дороги
  car->setSpeed(m_currentSpeed);

  m_cars.push_back(car); //сохраняем указатель на объект(машины)

  emit addToScene(car); //сигнал для добавления машины на сцену
}


void Gameplay::clearCars()
{
  while(!m_cars.empty()){ // удаление машин из вектора
      delete m_cars.back();
      m_cars.pop_back();
    }
}
