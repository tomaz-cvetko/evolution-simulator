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
     
    for(auto& being : fauna)
    {
        // allocate objects to pointers in the vector
        being = new Creature(&simField);
    }
    
    
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
    
    //SDL, visualisation part
    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;
    
    long int count = 0;
    
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
            else if( e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == 'w' && e.key.keysym.mod & KMOD_LCTRL)
                {
                    quit = true;
                }
            }
        }
        
        SDL_Delay(500);
        std::cout << count++ <<std::endl;
    }
    
    Simulation::exit();
    
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
