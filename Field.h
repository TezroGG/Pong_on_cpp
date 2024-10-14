#ifndef FIELD_H
#define FIELD_H

#include "Ball.h"
#include "Racket.h"
#include <iostream>

class Field {

 public:
  Field(Ball *new_ball, Racket *new_right_racket, Racket *new_left_racket);
  void Draw();
  void Update();
  bool WinCheck();
  char GetInput();

 private:
  Ball *ball;
  Racket *right_racket;
  Racket *left_racket;
  int right_score = 0, left_score = 0;
  const int high = 25, width = 80;

  int CheckGoal();
  void SetDefault();
  void CheckCollision();
};
;

#endif