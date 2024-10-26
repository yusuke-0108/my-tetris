
#include "header.hpp"


void Display::display(Tetrimino mino){
    set_mino(mino);
    draw_grid();
    window.display();
}

void Display::draw_grid(){
    sf::Color grid_color = sf::Color::Black;

    for(int i = 0; i < WINDOW_WIDTH; i +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i, BLOCK_SIZE), grid_color),
            sf::Vertex(sf::Vector2f(i, WINDOW_HEIGHT - BLOCK_SIZE), grid_color)
        };
        window.draw(line, 4, sf::Lines);
    }

    for(int j = 0; j < WINDOW_HEIGHT; j +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(BLOCK_SIZE, j), grid_color),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH - BLOCK_SIZE, j), grid_color)
        };
        window.draw(line, 4, sf::Lines);
    }
}

void Display::set_mino(Tetrimino mino){
    window.draw(mino.mino1_.MINO);
    window.draw(mino.mino2_.MINO);
}