#include "../HeaderFile/sound.hpp"

Sound::Sound(){
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4000);
    audio = Mix_LoadWAV("./ResourceFile/collision.mp3");
    if( audio == nullptr ) std::cout<<Mix_GetError()<<std::endl;
}

void Sound::play(){
    Mix_PlayChannel(-1, audio, 0);
}

Sound::~Sound(){
    Mix_FreeChunk(audio);
    Mix_CloseAudio();
}
