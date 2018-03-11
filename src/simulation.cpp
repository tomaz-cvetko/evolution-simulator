#include "simulation.h"

// definition of global RNG generator
std::mt19937* Simulation::rng = nullptr;
std::uniform_int_distribution<std::mt19937::result_type>* Simulation::dist = nullptr;

void Simulation::init()
{
    Simulation::rng = new std::mt19937();
    Simulation::rng->seed(std::random_device()());
    Simulation::dist = new std::uniform_int_distribution<std::mt19937::result_type>(0, 100);
}

void Simulation::exit()
{
    delete Simulation::rng;
    delete Simulation::dist;
}

