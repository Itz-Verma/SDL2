#include<SDL2/SDL_mixer.h>
#include <iostream>
class Sound{
    
    public:
        Sound();
        void play();
        ~Sound();

    private:
        Mix_Chunk *audio = nullptr;
        Mix_Chunk *backgroundSong;

    private:
        
};
