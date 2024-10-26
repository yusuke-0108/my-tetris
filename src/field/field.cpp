
#include "header.hpp"
#include "../tetrimino/header.hpp"

int Field::field[ROW][COL];
int Field::field_color[ROW][COL];

void Field::update(Tetrimino mino, int color_index){
    for(int i = 0; i < mino.mino1_.MINO.getSize().x / BLOCK_SIZE; ++i){
        field[mino.mino1_.y][mino.mino1_.x + i] = 1;
        field_color[mino.mino1_.y][mino.mino1_.x + i] = color_index;
    }
    for(int i = 0; i < mino.mino1_.MINO.getSize().y / BLOCK_SIZE; ++i){
        field[mino.mino1_.y + i][mino.mino1_.x] = 1;
        field_color[mino.mino1_.y + i][mino.mino1_.x] = color_index;
    }

    for(int i = 0; i < mino.mino2_.MINO.getSize().x / BLOCK_SIZE; ++i){
        field[mino.mino2_.y][mino.mino2_.x + i] = 1;
        field_color[mino.mino2_.y][mino.mino2_.x + i] = color_index;
    }
    for(int i = 0; i < mino.mino2_.MINO.getSize().y / BLOCK_SIZE; ++i){
        field[mino.mino2_.y + i][mino.mino2_.x] = 1;
        field_color[mino.mino2_.y + i][mino.mino2_.x] = color_index;
    }
}