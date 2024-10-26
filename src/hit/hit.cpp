

#include "header.hpp"

extern const int BLOCK_SIZE;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

bool is_hit_bottom(Tetrimino mino){
    int cnt = 0;
    for(int i = 0; i < mino.mino1_.MINO.getSize().x / BLOCK_SIZE; ++i){
        for(int j = 0; j < mino.mino1_.MINO.getSize().y / BLOCK_SIZE; ++j){
            if(Field::field[mino.mino1_.y + 1 + j][mino.mino1_.x + i] == 1) ++cnt;
        }
    }

    for(int i = 0; i < mino.mino2_.MINO.getSize().x / BLOCK_SIZE; ++i){
        for(int j = 0; j < mino.mino2_.MINO.getSize().y / BLOCK_SIZE; ++j){
            if(Field::field[mino.mino2_.y + 1 + j][mino.mino2_.x + i] == 1) ++cnt;
        }
    }
    return cnt > 0;
}

bool is_hit_left(Tetrimino mino){
    int cnt = 0;
    for(int i = 0; i < mino.mino1_.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field::field[mino.mino1_.y + i][mino.mino1_.x - 1] == 1) ++cnt;
    }

    for(int i = 0; i < mino.mino2_.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field::field[mino.mino2_.y + i][mino.mino2_.x - 1] == 1) ++cnt;
    }
    return cnt > 0;
}

bool is_hit_right(Tetrimino mino){
    int cnt = 0;
    int mino1_size_x = mino.mino1_.MINO.getSize().x / BLOCK_SIZE;
    int mino2_size_x = mino.mino2_.MINO.getSize().x / BLOCK_SIZE;

    for(int i = 0; i < mino.mino1_.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field::field[mino.mino1_.y + i][mino.mino1_.x + mino1_size_x] == 1) ++cnt;
    }

    for(int i = 0; i < mino.mino2_.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field::field[mino.mino2_.y + i][mino.mino2_.x + mino2_size_x] == 1) ++cnt;
    }
    return cnt > 0;
}