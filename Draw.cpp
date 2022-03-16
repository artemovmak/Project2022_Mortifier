#include "Engine.h"

void Engine::Draw() {
  game_window.clear(sf::Color::White);
  for (int i = 0; i < field.GetHeight(); i ++) {
    for (int j = 0; j < field.GetWidth(); j++) {
      game_window.draw(field.GetTile(i, j));
    }
  }
  game_window.draw(farmer.getSprite());
  game_window.display();
}

