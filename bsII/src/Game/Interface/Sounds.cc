#include "SFML/Audio.hpp"

#include "Game/Interface/Sounds.h"

#include "Utils/Path.h"

namespace BrickShooter
{
    using Utils::Path;
    using Utils::SysPath;

    sf::Music Sounds::backgroundMusic;

    sf::SoundBuffer Sounds::shotSoundBuffer;

    sf::SoundBuffer Sounds::hitSoundBuffer;

    sf::SoundBuffer Sounds::gameOverSoundBuffer;

    sf::SoundBuffer Sounds::levelUpSoundBuffer;

    sf::SoundBuffer Sounds::restartSoundBuffer;

    sf::Sound Sounds::shotSound;

    sf::Sound Sounds::hitSound;

    sf::Sound Sounds::gameOverSound;

    sf::Sound Sounds::levelUpSound;

    sf::Sound Sounds::restartSound;

    void Sounds::loadSounds() {
        backgroundMusic.openFromFile(Path::getSoundPath("background.ogg"));
        backgroundMusic.setLoop(true);

        shotSoundBuffer.loadFromFile(Path::getSoundPath("shot.wav"));
        hitSoundBuffer.loadFromFile(Path::getSoundPath("hit.wav"));
        gameOverSoundBuffer.loadFromFile(Path::getSoundPath("gameOver.wav"));
        levelUpSoundBuffer.loadFromFile(Path::getSoundPath("levelUp.wav"));
        restartSoundBuffer.loadFromFile(Path::getSoundPath("restart.wav"));

        shotSound.setBuffer(shotSoundBuffer);
        hitSound.setBuffer(hitSoundBuffer);
        gameOverSound.setBuffer(gameOverSoundBuffer);
        levelUpSound.setBuffer(levelUpSoundBuffer);
        restartSound.setBuffer(restartSoundBuffer);
    }

    void Sounds::playBackgroundMusic() {
        backgroundMusic.play();
    }

    void Sounds::playShotSound() {
        shotSound.play();
    }

    void Sounds::playHitSound() {
        hitSound.play();
    }

    void Sounds::playGameOverSound() {
        gameOverSound.play();
    }

    void Sounds::playLevelUpSound() {
        levelUpSound.play();
    }

    void Sounds::playRestartSound() {
        restartSound.play();
    }
}
