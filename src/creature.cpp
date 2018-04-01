#include "creature.h"
#include <cstdlib>
#include <iostream>

Creature::Creature(float en, float cst, float spd, float left, float right) :
  energy(en),
  cost(cst),
  speed(spd),
  eating(2*cost),
  goLeft(left),
  goRight(right),
  pos(200, 200),
  move(1, 0)
{
}

Creature::Creature(Field* system) :
    energy(10.0),
    cost(1.0),
    speed(1/cost),
    eating(2*cost),
    ecosystem(system),
    move(1, 0)
{
    goLeft = static_cast<float>((*Simulation::dist)(*Simulation::rng))/300.0;
    goRight = static_cast<float>((*Simulation::dist)(*Simulation::rng))/300.0;
    
    pos.x = 3*(*Simulation::dist)(*Simulation::rng);
    pos.y = 3*(*Simulation::dist)(*Simulation::rng);
}


void Creature::setEcoSys(Field* eco)
{
    ecosystem = eco;
}

PosStatus Creature::checkBorders()
{
    if ( pos.x == 0 )
    {
        return PosStatus::LEFT;
    }
    else if ( pos.x == ecosystem->maxX() - 1)
    {
        return PosStatus::RIGHT;
    }
    else if ( pos.y == 0)
    {
        return PosStatus::TOP;
    }
    else if ( pos.y == ecosystem->maxY() - 1)
    {
        return PosStatus::BOTTOM;
    }
    return PosStatus::INSIDE;
}

void Creature::decideNextMove()
{
    float decision = static_cast<float>((*Simulation::dist)(*Simulation::rng)) / 100.0;
        
        if(decision < goLeft)
        {
            move.left();
        }
        else if (decision > (1 - goRight))
        {
            move.right();
        }
}



void Creature::live()
{
    if (energy < 0)
    {
        // die
        alive = false;
        std::cout << "I died at age of " << age <<". (" << goLeft << ", " << goRight <<')' << std::endl;
        return;
    }
    else
    {
        ++age;
        //live
        energy -= cost;
        pos.add(move);
        
        
        if( pos.x >= 0 && pos.x < ecosystem->maxX()
            && pos.y >= 0 && pos.y < ecosystem->maxY())
        {
            meal = ecosystem->infoFood(pos.x, pos.y); //potentially could eat this much
            meal = (meal > eating) ? eating : meal;
            
            
            ecosystem->decrease(pos.x, pos.y, meal); // take from the ecosystem
            energy += meal; // add to belly
        }
        else
        {
            std::cout <<"I wandered off the board." << std::endl;
        }
        
        // Prevents creatures to go off the board.
        switch(checkBorders())
        {
            case PosStatus::INSIDE:
                decideNextMove();
                break;
            case PosStatus::TOP:
                move.set(0, 1);
                break;
            case PosStatus::BOTTOM:
                move.set(0, -1);
                break;
            case PosStatus::LEFT:
                move.set(1, 0);
                break;
            case PosStatus::RIGHT:
                move.set(-1, 0);
                break;
        }
    }
}


