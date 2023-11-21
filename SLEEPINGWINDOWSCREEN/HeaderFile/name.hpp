#include <iostream>
#include <SDL2/SDL_ttf.h>

class Name{
public:
    Name();
    void createTexture(SDL_Renderer* renderer);
    void displayOn(SDL_Rect*);
    ~Name();

private:
    TTF_Font *font = nullptr;
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Renderer *renderer = nullptr;
};
