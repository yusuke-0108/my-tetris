
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

    Tetrimino tetrimino(mino_type);
    tetrimino.get_mino();
    std::cout << "get mino OK." << std::endl;
    while(dp.window.isOpen()){
        dp.window.clear(sf::Color::White);

        sf::Event event;
        while(dp.window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Escape:
                        dp.window.close();
                        break;
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

            tetrimino.get_mino();
        }

        dp.display(tetrimino);
    }
}