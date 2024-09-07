#include "ball.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

Ball::Ball(float startX, float startY) {
  this->position.x = startX;
  this->position.y = startY;

  this->shape.setSize(sf::Vector2f(10, 10));
  this->shape.setPosition(this->position);
}

FloatRect Ball::getPosition() { return this->shape.getGlobalBounds(); }

RectangleShape Ball::getShape() { return this->shape; }
float Ball::getXVelocity() { return this->directionX; }

void Ball::reboundSides() { this->directionX = -this->directionX; }
void Ball::reboundBatOrTop() { this->directionY = -this->directionY; }
void Ball::reboundBottom() {
  this->position.y = 0;
  this->position.x = 500;
  this->directionY = -this->directionY;
};

void Ball::update(Time dt) {
  this->position.y += this->directionY * this->speed * dt.asSeconds();
  this->position.x += this->directionX * this->speed * dt.asSeconds();

  this->shape.setPosition(this->position);
}
