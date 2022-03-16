#include "Engine.h"

Engine::Engine() {
  sf::Vector2f resolution;
  resolution.x = sf::VideoMode::getDesktopMode().width;
  resolution.y = sf::VideoMode::getDesktopMode().height;
  game_window.create(sf::VideoMode(resolution.x, resolution.y),
                  "Simple Game Engine",
                  sf::Style::Fullscreen);
  game_background_texture.loadFromFile("../Background.jpg");
  game_background_sprite.setTexture(game_background_texture);
  music.openFromFile("../Boy.ogg");
}

void Engine::Start() {
  Music();
  while (game_window.isOpen()) {
    Input();
    Update(static_cast<float>(sf::Mouse::getPosition(game_window).x - 40), static_cast<float>(sf::Mouse::getPosition(game_window).y - 60));
    Draw();
  }
}