
#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"
#include "../field/header.hpp"
#include "../tetrimino/header.hpp"

class Display :public virtual Field{
    private:
        sf::Font font;
        sf::Text score_text;
        sf::Text gameover_text;

        void draw_grid();
    
    public:
        explicit Display(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris") {}

        sf::RenderWindow window;

        void display(Tetrimino mino);

        void draw_mino(Tetrimino mino);
        void gameover();
};

#endif