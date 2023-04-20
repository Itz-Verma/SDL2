#include "rotate_rectangle.hpp"

Rectangle::Rectangle(const std::string& title,const uint16_t width,const uint16_t height) :

    SCREEN_WIDTH {width},
    SCREEN_HEIGHT{ height},
    points{{400,400},{500,400},{500,500},{400,500}},
    angle{0}
{

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&window,&renderer);
    SDL_SetWindowTitle(window,title.c_str());

    running = true;
}

void Rectangle::start()
{
    while(running)
    {
        update();
        handle();
        show();  
        rotate();      
    }
}

void Rectangle::update()
{
    angle += 0.01;
    if(angle >= 6.28f) angle = 0; 
}

void Rectangle::handle()
{
    while(SDL_PollEvent(&event)){
        switch(event.type)
        {
            case SDL_QUIT:
            case SDL_KEYDOWN:
                running = false;
                break;
        }

    }
}

void Rectangle::show()
{
    SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i=0;i<4; i++)
    {
        SDL_RenderDrawLine(renderer,points[i].x,points[i].y,points[(i+1)%4].x,points[(i+1)%4].y);
    }
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(5);
} 
   
void Rectangle::rotate(){
    shiftOrigin(); //before application of 2d transformation.
    for(int i=0; i<4; i++){
        double tempX = points[i].x, tempY = points[i].y;
        points[i].x = tempX*cos(angle) - tempY*sin(angle) ;
        points[i].y = tempX*sin(angle) + tempY*cos(angle) ;   
    }
    reshiftOrigin();//after transformation.

}

void Rectangle::shiftOrigin()
{
    points[0].x = points[0].y = points[1].y = points[3].x = -50;
    points[1].x = points[2].x = points[2].y = points[3].y = 50;
}

void Rectangle::reshiftOrigin()
{
    for(int i=0; i<4;i++)
    {
        points[i].x += 450;
        points[i].y += 450;
    
    }
}

Rectangle::~Rectangle() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}




