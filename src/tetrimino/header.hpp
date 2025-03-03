
#ifndef TETRIMINO_HEADER
#define TETRIMINO_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"

class Field;

// テトラミノの生成や移動を行うクラス
class Tetrimino{
    private:
        struct MINOINFO{
            sf::RectangleShape MINO;
            sf::Vector2f position;
            int x, y;
        };
    
    public:
        int mino_type_;
        explicit Tetrimino(int mino_type) : mino_type_(mino_type) {}

        MINOINFO mino1_;
        MINOINFO mino2_;
        
        void get_mino();
        void create_mino_I();
        void create_mino_J();
        void create_mino_T();
        void create_mino_O();
        void create_mino_L();
        void create_mino_S();
        void create_mino_Z();

        void move_mino(sf::Event event);
        void get_mino_pos();

        void rotate_mino(int* cnt);
        void rotate_mino_I(int* cnt);
        void rotate_mino_J(int* cnt);
        void rotate_mino_T(int* cnt);
        void rotate_mino_O(int* cnt);
        void rotate_mino_L(int* cnt);
        void rotate_mino_S(int* cnt);
        void rotate_mino_Z(int* cnt);
};

#endif