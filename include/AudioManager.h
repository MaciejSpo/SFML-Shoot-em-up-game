#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <SFML/Audio.hpp>

class AudioManager
{
    public:
        AudioManager();
        virtual ~AudioManager();
        void loadMusic(const std::string& filePath);
        void playMusic();
        bool isMuted;
        void mute();
        void unmute();
        void playShootSound();
        void stopShootSound();
        void stopMusic();
        bool isShooting();

    protected:

    private:
        void pauseMusic();
        void setMusicLoop(bool loop);
        bool loop;
        sf::Music music;
        sf::SoundBuffer shootBuffer;
        sf::Sound shootSound;
};

#endif // AUDIOMANAGER_H
