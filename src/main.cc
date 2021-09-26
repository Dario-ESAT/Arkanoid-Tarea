#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include "class.cc"
#include "player.cc"

#include <SFML/Graphics.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(800, 1000), "SFML works!");
  InitPlatform();
/*  
  sf::RectangleShape rectangle(sf::Vector2f (150, 150));
  rectangle.setFillColor(sf::Color::Green);
//  rectangle.setPosition(0, 0);
*/
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }

      MovePlatform();
      window.clear();

      DrawPlatform();
//      window.draw(rectangle);
      window.display();
    }
  }
  return 0;
}

