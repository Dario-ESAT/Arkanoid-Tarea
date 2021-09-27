#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "definitions.cc"
#include "brick.cc"
#include "platform.cc"
#include "ball.cc"

#include <SFML/Graphics.hpp>

class Game{
  int lives, score;

  void buildBricks(){

    sf::Vector2f position = sf::Vector2f(10,50);
    
    sf::RectangleShape brick_shape(sf::Vector2f(50,30));

    Brick building_brick(brick_shape,1);

    for (int i = 0; i < 5; i++) {
      for (int f = 0; f < 5; f++) {
        position.x += building_brick.getShape().getPosition().x * f + 5;
        building_brick.getShape().setPosition(position);
        
      }
      position.y += building_brick.getShape().getPosition().y * i + 5;
    }
    
  }
};

int main(){
  sf::RenderWindow window(sf::VideoMode(kScreenWith, kScreenHeight), "SFML works!");
  window.setFramerateLimit(30);
// GameInfo game;
// BallClass ball;
// BrickListClass *brick_list = NULL;
  sf::RectangleShape player_shape(sf::Vector2f(80,20));
  sf::RectangleShape ball_shape(sf::Vector2f(20,20));
  player_shape.setPosition(360,860);
  player_shape.setFillColor(sf::Color::Green);
  

  ball_shape.setPosition(380,840);
//  ball_shape.getFillColor(sf::Color::Red);
  
  PlatformClass player(player_shape,1,5);
  BallClass ball(2, 6.0f, ball_shape);
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window.close();
      }

      player.MovePlatform();
      window.clear();
      // ---- Draw ------------------------

      player.DrawPlatform(&window);

      // ----------------------------------
      window.display();
    }

  }

  return 0;
}

