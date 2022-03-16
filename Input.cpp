#include "Engine.h"

void Engine::Input() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    game_window.close();
  }

  if ((farmer.getSprite().getGlobalBounds().contains
  (game_window.mapPixelToCoords(sf::Mouse::getPosition(game_window))))
  && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    farmer.Capture();
  } else {
    farmer.Stop();
  }
}
