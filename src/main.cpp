
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

int main(){
    Field field;

    init_field();

    Display dp;

    int mino_type = 1;
    int color_index = mino_type + 2;
    int rotate_cnt = 0;

    Tetrimino tetrimino(mino_type);
    tetrimino.get_mino();
    std::cout << "get mino OK." << std::endl;
    while(dp.window.isOpen()){
        dp.window.clear(sf::Color::White);

        sf::Event event;
        while(dp.window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    // 時計回りに回転
                    case sf::Keyboard::R:
                        tetrimino.rotate_mino(&rotate_cnt);
                        break;
                    
                    // テトリスの終了
                    case sf::Keyboard::Escape:
                        dp.window.close();
                        break;
                    
                    // ミノの上下左右での移動
                    default:
                        tetrimino.move_mino(event);
                        break;
                }
            }
        }

        tetrimino.mino1_.MINO.setPosition(tetrimino.mino1_.position);
        tetrimino.mino2_.MINO.setPosition(tetrimino.mino2_.position);
        tetrimino.get_mino_pos();  // テトリミノの位置を取得(Field::field上での座標)

        if(is_hit_bottom(&tetrimino)){
            field.update(tetrimino, color_index);

            tetrimino.mino_type_++;
            rotate_cnt = 0;

            if(tetrimino.mino_type_ >= 7) tetrimino.mino_type_ = 0;

            color_index = tetrimino.mino_type_ + 2;


            tetrimino.get_mino();
        }

        dp.display(tetrimino);
    }
}