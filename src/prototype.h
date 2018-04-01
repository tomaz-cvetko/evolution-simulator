#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include "creature.h"
#include "field.h"

class Prototype
{
public:
    Prototype(float en, float cst, float spd, float left, float right);
    
    Prototype(Field* system); // randomised constructor
    
    void setEcoSys(Field* eco);
    
    void live();
    
    bool alive = true; // when created it is true and it is public information (may need to make it private though)
    int age = 0;
    
    
private:
    float energy;
    const float cost; // energy consumption per turn
    const float speed; // speed parameter
    const float eating = 2.0;
    
    float goLeft, goRight;
    
    Field* ecosystem = nullptr;
    Direction pos;
    Direction move;
    
    float meal = 0.0;
   
};

#endif // PROTOTYPE_H
