#pragma once
#include "common.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Ball {
private:
  Vector2f position;
  RectangleShape shape;

  float speed = BALL_SPEED;
  float directionX = .5f;
  float directionY = .2f;

public:
  Ball(float startX, float startY);
  FloatRect getPosition();
  RectangleShape getShape();
  float getXVelocity();
  void reboundSides();
  void reboundBatOrTop();
  void reboundBottom();
  void update(Time dt);
};
