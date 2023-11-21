#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class Window{

    public:
        Window();
        SDL_Renderer* getRenderer(){ return renderer; }  
        ~Window();

    private:
        void createWindowAndRenderer();

    private:
        size_t width;
        size_t height;
        const std::string title;
        SDL_Window* window;
        SDL_Renderer* renderer;

};
