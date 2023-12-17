#include "Tetris.hpp"

extern const int BLOCK_SIZE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int ROW;
extern const int COL;

void drawGrid(sf::RenderWindow& window){
    sf::Color gridColor = sf::Color::Black;
    for(int i = 0; i < WINDOW_WIDTH; i +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i, BLOCK_SIZE), gridColor),
            sf::Vertex(sf::Vector2f(i, WINDOW_HEIGHT - BLOCK_SIZE), gridColor)
        };
        window.draw(line, 4, sf::Lines);
    }

    for(int j = 0; j < WINDOW_HEIGHT; j +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(BLOCK_SIZE, j), gridColor),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH - BLOCK_SIZE, j), gridColor)
        };
        window.draw(line, 4, sf::Lines);
    }
}