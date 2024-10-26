
#ifndef HIT_HEADER
#define HIT_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"
#include "../field/header.hpp"
#include "../tetrimino/header.hpp"

// テトラミノの衝突判定を扱う関数
bool is_hit_bottom(Tetrimino* mino);
bool is_hit_left(Tetrimino* mino);
bool is_hit_right(Tetrimino* mino);

#endif