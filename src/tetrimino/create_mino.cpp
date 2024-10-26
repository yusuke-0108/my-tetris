
#include "header.hpp"

void Tetrimino::create_mino_I(){
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Cyan);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Cyan);

    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y;

    mino2_.position.x = init_pos_x + 2 * BLOCK_SIZE;
    mino2_.position.y = init_pos_y;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_J(){
    //shape
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Blue);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Blue);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y + BLOCK_SIZE;

    mino2_.position.x = mino1_.position.x;
    mino2_.position.y = mino1_.position.y - BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_T(){
    //shape
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Magenta);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Magenta);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y + BLOCK_SIZE;

    mino2_.position.x = mino1_.position.x + BLOCK_SIZE;
    mino2_.position.y = mino1_.position.y - BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_O(){
    //shape
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Yellow);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Yellow);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y;

    mino2_.position.x = mino1_.position.x;
    mino2_.position.y = mino1_.position.y + BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_L(){
    sf::Color Orange = sf::Color(255, 165, 0);
    //shape
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*3, BLOCK_SIZE));
    mino1_.MINO.setFillColor(Orange);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    mino2_.MINO.setFillColor(Orange);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y + BLOCK_SIZE;

    mino2_.position.x = mino1_.position.x + 2 * BLOCK_SIZE;
    mino2_.position.y = mino1_.position.y - BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_S(){
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Green);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Green);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y + BLOCK_SIZE;

    mino2_.position.x = mino1_.position.x +  BLOCK_SIZE;
    mino2_.position.y = mino1_.position.y - BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}

void Tetrimino::create_mino_Z(){
    mino1_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino1_.MINO.setFillColor(sf::Color::Red);

    mino2_.MINO.setSize(sf::Vector2f(BLOCK_SIZE*2, BLOCK_SIZE));
    mino2_.MINO.setFillColor(sf::Color::Red);

    //position
    mino1_.position.x = init_pos_x;
    mino1_.position.y = init_pos_y;

    mino2_.position.x = mino1_.position.x +  BLOCK_SIZE;
    mino2_.position.y = mino1_.position.y + BLOCK_SIZE;

    mino1_.MINO.setPosition(mino1_.position);
    mino2_.MINO.setPosition(mino2_.position);
}