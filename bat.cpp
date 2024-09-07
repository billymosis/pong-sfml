#include "bat.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Bat::Bat(float startX, float startY) {
  this->position.x = startX;
  this->position.y = startY;
  this->shape.setSize(sf::Vector2f(50, 5));
  this->shape.setPosition(this->position);
}

FloatRect Bat::getPosition() { return this->shape.getGlobalBounds(); }

RectangleShape Bat::getShape() { return this->shape; }

void Bat::moveLeft() { this->isMovingLeft = true; }

void Bat::moveRight() { this->isMovingRight = true; }

void Bat::stopLeft() { this->isMovingLeft = false; }

void Bat::stopRight() { this->isMovingRight = false; }

void Bat::update(Time dt) {
  if (this->isMovingLeft) {
    this->position.x -= this->speed * dt.asSeconds();
  }
  if (this->isMovingRight) {
    this->position.x += this->speed * dt.asSeconds();
  }
  this->shape.setPosition(this->position);
}
