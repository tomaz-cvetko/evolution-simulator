#include "field.h"
#include <cstdlib>

const float pi = std::acos(-1);

Field::Field::Field(int height, int width) : field(height, std::vector<float>(width, 1.0)), w(width), h(height)
{
    //additional stuff
    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j){
            //field[j][i] = 1.0 + 1.0*std::sin(pi/5 *i)*std::cos(pi/5 * j);
            field[j][i] = 2;
        }
    }
}

float Field::infoFood(int x, int y)
{
    return field.at(y).at(x);
}


void Field::decrease(int x, int y, float amount)
{
    field.at(y).at(x) -= amount;
}




