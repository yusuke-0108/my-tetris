
#ifndef FIELD_HEADER
#define FIELD_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"

class Tetrimino;

class Field {
    private:
        void erase_mino(int* score);
    
    public:
        Field() {}
        void update(Tetrimino mino, int color_index, int* score);
        static int field[ROW][COL];
        static int field_color[ROW][COL];
};

#endif