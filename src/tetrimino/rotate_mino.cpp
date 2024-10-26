
#include "header.hpp"

void Tetrimino::rotate_mino_T(int* cnt){
    switch(*cnt){
        case 0:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.x += BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 1:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.x -= BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 2:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.x -= BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE;
            ++(*cnt);
            break;
        case 3:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.x += BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE;
            *cnt = 0;
            break;
    }
}

void Tetrimino::rotate_mino_J(int* cnt){
    switch(*cnt){
        case 0:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.x += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 1:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 2:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.x -= BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 3:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE * 2;
            *cnt = 0;
            break;
    }
}

void Tetrimino::rotate_mino_I(int* cnt){
    switch(*cnt){
        case 0:
            mino2_.position.x = mino1_.position.x;
            mino2_.position.y = mino2_.position.y + 2 * BLOCK_SIZE;
            ++(*cnt);
            break;
        case 1:
            mino2_.position.x = mino1_.position.x + 2 * BLOCK_SIZE;
            mino2_.position.y = mino1_.position.y;
            *cnt = 0;
            break;
    }
}

void Tetrimino::rotate_mino_L(int* cnt){
    switch(*cnt){
        case 0:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 1:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.x -= BLOCK_SIZE *2;
            ++(*cnt);
            break;
        case 2:
            mino1_.position.x += BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 3:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.x += BLOCK_SIZE * 2;
            *cnt = 0;
            break;
    }
}

void Tetrimino::rotate_mino_S(int* cnt){
    switch(*cnt){
        case 0:
            mino1_.position.x += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 1:
            mino1_.position.x -= BLOCK_SIZE * 2;
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE;
            ++(*cnt);
            break;
        case 2:
            mino1_.position.y -= BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 3:
            mino1_.position.y += BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE;
            *cnt = 0;
            break;
    }

}

void Tetrimino::rotate_mino_Z(int* cnt){
    switch(*cnt){
        case 0:
            mino1_.position.x += BLOCK_SIZE * 2;
            ++(*cnt);
            break;
        case 1:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y += BLOCK_SIZE * 2;
            mino2_.position.x -= BLOCK_SIZE;
            ++(*cnt);
            break;
        case 2:
            mino1_.position.x -= BLOCK_SIZE;
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.x += BLOCK_SIZE;
            mino2_.position.y -= BLOCK_SIZE;
            ++(*cnt);
            break;
        case 3:
            mino1_.position.y -= BLOCK_SIZE;
            mino2_.position.y += BLOCK_SIZE;
            *cnt = 0;
            break;
    }
}

void Tetrimino::rotate_mino_O(int* cnt){

}