#include "../HeaderFile/name.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

Name::Name(){
    TTF_Init();
    font = TTF_OpenFont("./ResourceFile/8bitOperatorPlus8-Regular.ttf", 512);
    //if(font == nullptr ) std::cout<<"Font failed\n";
    surface = TTF_RenderText_Solid(font,"PRINCE", {255,255,0,255});
    //if(surface == nullptr) std::cout<<"Suraface failed\n";
}

void Name::createTexture(SDL_Renderer *Renderer){
    renderer = Renderer;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    //if(texture == nullptr) std::cout<<"Txt filed\n";

}

void Name::displayOn( SDL_Rect *rect){
    //if(!rect) std::cout<<"rect failed\n";
    SDL_RenderCopy(renderer, texture, nullptr, rect);

}

Name::~Name(){
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_Quit();
}
