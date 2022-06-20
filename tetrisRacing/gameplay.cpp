#include "gameplay.h"
#include <QDebug>

Gameplay::Gameplay(const QSize& sizeRoad) : m_sizeRoad(sizeRoad)
{
  rg = QRandomGenerator::global();
  connect(&m_timerAddCar,&QTimer::timeout,this,&Gameplay::addCar);
  connect(&m_timerSpeedChange,&QTimer::timeout,[&currentSpeed = m_currentSpeed ,
          &currentAddCarInterval = m_currentAddCarInterval
          ,&timerAddCar = m_timerAddCar] () {

      currentSpeed++;
      if(currentAddCarInterval > 2000){
          currentAddCarInterval -= 400;
          timerAddCar.setInterval(currentAddCarInterval);

        }
    } );
}

Gameplay::~Gameplay()
{
  clearCars();
}

void Gameplay::startGame()
{
  m_currentAddCarInterval = MSEC_ADD_CAR_INTERVAL;
  m_currentSpeed = 4;
  m_timerAddCar.start(MSEC_ADD_CAR_INTERVAL);
  m_timerSpeedChange.start(INTERVAL_LEVEL_COMPLICATION);
}

void Gameplay::stopGame()
{
  m_timerAddCar.stop();
  m_timerSpeedChange.stop();
  clearCars();
}

void Gameplay::addCar()
{
  int randomX = rg->bounded(0,m_sizeRoad.width());
  Car* car = new Car;
  car->initCar();
  car->setPos(randomX,-100);
  car->setSpeed(m_currentSpeed);

  m_cars.push_back(car);

  emit addToScene(car);
}


void Gameplay::clearCars()
{
  while(!m_cars.empty()){
      delete m_cars.back();
      m_cars.pop_back();
    }
}
