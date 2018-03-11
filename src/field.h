#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include "simulation.h"


class Field
{
public:
    Field(int height, int width);
    
    float infoFood(int x, int y);
    void decrease(int x, int y, float amount);
    
    int maxX(){ return w; }
    int maxY(){ return h; }
    const std::vector<std::vector<float> >& getField(){ return field; }
    const int getScale(){ return scaling; }
    
private:
    std::vector<std::vector<float> > field;
    const int scaling = 4;
    
    const int w;
    const int h;
    
};


#endif
