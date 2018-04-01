#ifndef CREATURE_H
#define CREATURE_H

#include "field.h"
#include <random>
#include "simulation.h"

struct Direction
{
// Simple 2D vectors
public:
    int x;
    int y;
    
    Direction() = default;
    Direction(int xcomp, int ycomp) : x(xcomp), y(ycomp){};
    
    void left()
    {
        int tempx = x;
        int tempy = y;
        
        x = -tempy;
        y = tempx;
    }
    
    void right()
    {
        int tempx = x;
        int tempy = y;
        
        x = tempy;
        y = -tempx;
    }
    
    void add(const Direction& vec)
    {
        x += vec.x;
        y += vec.y;
    }
    
    void set(int newx, int newy)
    {
        x = newx;
        y = newy;
    }
};

enum class PosStatus {INSIDE, TOP, BOTTOM, LEFT, RIGHT};

class Creature
{
public:
    Creature(float en, float cst, float spd, float left, float right);
    
    Creature(Field* system); // randomised constructor
    
    void setEcoSys(Field* eco);
    
    void live();
    
    bool alive = true; // when created it is true and it is public information (may need to make it private though)
    int age = 0;
    
    
private:
    PosStatus checkBorders();
    void decideNextMove();
    
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

#endif
