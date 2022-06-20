#include "roadScene.h"
#include <QKeyEvent>
#include <road.h>



CustomScene::CustomScene(const QSize &size) : m_gameplay(size)
{ 
 connect(&m_timerAdvance,&QTimer::timeout, this,&QGraphicsScene::advance);
 connect(&m_gameplay,&Gameplay::addToScene,this,&CustomScene::showItem);


 m_timerAdvance.start(MSEC_ADVANCE);

 setSize(size);


 setStickyFocus(true);
 m_car = new UserCar(sceneRect().width());
 m_car->initCar();
 m_car->setPos(sceneRect().width()/2 - m_car->boundingRect().width() /2,sceneRect().height() - m_car->boundingRect().height());

 connect(m_car,&UserCar::carAccident,[&gameplay = m_gameplay ,&buttonStart = m_buttonStart,&buttonExit = m_buttonExit]() {

   gameplay.stopGame();
   buttonExit->show();

   buttonStart->setText("Рестарт");
   buttonStart->show();

   } );


 addObjects();

}

void CustomScene::showItem(QGraphicsItem *item)
{
 addItem(item);
}

void CustomScene::addObjects()
{

  Road* r =  new Road(QSize(sceneRect().width(),sceneRect().height()));
  r->setPos(0,0);
  addItem(r);

  m_buttonStart = new QPushButton;
  m_buttonStart->resize(100,50);
  m_buttonStart->setText("Старт");

  m_buttonExit = new QPushButton;
  m_buttonExit->resize(100,50);
  m_buttonExit->setText("Выход");

  const int interval = 50;
  int xPosButton = ( sceneRect().width()/2 ) -  m_buttonStart->width() - interval;
  int yPosButton = 100;

  m_buttonStart->move( xPosButton , yPosButton);
  m_buttonExit->move( xPosButton + m_buttonStart->width()+ interval*2, yPosButton);

  addWidget(m_buttonStart);
  addWidget(m_buttonExit);

  connect(m_buttonStart,&QPushButton::clicked,[this] () {

      setFocusItem(m_car);
      m_buttonExit->hide();
      m_buttonStart->hide();
      m_gameplay.startGame();

      m_car->setPos(sceneRect().width()/2 - m_car->boundingRect().width() /2,sceneRect().height() - m_car->boundingRect().height());
      m_car->show();

    } );


  connect(m_buttonExit,&QPushButton::clicked ,[] () {exit(1);} );


  addItem(m_car);



}

void CustomScene::setSize(const QSize &size)
{
  setSceneRect(0,0,size.width()-5,size.height()-5);
}

