#include "Tetris.hpp"
#include <iostream>
#include <chrono>
#include <thread>

extern const int BLOCK_SIZE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int ROW;
extern const int COL;
extern const int init_pos_x;
extern const int init_pos_y;

std::vector<sf::Color> ColorList = {
    sf::Color::White,          //ウィンドウ
    sf::Color(169, 169, 169),  //壁
    sf::Color::Cyan,           //I型
    sf::Color::Yellow,         //O型
    sf::Color::Magenta,        //T型
    sf::Color::Blue,           //J型
    sf::Color(255, 165, 0),    //L型
    sf::Color::Green,          //S型
    sf::Color::Red             //Z型
};

Tetris::Tetris()
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris"){
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            if((j == 0 || j == COL - 1 || i == ROW - 1) && (i != 0)){
                Field[i][j] = 1;
                FieldColor[i][j] = 1;  //Black
            }else{
                Field[i][j] = 0;
                FieldColor[i][j] = 0; //White
            }
        }
    }
}

void Tetris::run(){
    auto start_time = std::chrono::steady_clock::now();
    int cnt = 0;
    determinate_MINO_Type(); //first MINO;
    get_MINO();
    int color_index = MINO_Type_num + 2;
    while(window.isOpen()){

        //1秒ごとに自動で落下
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time);
        if(duration.count() % 1000 >= 0 && duration.count() % 1000 <= 10){
            std::cout << duration.count() << std::endl;
            mino1.position.y += BLOCK_SIZE;
            mino2.position.y += BLOCK_SIZE;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        sf::Event event;
        get_MINO_Pos();
        if(isHit_bottom()) next_step(&color_index, &cnt);
        while(window.pollEvent(event)){
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::J:
                        rotate_MINO(&cnt);
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        move_MINO(event);
                        break;
                }
            }
        }
        Display();
        if(isGameOver()){
            break;
        }
    }
    DisplayGameOver();
}


void Tetris::Display(){
    window.clear(sf::Color::White);

    //ひとつ前の状態
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            if(Field[i][j] == 1){
                sf::RectangleShape cell(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                cell.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE);
                sf::Color Color = ColorList[FieldColor[i][j]];
                if(i == ROW - 1 || j == 0 || j == COL - 1){
                    cell.setFillColor(Color);
                }else{
                    cell.setFillColor(Color);
                }
                window.draw(cell);
            }
        }
    }

    mino1.MINO.setPosition(mino1.position);
    mino2.MINO.setPosition(mino2.position);

    window.draw(mino1.MINO);
    window.draw(mino2.MINO);

    drawGrid(window);

    scoreText.setString("Score: " + std::to_string(score));  //GemaOverでなかったら、左上にスコアを表示
    window.draw(scoreText);
    window.display();
}

void Tetris::DisplayGameOver(){
    while(window.isOpen()){
        window.clear(sf::Color::White);
        sf::Event event;
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                if(Field[i][j] == 1){
                    sf::RectangleShape cell(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                    cell.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE + 3 * BLOCK_SIZE);
                    sf::Color Color = ColorList[FieldColor[i][j]];
                    if(i == ROW - 1 || j == 0 || j == COL - 1){
                        cell.setFillColor(Color);
                    }else{
                        cell.setFillColor(Color);
                    }
                    window.draw(cell);
                }
            }
        }

        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setPosition(WINDOW_WIDTH / 2 - 50 , WINDOW_HEIGHT / 2 + 30);
        scoreText.setString("Final Score:" + std::to_string(score));
        window.draw(scoreText);

        GameOverText.setFont(font);
        GameOverText.setFillColor(sf::Color::Black);
        GameOverText.setPosition(WINDOW_WIDTH / 2 - 50 , WINDOW_HEIGHT / 2);
        GameOverText.setString("GameOver!");
        window.draw(GameOverText);

        drawGrid(window);
        window.display();
        while(window.pollEvent(event)){
                if(event.key.code == sf::Keyboard::Escape) window.close();
        }
    }
}

void Tetris::get_MINO_Pos(){
    mino1.x = mino1.position.x / BLOCK_SIZE;
    mino1.y = mino1.position.y / BLOCK_SIZE;

    mino2.x = mino2.position.x / BLOCK_SIZE;
    mino2.y = mino2.position.y / BLOCK_SIZE;
}

void Tetris::update_Field(int color_index){
    for(int i = 0; i < mino1.MINO.getSize().x / BLOCK_SIZE; ++i){
        Field[mino1.y][mino1.x + i] = 1;
        FieldColor[mino1.y][mino1.x + i] = color_index;
    }
    for(int i = 0; i < mino1.MINO.getSize().y / BLOCK_SIZE; ++i){
        Field[mino1.y + i][mino1.x] = 1;
        FieldColor[mino1.y + i][mino1.x] = color_index;
    }

    for(int i = 0; i < mino2.MINO.getSize().x / BLOCK_SIZE; ++i){
        Field[mino2.y][mino2.x + i] = 1;
        FieldColor[mino2.y][mino2.x + i] = color_index;
    }
    for(int i = 0; i < mino2.MINO.getSize().y / BLOCK_SIZE; ++i){
        Field[mino2.y + i][mino2.x] = 1;
        FieldColor[mino2.y + i][mino2.x] = color_index;
    }
}

void Tetris::next_step(int* color_index, int* cnt){
    update_Field(*color_index);
    erase_MINO();

    ++MINO_Type_num;
    ++get_MINO_cnt;

    if(MINO_Type_num > 6){
        MINO_Type_num = 0;
    }
    if(get_MINO_cnt > 6){  //テトラミノが1順
        determinate_MINO_Type();
        get_MINO_cnt = 0;
    }
    get_MINO();
    *color_index = MINO_Type_num + 2;
    get_MINO_Pos();
    *cnt = 0;   //回転回数を０で初期化
}

void Tetris::erase_MINO(){
    int count = 0;
    for(int i = ROW - 2; i > 0; --i){
        for(int j = 1; j < COL - 1; ++j){
            if(Field[i][j] == 1) ++count;
        }
        if(count == COL - 2){
            for(int k = i; k > 0; --k){
                for(int j = 1; j < COL - 1; ++j){
                    Field[k][j] = Field[k - 1][j]; //erase MINO
                    FieldColor[k][j] = FieldColor[k - 1][j];
                }
            }
            score += 100;
            ++i;
        }
        count = 0;

    }
}

bool Tetris::isGameOver(){
    int count = 0;
    for(int i = 1; i < COL - 1; ++i){
        if(Field[1][i] == 1) ++count;
    }
    return count > 0;
}

void set_text_font(sf::Font& font, sf::Text& scoreText){
    //フォントの読み込み
    if (font.loadFromFile("/home/yusuke0108/arial.ttf")) {
        std::cerr << "Successed to load font!" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(30, 0);
}

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    Tetris Tetris;
    set_text_font(Tetris.font, Tetris.scoreText);

    Tetris.run();

    return 0;
}