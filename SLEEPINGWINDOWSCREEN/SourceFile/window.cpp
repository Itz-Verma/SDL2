#include "../HeaderFile/window.hpp"
Window::Window(): width{1000}, height{1000}, title{"SLEEP SCREEN"}
{
    createWindowAndRenderer();
    SDL_SetWindowTitle(window, title.c_str());
}

void Window::createWindowAndRenderer()
{
    SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer);
    if (!window) {
        std::cout<<"Window Failed: "<<SDL_GetError() << std::endl;
        exit(1);
    }
    if (!renderer) {
        std::cout<<"Renderer Failed: "<<SDL_GetError() << std::endl;
        exit(1);
    }


}

Window::~Window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


