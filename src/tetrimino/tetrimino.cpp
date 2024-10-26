
#include "header.hpp"

void Tetrimino::get_mino(){
    switch(mino_type_){
        case 0:
            create_mino_I();
            break;
        case 1:
            create_mino_O();
            break;
        case 2:
            create_mino_T();
            break;
        case 3:
            create_mino_J();
            break;
        case 4:
            create_mino_L();
            break;
        case 5:
            create_mino_S();
            break;
        case 6:
            create_mino_Z();
            break;
    }
}

void Tetrimino::rotate_mino(int* cnt){
    sf::Vector2f org_size_mino1 = mino1_.MINO.getSize();
    sf::Vector2f org_size_mino2 = mino2_.MINO.getSize();

    // 反転させる
    mino1_.MINO.setSize(sf::Vector2f(org_size_mino1.y, org_size_mino1.x));
    mino2_.MINO.setSize(sf::Vector2f(org_size_mino2.y, org_size_mino2.x));

    // 反転後の位置を微調整し、回転を実現
    switch(mino_type_){
        case 0:
            rotate_mino_I(cnt);
            break;
        case 1:
            rotate_mino_O(cnt);
            break;
        case 2:
            rotate_mino_T(cnt);
            break;
        case 3:
            rotate_mino_J(cnt);  //OK
            break;
        case 4:
            rotate_mino_L(cnt);  //OK
            break;
        case 5:
            rotate_mino_S(cnt);  //OK
            break;
        case 6:
            rotate_mino_Z(cnt);  //OK
            break;
    }
}