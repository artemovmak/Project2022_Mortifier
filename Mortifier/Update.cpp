#include "Engine.h"

void Engine::Update(float x, float y) {
  farmer.Update(x, y);
  for (int i = 0; i < field.GetHeight(); i ++) {
    for (int j = 0; j < field.GetWidth(); j++) {
      if (field.IsInHex(sf::Mouse::getPosition(game_window), field.GetTile(i, j))) {
        field.GetTile(i, j).setFillColor(sf::Color(150, 90, 100));
      } else {
        field.GetTile(i, j).setFillColor(sf::Color(128, 128, 128));
      }
    }
  }
}