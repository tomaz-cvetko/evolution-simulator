#include <iostream>
#include <SDL.h>
#include <vector>


#include "window.h"
#include "field.h"
#include "creature.h"
#include "simulation.h"

#include <random>
int main(int argc, char **argv) {
    
    Simulation::init();
    
    Window theWindow;
    theWindow.init();
    SDL_Renderer* globalRen = theWindow.getRenderer();
    
    Field simField(640, 480);
    
    
    // make test subjects
    std::vector<Creature*> fauna(100, nullptr);
    fauna[0] = new Creature(&simField);
     
    for(auto& being : fauna)
    {
        being = new Creature(&simField);
//         being->setEcoSys(&simField);
    }
    
//     Creature testOrg(10.0, 1.0, 1.0, 0.15, 0.05);
//     testOrg.setEcoSys(&simField);
    
//     Creature* testOrg2 = nullptr;
//     testOrg2 = new Creature(&simField);
    
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;
    
    long int count = 0;
    
    for (int i=0; i < 2000; ++i)
    {
        for(auto& being : fauna)
        {
            if(being->alive)
            {
                being->live();
            }
        }
    }
    
    
    //Clear screen
    SDL_SetRenderDrawColor( globalRen, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( globalRen );
    
    
    theWindow.drawField(simField.getField(), simField.getScale());
    
    SDL_RenderPresent(globalRen);
    
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }
        
        SDL_Delay(500);
        std::cout << count++ <<std::endl;
    }
    
    Simulation::exit();
    
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
