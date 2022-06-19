#ifndef USERCAR_H
#define USERCAR_H

#include <QGraphicsPixmapItem>

class UserCar : public QGraphicsPixmapItem
{
public:
  UserCar();


  // QGraphicsScene interface
protected:
  void keyPressEvent(QKeyEvent *event) override;
};

#endif // USERCAR_H
