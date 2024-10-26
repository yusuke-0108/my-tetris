
#ifndef FIELD_HEADER
#define FIELD_HEADER

#include "../common/header.hpp"
#include "../common/params.hpp"

class Field {
    protected:
        void update();
    
    public:
        Field() {}

        static int field[ROW][COL];
        static int field_color[ROW][COL];
};

#endif