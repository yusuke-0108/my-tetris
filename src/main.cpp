
#include "field/header.hpp"
#include "tetrimino/header.hpp"
#include "display/header.hpp"
#include "hit/header.hpp"
#include <random>

extern const int BLOCK_SIZE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

bool gameover();
void display_game_end(int score);
void read_font();

sf::Font font;
sf::Text scoreText;
sf::Text GameOverText;

int main(){
    read_font();
    Field field;
    init_field();

    Display dp;
    std::random_device rnd;
    std::mt19937 mt(rnd());     
    std::uniform_int_distribution<> rand(0, 100000);  
    
    int mino_type = rand(mt) % 7;  
    int color_index = mino_type + 2;
    int rotate_cnt = 0;
    int score = 0;

    // 最初のテトラミノを生成
    Tetrimino tetrimino(mino_type);
    tetrimino.get_mino();

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

        // ミノの表示位置を更新
        tetrimino.mino1_.MINO.setPosition(tetrimino.mino1_.position);
        tetrimino.mino2_.MINO.setPosition(tetrimino.mino2_.position);
        tetrimino.get_mino_pos();  // テトリミノの位置を取得(Field::field上での座標)

        if(is_hit_bottom(&tetrimino)){
            field.update(tetrimino, color_index, &score);

            if(gameover()){
                std::cout << "game over" << std::endl;
                dp.window.close();
            }

            tetrimino.mino_type_ = rand(mt) % 7;
            rotate_cnt = 0;

            if(tetrimino.mino_type_ >= 7) tetrimino.mino_type_ = 0;

            color_index = tetrimino.mino_type_ + 2;

            tetrimino.get_mino();
        }

        dp.display(tetrimino);
    }

    display_game_end(score);
}

bool gameover(){
    int count = 0;

    // 一番上のセルが1であればゲームオーバー
    for(int i = 1; i < COL - 1; ++i){
        if(Field::field[1][i] == 1) ++count;
    }
    return count > 0;
}

void display_game_end(int score){
    Display dp;

    while(dp.window.isOpen()){
        dp.window.clear(sf::Color::White);
        sf::Event event;
        while(dp.window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){

                    // テトリスの終了
                    case sf::Keyboard::Escape:
                        dp.window.close();
                        break;
                }
            }
        }

        dp.display_end();

        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(WINDOW_WIDTH / 2 - 50 , WINDOW_HEIGHT / 2 + 30);
        scoreText.setString("Final Score:" + std::to_string(score));
        dp.window.draw(scoreText);

        GameOverText.setFont(font);
        GameOverText.setFillColor(sf::Color::Black);
        GameOverText.setPosition(WINDOW_WIDTH / 2 - 50 , WINDOW_HEIGHT / 2);
        GameOverText.setString("Game End!");
        dp.window.draw(GameOverText);

        dp.window.display();
    }

    std::cout << "Your final score is " << score << "." << std::endl;
}

void read_font(){
    //フォントの読み込み
    if (font.loadFromFile("asset/ARIAL.TTF")) {
        std::cerr << "Successed to load font!" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(30, 0);
}