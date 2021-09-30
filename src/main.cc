#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "definitions.h"
#include "brick.h"
#include "platform.h"
#include "ball.h"
#include "game.h"

#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(kScreenWidth, kScreenHeight), "SFML works!");
  window.setFramerateLimit(30);

  Game game;
  game.buildBricks();
  game.initPLatform();
  game.initBall();

  while (window.isOpen()){

    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
      }
    }
    // ---- Input ------------

    game.player.MovePlatform();
    game.ball.MoveBall();

    // ---------------------------

    // ---- Update ---------------

    game.BallBricksCollision();
    game.PlatformBallCollision();
    game.ball.CheckBoundaries();
    game.CheckLoss();

    // ---------------------------

    window.clear();

    // ---- Draw ------------------------

    game.player.DrawPlatform(&window);
    game.brick_list.printBricksAlive(&window);
    game.ball.DrawBall(&window);
    
    // ----------------------------------

    window.display();

  }

  return 0;
}

