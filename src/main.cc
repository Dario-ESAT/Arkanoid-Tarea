#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "class.cc"

#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(800, 900), "SFML works!");
  window.setFramerateLimit(30);
// GameInfo game;
// BallClass ball;
// BrickListClass *brick_list = NULL;
  sf::RectangleShape player_shape(sf::Vector2f(80,20));
  player_shape.setPosition(375,860);
  player_shape.setFillColor(sf::Color::Green);
  
  PlatformClass player(player_shape,1,5);
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

