
#ifndef COMMON_PARAMS
#define COMMON_PARAMS

const int ROW = 22;
const int COL = 12;
const int WINDOW_WIDTH = 360;
const int WINDOW_HEIGHT = 660;
const int BLOCK_SIZE = 30;
const int init_pos_x = (COL / 2 - 1)* BLOCK_SIZE;
const int init_pos_y = BLOCK_SIZE;

inline std::vector<sf::Color> ColorList = {
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

#endif