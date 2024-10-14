#include "Field.h"
#include "Racket.h"
#include "Ball.h"

int main() {
  Ball ball;
  Racket right_racket(79, 12);
  Racket left_racket(0, 12);
  Field field(&ball, &right_racket, &left_racket);

  while (!field.WinCheck()) {
    field.Update();
    field.Draw();
  }

  return 0;
}