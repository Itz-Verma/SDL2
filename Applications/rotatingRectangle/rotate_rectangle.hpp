#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
class Rectangle{
private:
    const std::string title;
    const uint16_t SCREEN_WIDTH;
    const uint16_t SCREEN_HEIGHT;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool running;
    SDL_Event event; //keyboards press 
    SDL_Point  points[4]; //four points of square.
    double angle;

private:
    void update();//  update angle.
    void handle();//pull event from keyboards and press 'x'
    void show();//show line between update position of points
    void shiftOrigin();// to shift to origine to apply the 2d transformation.
    void reshiftOrigin(); // to shift to new position after rotatation.
    void rotate(); // rotate the points.
public:
    Rectangle(const std::string&, const uint16_t,uint16_t);
    void start();
    ~Rectangle();
};
