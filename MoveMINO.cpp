#include "Tetris.hpp"

extern const int BLOCK_SIZE;

void Tetris::move_MINO(sf::Event event){
        switch(event.key.code){
            case sf::Keyboard::Down:
                if(!isHit_bottom()){
                    mino1.position.y += BLOCK_SIZE;
                    mino2.position.y += BLOCK_SIZE;
                }
                break;
            case sf::Keyboard::Left:
                if(!isHit_left()){
                    mino1.position.x -= BLOCK_SIZE;
                    mino2.position.x -= BLOCK_SIZE;
                }
                break;
            case sf::Keyboard::Right:
                if(!isHit_right()){
                    mino1.position.x += BLOCK_SIZE;
                    mino2.position.x += BLOCK_SIZE;
                }
                break;
        }
}