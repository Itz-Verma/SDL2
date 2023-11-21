#include "window.hpp"
#include "sound.hpp"
#include "name.hpp"
class SleepScreen{

    public:
        SleepScreen();
        void start();
        ~SleepScreen();
    
    private:
        SDL_Renderer* renderer;
        SDL_Event event;
        bool isRunning;
        Window window;
        SDL_Rect rectangle;
        float accelerationX,accelerationY;
        Sound sound;
        Name name;
    private:
        void update();
        void handle();
        void show();

};
