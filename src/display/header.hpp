
#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"
#include "../field/header.hpp"

class Display :public virtual Field{
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Text score_text;
        sf::Text gameover_text;

        void draw_grid();
    
    public:
        explicit Display(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris") {}
        void display();
        void gameover();
};

#endif