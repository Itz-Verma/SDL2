#include "../HeaderFile/sleepScreen.hpp"
#include <SDL2/SDL_mixer.h>

SleepScreen::SleepScreen() : rectangle{300, 400, 200, 100},
    accelerationX{5}, accelerationY{5}
{
    SDL_Init(SDL_INIT_EVERYTHING);
    renderer = window.getRenderer();
    name.createTexture(renderer);
    isRunning = true;
}

void SleepScreen::start(){
    while(isRunning)
    {
        handle();
        update();
        show();
    }

}

void SleepScreen::handle(){
    while(SDL_PollEvent(&event)){
        switch (event.type) {
            case SDL_QUIT:
            case SDL_KEYDOWN:
                isRunning = false;
                break;
          }
    }
}

void SleepScreen::update(){
    if(rectangle.x <= 0 || rectangle.x >= 800){
        accelerationX = -accelerationX;
        sound.play();
    }

    if(rectangle.y <=0  || rectangle.y >= 900 ){
        accelerationY = -accelerationY;
        sound.play();
    }

    rectangle.x += accelerationX;
    rectangle.y += accelerationY;
}

void SleepScreen::show(){
    SDL_SetRenderDrawColor(renderer, 0,0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255,0, 0, 255);
    SDL_RenderDrawRect(renderer, &rectangle);
    name.displayOn(&rectangle);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);
}

SleepScreen::~SleepScreen(){
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
