#ifndef USERCAR_H
#define USERCAR_H

#include <QGraphicsPixmapItem>
#include "car.h"

class UserCar : public QObject, public Car
{
  Q_OBJECT
public:
  UserCar(int widthRoad);
  ~UserCar() override = default;

  void initCar() override;
protected:
  void advance(int phase) override;
  void keyPressEvent(QKeyEvent *event) override;
signals:
  void carAccident();
private:
  int m_widthRoad;
};

#endif // USERCAR_H
