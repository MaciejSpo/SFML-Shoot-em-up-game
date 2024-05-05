#include "AudioManager.h"

AudioManager::AudioManager()
{
    music.setLoop(true);
    music.setVolume(5);
    if (!shootBuffer.loadFromFile("Music/gun-shot-6178.wav")) {
    }
    shootSound.setVolume(10);
    if (!music.openFromFile("Music/price-of-freedom-33106.wav"))
    {
    }
}

AudioManager::~AudioManager()
{
}

void AudioManager::loadMusic(const std::string& filePath)
{
    if (!music.openFromFile(filePath))
    {
    }
}

void AudioManager::playMusic()
{
    music.play();
}

void AudioManager::pauseMusic()
{
    music.pause();
}

void AudioManager::stopMusic()
{
    music.stop();
}

void AudioManager::setMusicLoop(bool loop)
{
    music.setLoop(loop);
}

void AudioManager::mute()
{
    music.setVolume(0);
    shootSound.setVolume(0);
    isMuted = true;
}

void AudioManager::unmute()
{
    music.setVolume(5);
    shootSound.setVolume(5);
    isMuted = false;
}

void AudioManager::stopShootSound() {
    shootSound.stop();
}

void AudioManager::playShootSound(){
    shootSound.setBuffer(shootBuffer);
    shootSound.play();
}

bool AudioManager::isShooting()
{
    return shootSound.getStatus() == sf::Sound::Playing;
}

