#include "ball.h"
#include "bat.h"
#include "common.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cmath>
#include <iostream>
#include <sstream>

int main() {
  VideoMode vm(WIDTH, HEIGHT);
  RenderWindow window(vm, "Pong", Style::Default);

  int score = 0;
  int lives = 3;
  Bat bat(WIDTH / 2.0f, HEIGHT - 20);
  Ball ball(WIDTH / 2.0f, 0);

  Text hud;

  Font font;
  font.loadFromFile("fonts/HomeVideo-BLG6G.ttf");
  hud.setFont(font);

  hud.setCharacterSize(50);
  hud.setFillColor(Color::White);

  hud.setPosition(20, 20);

  Clock clock;

  while (window.isOpen()) {
    /* HANDLE THE PLAYER INPUT */
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) {
        window.close();
      }
      if (event.type == Event::KeyPressed) {
        switch (event.key.code) {
        case Keyboard::Left:
          bat.moveLeft();
          break;
        case Keyboard::Right:
          bat.moveRight();
          break;
        default:
          break;
        }
      }
      if (event.type == Event::KeyReleased) {
        switch (event.key.code) {
        case Keyboard::Left:
          bat.stopLeft();
          break;
        case Keyboard::Right:
          bat.stopRight();
          break;
        default:
          break;
        }
      }
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
      window.close();
    }
    /* UPDATE THE BAT, THE BALL AND THE HUD */

    Time dt = clock.restart();
    bat.update(dt);
    ball.update(dt);
    std::stringstream ss;
    ss << "Score:" << score << " Lives:" << lives;
    hud.setString(ss.str());

    if (ball.getPosition().top > window.getSize().y) {
      ball.reboundBottom();
      lives -= 1;

      if (lives < 1) {
        score = 0;
        lives = 3;
      }
    };

    if (ball.getPosition().top < 0) {
      ball.reboundBatOrTop();
      score += 1;
    };

    if (ball.getPosition().left < 0 ||
        ball.getPosition().left + ball.getPosition().width >
            window.getSize().x) {
      ball.reboundSides();
    };

    if (ball.getPosition().intersects(bat.getPosition())) {
      ball.reboundBatOrTop();
    };

    /* DRAW THE BAT, THE BALL AND THE HUD */
    window.clear();
    window.draw(hud);
    window.draw(bat.getShape());
    window.draw(ball.getShape());
    window.display();
  }

  return 0;
}
