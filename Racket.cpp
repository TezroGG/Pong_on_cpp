#include "Racket.h"

Racket::Racket(int new_x, int new_y) : x(new_x), y(new_y) {
}

int Racket::GetX() {
  return x;
}

int Racket::GetY() {
  return y;
}

void Racket::Move(char c) {
  if (c == 'a' || c == 'A' || c == 'k' || c == 'K') {
    if (y + 1 <= 25) {
      ++y;
    }
  } else if (c == 'z' || c == 'Z' || c == 'm' || c == 'M') {
    if (y - 1 >= 1) {
      --y;
    }
  }
}