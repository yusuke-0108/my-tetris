#include "Tetris.hpp"

extern const int BLOCK_SIZE;

void Tetris::rotate_MINO(int* cnt){
    sf::Vector2f orgPosMINO1 = mino1.position;
    sf::Vector2f orgSizeMINO1 = mino1.MINO.getSize();

    sf::Vector2f orgPosMINO2 = mino2.position;
    sf::Vector2f orgSizeMINO2 = mino2.MINO.getSize();

    mino1.MINO.setSize(sf::Vector2f(orgSizeMINO1.y, orgSizeMINO1.x));
    mino2.MINO.setSize(sf::Vector2f(orgSizeMINO2.y, orgSizeMINO2.x));

    switch(MINO_Type_num){
        case 0:
            rotate_MINO_I(cnt);
            break;
        case 1:
            rotate_MINO_O(cnt);
            break;
        case 2:
            rotate_MINO_T(cnt);
            break;
        case 3:
            rotate_MINO_J(cnt);
            break;
        case 4:
            rotate_MINO_L(cnt);
            break;
        case 5:
            rotate_MINO_S(cnt);
            break;
        case 6:
            rotate_MINO_Z(cnt);
            break;
    }
}

void Tetris::rotate_MINO_T(int* cnt){
    switch(*cnt){
        case 0:
            ++(*cnt);
            break;
        case 1:
            mino1.position.y += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 2:
            mino1.position.x += BLOCK_SIZE * 2;
            mino1.position.y -= BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 3:
            mino1.position.x -= BLOCK_SIZE * 2;
            *cnt = 0;
            break;
    }
}

void Tetris::rotate_MINO_J(int* cnt){
    switch(*cnt){
        case 0:
            mino2.position.x += BLOCK_SIZE;
            mino2.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 1:
            mino2.position.x += BLOCK_SIZE;
            mino2.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 2:
            mino2.position.x -= BLOCK_SIZE * 3;
            mino2.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 3:
            mino2.position.x += BLOCK_SIZE;
            mino2.position.y -= BLOCK_SIZE * 3;
            *cnt = 0;
            break;
    }
}

void Tetris::rotate_MINO_I(int* cnt){
    switch(*cnt){
        case 0:
            mino2.position.x = mino1.position.x;
            mino2.position.y = mino2.position.y + 2 * BLOCK_SIZE;
            ++(*cnt);
            break;
        case 1:
            mino2.position.x = mino1.position.x + 2 * BLOCK_SIZE;
            mino2.position.y = mino1.position.y;
            *cnt = 0;
            break;
    }
}

void Tetris::rotate_MINO_L(int* cnt){
    switch(*cnt){
        case 0:
            mino2.position.x -= BLOCK_SIZE;
            mino2.position.y += BLOCK_SIZE * 3;
            ++(*cnt);
            break;
        case 1:
            mino2.position.x -= BLOCK_SIZE;
            mino2.position.y -= BLOCK_SIZE;
            ++(*cnt);
            break;
        case 2:
            mino2.position.x -= BLOCK_SIZE;
            mino2.position.y -= BLOCK_SIZE;
            ++(*cnt);
            break;
        case 3:
            mino2.position.x += BLOCK_SIZE * 3;
            mino2.position.y -= BLOCK_SIZE;
            *cnt = 0;
            break;
    }
}

void Tetris::rotate_MINO_S(int* cnt){

}

void Tetris::rotate_MINO_Z(int* cnt){

}

void Tetris::rotate_MINO_O(int* cnt){

}