#ifndef RACKET_H
#define RACKET_H

class Racket {

 public:
  Racket(int new_x, int new_y);
  void Move(char c);
  int GetX();
  int GetY();

 private:
  int x, y;
};

#endif