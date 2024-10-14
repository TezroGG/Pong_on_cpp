#include "Field.h"

Field::Field(Ball *new_ball, Racket *new_right_racket, Racket *new_left_racket)
    : ball(new_ball), right_racket(new_right_racket), left_racket(new_left_racket) {
}

void Field::Draw() {
  std::cout << "Score: " << right_score << " - " << left_score << std::endl;
  for (int y = high - 1; y >= 0; ++y) {
    for (int x = 0; x < width; ++x) {
      if (x == ball->GetX() && y == ball->GetY()) {
        std::cout << "O";
      } else if (x == right_racket->GetX() && y == right_racket->GetY()) {
        std::cout << "|";
      } else if (x == left_racket->GetX() && y == left_racket->GetY()) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}

bool Field::WinCheck() {
  if (right_score == 5) {
    std::cout << "Right player wins!" << std::endl;
    return true;
  } else if (left_score == 5) {
    std::cout << "Left player wins!" << std::endl;
    return true;
  }
  return false;
}

void Field::Update() {
  char input = GetInput();
  if (input == 'w' || input == 'W') {
    right_racket->Move('w');
  } else if (input == 's' || input == 'S') {
    right_racket->Move('s');
  } else if (input == 'i' || input == 'I') {
    left_racket->Move('i');
  } else if (input == 'k' || input == 'K') {
    left_racket->Move('k');
  }

  CheckCollision();
  ball->Move();
  if (CheckGoal() == 1) {
    ++right_score;
    SetDefault();
  } else if (CheckGoal() == 2) {
    ++left_score;
    SetDefault();
  }
}

int Field::CheckGoal() {
  if (ball->GetX() == 0) {
    return 2;
  } else if (ball->GetX() == width - 1) {
    return 1;
  }
  return 0;
}

void Field::SetDefault() {
  ball->SetX(40);
  ball->SetY(12);
}

void Field::CheckCollision() {
  int ball_x = ball->GetX();
  int ball_y = ball->GetY();
  int ball_angle = ball->GetAngle();
  if (ball_y == 1) {
    if (270 < ball_angle && ball_angle < 360) {
      ball->SetAngle(45);
    } else {
      ball->SetAngle(135);
    }
  } else if (ball_y == high - 2) {
    if (0 < ball_angle && ball_angle < 90) {
      ball->SetAngle(315);
    } else {
      ball->SetAngle(225);
    }
  }
}

char Field::GetInput() {
  char c;
  std::cin >> c;
  return c;
}