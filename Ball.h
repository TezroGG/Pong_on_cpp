#ifndef BALL_H
#define BALL_H

class Ball {

 public:
  Ball(int new_x = 40, int new_y = 12);
  int GetX();
  int GetY();
  void SetX(int new_x);
  void SetY(int new_y);
  void SetAngle(int new_angle);
  int GetAngle();
  void Move();

 private:
  int x, y, angle = 45;
};

#endif