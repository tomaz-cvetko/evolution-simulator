#ifndef SIMULATION_H
#define SIMULATION_H

#include <random>

class Simulation
{
public:
    // global random generators to be used by all entities
    static std::mt19937* rng;
    static std::uniform_int_distribution<std::mt19937::result_type>* dist;
    
    static void init();
    static void exit();
    
};

#endif
