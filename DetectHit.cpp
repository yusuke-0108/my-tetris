#include "Tetris.hpp"

extern const int BLOCK_SIZE;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

bool Tetris::isHit_bottom(){
    int cnt = 0;
    for(int i = 0; i < mino1.MINO.getSize().x / BLOCK_SIZE; ++i){
        for(int j = 0; j < mino1.MINO.getSize().y / BLOCK_SIZE; ++j){
            if(Field[mino1.y + 1 + j][mino1.x + i] == 1) ++cnt;
        }
    }

    for(int i = 0; i < mino2.MINO.getSize().x / BLOCK_SIZE; ++i){
        for(int j = 0; j < mino2.MINO.getSize().y / BLOCK_SIZE; ++j){
            if(Field[mino2.y + 1 + j][mino2.x + i] == 1) ++cnt;
        }
    }
    return cnt > 0;
}

bool Tetris::isHit_left(){
    int cnt = 0;
    for(int i = 0; i < mino1.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field[mino1.y + i][mino1.x - 1] == 1) ++cnt;
    }

    for(int i = 0; i < mino2.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field[mino2.y + i][mino2.x - 1] == 1) ++cnt;
    }
    return cnt > 0;
}

bool Tetris::isHit_right(){
    int cnt = 0;
    int mino1_size_x = mino1.MINO.getSize().x / BLOCK_SIZE;
    int mino2_size_x = mino2.MINO.getSize().x / BLOCK_SIZE;

    for(int i = 0; i < mino1.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field[mino1.y + i][mino1.x + mino1_size_x] == 1) ++cnt;
    }

    for(int i = 0; i < mino2.MINO.getSize().y / BLOCK_SIZE; ++i){
        if(Field[mino2.y + i][mino2.x + mino2_size_x] == 1) ++cnt;
    }
    return cnt > 0;
}
