#include "roadScene.h"
#include <QKeyEvent>
#include <road.h>



CustomScene::CustomScene(const QSize &size) : m_gameplay(size)
{ 
  connect(&m_timerAdvance,&QTimer::timeout, this,&QGraphicsScene::advance); // по истечению таймера, вызывать у каждого объекта на сцене метод advance
  connect(&m_gameplay,&Gameplay::addToScene,this,&CustomScene::showItem);// при сигнале addToScene, добавляет переданный объект на сцену

  m_timerAdvance.start(MSEC_ADVANCE); //запуск таймера для вызова advance у объектов сцены

  setSize(size); //установка размера сцены

  setStickyFocus(true); // не убирать фокус с текущего элемента, если мы кликнем мышью по элементу, который не объявлен как выделяемый

  m_car = new UserCar(sceneRect().width()); //создаем машину игрока
  m_car->initCar();
  m_car->setPos(sceneRect().width()/2 - m_car->boundingRect().width() /2,sceneRect().height() - m_car->boundingRect().height()); //установка позиции
                                                                                                                                 //с расчетом центра дороги


  connect(m_car,&UserCar::carAccident,[&gameplay = m_gameplay ,&buttonStart = m_buttonStart,&buttonExit = m_buttonExit]() { //если машина игрока испустила сигнал о столкновении

      gameplay.stopGame(); // останавливаем таймеры добавления машин и изменения скорости
      buttonExit->show(); //показываем кнопку выход

      buttonStart->setText("Рестарт"); //меняем текст у кнопки старт на рестарт
      buttonStart->show();//показываем кнопку рестарт

    } );


  addObjects(); // добавления машины игрока, дороги и кнопок для старта игры

}

void CustomScene::showItem(QGraphicsItem *item)
{
  addItem(item); //добавление элемента на сцену
}

void CustomScene::addObjects()
{

  Road* road =  new Road(QSize(sceneRect().width(),sceneRect().height())); //Создание дороги
  road->setPos(0,0);//установка позиции
  addItem(road); //добавление дороги на сцену

  m_buttonStart = new QPushButton; //создание кнопки старт
  m_buttonStart->resize(100,50); //установка размера кнопки
  m_buttonStart->setText("Старт"); //установка текста кнопки

  m_buttonExit = new QPushButton;//создание кнопки выход
  m_buttonExit->resize(100,50);//установка размера кнопки
  m_buttonExit->setText("Выход");//установка текста кнопки

  const int interval = 50; //интервал между кнопками
  int xPosButton = ( sceneRect().width()/2 ) -  m_buttonStart->width() - interval; //вычисление центра дороги для кнопки по координа х
  int yPosButton = 100; //позиция y кнопки

  m_buttonStart->move( xPosButton , yPosButton); //перемещаем кнопку старт
  m_buttonExit->move( xPosButton + m_buttonStart->width()+ interval*2, yPosButton); //перемещаем кнопку выход

  addWidget(m_buttonStart); //добавление кнопок на сцену
  addWidget(m_buttonExit);

  connect(m_buttonStart,&QPushButton::clicked,[this] () { // при клике мышью на кнопку старт

      setFocusItem(m_car); // установить фокус на машину игрока
      m_buttonExit->hide(); //скрыть кнопку
      m_buttonStart->hide();//скрыть кнопку
      m_gameplay.startGame();//запустить таймеры добавления машин и изменения скорости

      m_car->setPos(sceneRect().width()/2 - m_car->boundingRect().width() /2,sceneRect().height() - m_car->boundingRect().height()); // устанавливаем машину игрока по центру дороги
      m_car->show(); // показываем машину игрока

    } );


  connect(m_buttonExit,&QPushButton::clicked ,[] () {exit(1);} ); // если нажали на кнопку выход, выходим из приложения


  addItem(m_car); //добавлеяем машину игрока на сцену

}

void CustomScene::setSize(const QSize &size)
{
  setSceneRect(0,0,size.width()-5,size.height()-5); //установка размера сцены
}

