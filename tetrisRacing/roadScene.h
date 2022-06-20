#ifndef ROADSCENE_H
#define ROADSCENE_H

#include <QGraphicsScene>
#include "gameplay.h"
#include "usercar.h"
#include <QPushButton>

class CustomScene : public QGraphicsScene
{
public:
  CustomScene(const QSize& size);

private:
  void addObjects();
  void setSize(const QSize& size);
private slots:
  void showItem(QGraphicsItem *item);
private:

  static constexpr int MSEC_ADVANCE = 200;
  QTimer m_timerAdvance;
  Gameplay m_gameplay;
  UserCar* m_car;
  QPushButton* m_buttonStart;
  QPushButton* m_buttonExit;
};

#endif // ROADSCENE_H
