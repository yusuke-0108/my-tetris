class Tetris{
private:
    int Field[ROW][COL];
    int FieldColor[ROW][COL];
    int MINO_Type_num;
    int get_MINO_cnt = 0;
    int score = 0;
    MINOINFO mino1;
    MINOINFO mino2;
public:
    Tetris();
    void determinate_MINO_Type(){
        MINO_Type_num = rand() % 7;
    }
    sf::RenderWindow window;
    sf::Font font;
    sf::Text scoreText;
    sf::Text GameOverText;

    void run();
    void next_step(int* color_index, int* cnt);
    void update_Field(int color_index);
    void erase_MINO();
    void Display();
    void get_MINO_Pos();
    bool isGameOver();
    void DisplayGameOver();

    bool isHit_left();
    bool isHit_right();
    bool isHit_bottom();

    void get_MINO();
    void create_MINO_I();
    void create_MINO_J();
    void create_MINO_T();
    void create_MINO_O();
    void create_MINO_L();
    void create_MINO_S();
    void create_MINO_Z();

    void move_MINO(sf::Event event);
    void rotate_MINO(int* cnt);
    void rotate_MINO_I(int* cnt);
    void rotate_MINO_J(int* cnt);
    void rotate_MINO_T(int* cnt);
    void rotate_MINO_O(int* cnt);
    void rotate_MINO_L(int* cnt);
    void rotate_MINO_S(int* cnt);
    void rotate_MINO_Z(int* cnt);
};