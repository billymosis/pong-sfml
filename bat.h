#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

using namespace sf;

class Bat {
private:
  Vector2f position;
  RectangleShape shape;
  float speed = 1000.0f;
  bool isMovingRight = false;
  bool isMovingLeft = false;

public:
  Bat(float startX, float startY);
  FloatRect getPosition();
  RectangleShape getShape();
  void moveLeft();
  void moveRight();
  void stopLeft();
  void stopRight();
  void update(Time dt);
};
