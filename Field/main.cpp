#include <SFML/Graphics.hpp>

class Field {
private:
  int height = 100;
  int width = 100;
  sf::CircleShape field[100][100];
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
        field[i][j].setPosition((j % 2 == 1 ? 75 : 50) + i * 50.f, 50 + j * 40.f);
        field[i][j].setFillColor(sf::Color(128, 128, 128));
      }
    }
  }
  /*void KeyChangeColor() {
    static int i = 1;
    static int j = 1;
    field[0+i][0+j].setFillColor(sf::Color::Blue);
    i++;
    j++;
  }*/
  sf::CircleShape PrintField(int i, int j) {
    return field[i][j];
  }
  int GetHeight() const {
    return height;
  }
  int GetWidth() const {
    return width;
  }
};
int main() {
  sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    Field game(30, 20);
    window.clear();
    for (int i = 0; i < game.GetHeight(); i ++) {
      for (int j = 0; j < game.GetWidth(); j++) {
        window.draw(game.PrintField(i, j));
      }
    }
    window.display();
  }
}
