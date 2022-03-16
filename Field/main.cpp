#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Field {
private:
  int height = 37;
  int width = 23;
  sf::CircleShape field[38][24];
public:
  Field(int h, int w) {
    height = h;
    width = w;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        field[i][j] = sf::CircleShape(25, 6);
        field[i][j].setOutlineColor(sf::Color::Black);
        field[i][j].setOutlineThickness(5);
        field[i][j].setOrigin(25, 25);
        field[i][j].setPosition(static_cast<float>(j % 2 == 1 ? 75 : 50) + static_cast<float>(i)  * 50.f, 50 + static_cast<float>(j) * 40.f);
        field[i][j].setFillColor(sf::Color(128, 128, 128));
      }
    }
  }
  sf::CircleShape& GetTile(int i, int j) {
    return field[i][j];
  }
  int GetHeight() const {
    return height;
  }
  int GetWidth() const {
    return width;
  }
  static sf::Vector2i GetMousePosition(const sf::RenderWindow &window) {
    return sf::Mouse::getPosition(window);
  }
  bool IsInHex(sf::Vector2i point, sf::CircleShape hex) {
    sf::Vector2f pointf = {float(point.x), float(point.y)};
    sf::Vector2f point_v = pointf - hex.getPosition();
    if (point_v.x * point_v.x + point_v.y * point_v.y < hex.getRadius() * hex.getRadius()) {
      return true;
    }
    return false;
  }
};
int main() {
  sf::Music music;
  music.openFromFile("../Boy.ogg");
  music.play();
  music.setLoop(true);
  sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    Field game(25, 20);
    window.clear();

    for (int i = 0; i < game.GetHeight(); i ++) {
      for (int j = 0; j < game.GetWidth(); j++) {
        if (game.IsInHex(sf::Mouse::getPosition(window), game.GetTile(i, j))) {
          game.GetTile(i, j).setFillColor(sf::Color(150, 90, 100));
        }
        window.draw(game.GetTile(i, j));
      }
    }
    window.display();
  }
}
