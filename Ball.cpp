#include "Ball.h"

Ball::Ball(int new_x, int new_y) : x(new_x), y(new_y) {
}

int Ball::GetX() {
  return x;
}

int Ball::GetY() {
  return y;
}

void Ball::SetX(int new_x) {
  x = new_x;
}

void Ball::SetY(int new_y) {
  y = new_y;
}

void Ball::SetAngle(int new_angle) {
  if (new_angle == 0) {
    ++new_angle;
  } else if (new_angle == 90) {
    ++new_angle;
  } else if (new_angle == 180) {
    ++new_angle;
  } else if (new_angle == 270) {
    ++new_angle;
  } else if (new_angle == 360) {
    --new_angle;
  }

  angle = new_angle;
}

int Ball::GetAngle() {
  return angle;
}

void Ball::Move() {
  if (0 < angle && angle < 90) {
    ++x;
    ++y;
  } else if (90 < angle && angle < 180) {
    --x;
    ++y;
  } else if (180 < angle && angle < 270) {
    --x;
    --y;
  } else if (270 < angle && angle < 360) {
    ++x;
    --y;
  }
}