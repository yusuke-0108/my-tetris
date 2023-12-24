#include "Tetris.hpp"

extern const int BLOCK_SIZE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

void Tetris::get_MINO(){
    switch(MINO_Type_num){
        case 0:
            create_MINO_I();
            break;
        case 1:
            create_MINO_O();
            break;
        case 2:
            create_MINO_T();
            break;
        case 3:
            create_MINO_J();
            break;
        case 4:
            create_MINO_L();
            break;
        case 5:
            create_MINO_S();
            break;
        case 6:
            create_MINO_Z();
            break;
    }
}

void Tetris::create_MINO_I(){
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Cyan);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Cyan);

    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y;

    mino2.position.x = init_pos_x + 2 * BLOCK_SIZE;
    mino2.position.y = init_pos_y;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_J(){
    //shape
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Blue);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Blue);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y + BLOCK_SIZE;

    mino2.position.x = mino1.position.x;
    mino2.position.y = mino1.position.y - BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_T(){
    //shape
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Magenta);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Magenta);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y + BLOCK_SIZE;

    mino2.position.x = mino1.position.x + BLOCK_SIZE;
    mino2.position.y = mino1.position.y - BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_O(){
    //shape
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Yellow);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Yellow);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y;

    mino2.position.x = mino1.position.x;
    mino2.position.y = mino1.position.y + BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_L(){
    sf::Color Orange = sf::Color(255, 165, 0);
    //shape
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1.MINO.setFillColor(Orange);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2.MINO.setFillColor(Orange);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y + BLOCK_SIZE;

    mino2.position.x = mino1.position.x + 2 * BLOCK_SIZE;
    mino2.position.y = mino1.position.y - BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_S(){
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Green);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Green);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y + BLOCK_SIZE;

    mino2.position.x = mino1.position.x +  BLOCK_SIZE;
    mino2.position.y = mino1.position.y - BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}

void Tetris::create_MINO_Z(){
    mino1.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1.MINO.setFillColor(sf::Color::Red);

    mino2.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2.MINO.setFillColor(sf::Color::Red);

    //position
    mino1.position.x = init_pos_x;
    mino1.position.y = init_pos_y;

    mino2.position.x = mino1.position.x +  BLOCK_SIZE;
    mino2.position.y = mino1.position.y + BLOCK_SIZE;

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);
}
