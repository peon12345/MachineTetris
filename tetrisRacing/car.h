#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>



class Car : public QGraphicsPixmapItem
{
public:
  Car();
  virtual ~Car() = default;
public:
  virtual void initCar();
  void advance(int phase) override;
  void setSpeed(int speed);
protected:
  int m_speed;
  QPixmap m_pix;
};

#endif // CAR_H
