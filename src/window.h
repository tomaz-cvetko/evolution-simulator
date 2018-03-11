#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>

class Window
{
public:
    Window() = default;
    
    ~Window(){ this->close(); }
    
    //Starts up SDL and creates window
    bool init();

    //Loads media
    //bool loadMedia();

    //Frees media and shuts down SDL
    void close();
    
    SDL_Renderer* getRenderer();
    
    void drawField(const std::vector<std::vector<float> >& aField, const int scaling = 1);
    
    //Loads individual image as texture
    //SDL_Texture* loadTexture( std::string path );
    
private:
    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;
};

#endif

