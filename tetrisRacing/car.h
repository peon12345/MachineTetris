#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>

class Car : public QGraphicsPixmapItem
{
public:
  Car();
public:
  void advance(int phase) override;
protected:
  int m_speed;
  QPixmap m_pix;
};

#endif // CAR_H
