
#include "field/header.hpp"
#include "tetrimino/header.hpp"
#include "display/header.hpp"
#include "hit/header.hpp"

extern const int BLOCK_SIZE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

void init_field(){
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            if((j == 0 || j == COL - 1 || i == ROW - 1) && (i != 0)){
                Field::field[i][j] = 1;
                Field::field_color[i][j] = 1;  //Black
            }else{
                Field::field[i][j] = 0;
                Field::field_color[i][j] = 0; //White
            }
        }
    }
}

int main(){
    Field field;

    init_field();

    Display dp;
    Tetrimino tetrimino(1);
    tetrimino.get_mino();

    while(dp.window.isOpen()){
        dp.window.clear(sf::Color::White);
        
        dp.display(tetrimino);
    }
}