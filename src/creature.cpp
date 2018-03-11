#include "creature.h"
#include <cstdlib>
#include <iostream>

Creature::Creature(float en, float cst, float spd, float left, float right) :
  energy(en), cost(cst), speed(spd), goLeft(left), goRight(right), pos(200, 200), move(1, 0), eating(2*cost)
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

void Creature::live()
{
    if (energy < 0)
    {
        // die
        alive = false;
        std::cout << "I died at age of " << age <<"." << std::endl;
        return;
    }
    else
    {
        ++age;
        //live
        energy -= cost;
        pos.add(move);
        
        
        // WARNING it does not prevent leaving the board, just prevents calling stupid indexes
        if( pos.x >= 0 && pos.x < ecosystem->maxX()
            && pos.y >= 0 && pos.y < ecosystem->maxY())
        {
            meal = ecosystem->infoFood(pos.x, pos.y); //potentially could eat this much
            meal = (meal > eating) ? eating : meal;
            
            
            ecosystem->decrease(pos.x, pos.y, meal); // take from the ecosystem
            energy += meal; // add to belly
            
            //std::cout << "Ate food at" << pos.x << ' ' << pos.y <<std::endl;
            //std::cout << "I have this much energy: " << energy <<std::endl;
        }
        else
        {
            std::cout << "Stuck on making move" << std::endl;
        }
        
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
}


