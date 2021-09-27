#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "class.cc"

#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(800, 900), "SFML works!");
  window.setFramerateLimit(24);

  sf::RectangleShape rectangle(sf::Vector2f (150, 150));
  rectangle.setFillColor(sf::Color::Green);
  rectangle.setPosition(0, 0);
  sf::CircleShape circle(100.0f);
// GameInfo game;
// BallClass ball;
// BrickListClass *brick_list = NULL;
  sf::RectangleShape player_shape(sf::Vector2f(80,20));
  player_shape.setPosition(375,860);
  player_shape.setFillColor(sf::Color(0,0,255));
  
  PlatformClass player(player_shape,1,5);
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
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

