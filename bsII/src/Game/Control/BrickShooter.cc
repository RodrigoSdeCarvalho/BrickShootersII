#include "Game/Control/BrickShooter.h"
#include "Concurrency/traits.h"
#include "SFML/Audio.hpp"
#include "Game/Interface/Sounds.h"
#include "Game/Logic/Point.h"

__BEGIN_API

int BrickShooter::killedEnemies = 0;
Player* BrickShooter::player;
KeyboardHandler* BrickShooter::keyboardHandler;
CollisionHandler* BrickShooter::collisionHandler;
Window* BrickShooter::window;
vector<Enemy*> BrickShooter::enemies;
Thread* BrickShooter::playerThread;
Thread* BrickShooter::collisionHandlerThread;
Thread* BrickShooter::keyboardHandlerThread;
Thread* BrickShooter::windowThread;
vector<Thread*> BrickShooter::enemiesThreads;
Info* BrickShooter::info;

void BrickShooter::play(void * name)
{
    // Create game objects
    BrickShooter::init();

    // Create threads
    windowThread = new Thread(BrickShooter::windowThreadFunction);
    playerThread = new Thread(BrickShooter::playerThreadFunction);
    keyboardHandlerThread = new Thread(BrickShooter::keyboardHandlerThreadFunction);
    collisionHandlerThread = new Thread(BrickShooter::collisionHandlerThreadFunction);

    // Start threads
    int index = 0;
    for (auto enemy : BrickShooter::enemies)
    {
        enemiesThreads.push_back(new Thread(BrickShooter::enemiesThreadFunction, index));
        index++;
    }

    // Wait for threads to finish
    collisionHandlerThread->join();
    for (auto enemyThread : enemiesThreads)
    {
        enemyThread->join();
    }

    windowThread->join();
    playerThread->join();
    keyboardHandlerThread->join();

    // Delete game objects and threads
    Config::deleteSemaphores();
    delete window;
    delete player;
    delete keyboardHandler;
        delete collisionHandler;
    delete collisionHandlerThread;
    delete windowThread;
    delete keyboardHandlerThread;
    for (auto enemyThread : enemiesThreads)
    {
        delete enemyThread;
    }
    delete playerThread;
    for (auto enemy : enemies)
    {
        delete enemy;
    }
    delete info;
}

void BrickShooter::playerThreadFunction()
{
    player->run();
    playerThread->thread_exit(0);
}

void BrickShooter::collisionHandlerThreadFunction()
{
    collisionHandler->run();
    collisionHandlerThread->thread_exit(0);
}

void BrickShooter::keyboardHandlerThreadFunction()
{
    keyboardHandler->run();
    keyboardHandlerThread->thread_exit(0);
}

void BrickShooter::enemiesThreadFunction(int index)
{
    enemies[index]->run();
    enemiesThreads[index]->thread_exit(0);
}

void BrickShooter::windowThreadFunction()
{
    window->run();
    windowThread->thread_exit(0);
}

void BrickShooter::init()
{
    Sounds::loadSounds();
    info = new Info();

    collisionHandler = new CollisionHandler();
    window = new Window();
    keyboardHandler = new KeyboardHandler(window);
    player = new Player(keyboardHandler);
    enemies.push_back(new Enemy(Enemy::Algorithm::C, player, Point(100, 100)));
    enemies.push_back(new Enemy(Enemy::Algorithm::A, player, Point(100, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE)));
    enemies.push_back(new Enemy(Enemy::Algorithm::D, player, Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, 100)));
    enemies.push_back(new Enemy(Enemy::Algorithm::B, player, Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE)));

    enemies[0]->setEnemiesToAvoid(enemies[1], enemies[2], enemies[3]);
    enemies[1]->setEnemiesToAvoid(enemies[0], enemies[2], enemies[3]);
    enemies[2]->setEnemiesToAvoid(enemies[0], enemies[1], enemies[3]);
    enemies[3]->setEnemiesToAvoid(enemies[0], enemies[1], enemies[2]);
}

bool BrickShooter::shouldLevelUp()
{
    killedEnemies++;
    Info::levelSemaphore->p();
    int level = info->level;
    Info::levelSemaphore->v();
    return (killedEnemies == Config::enemiesPerLevel && level+1 <= Config::maxLevel);
}

void BrickShooter::increaseScore()
{
    info->incraseScore();
}

void BrickShooter::increaseLevel()
{
    {
        info->increaseLevel();
        killedEnemies = 0;
        Enemy::ENEMY_SPEED += 25;
        Sounds::playLevelUpSound();
    }
}

void BrickShooter::restart()
{
    killedEnemies = 0;

    Info::livesSemaphore->p();
    info->lives = Config::lives;
    Info::livesSemaphore->v();

    Info::scoreSemaphore->p();
    info->score = 0;
    Info::scoreSemaphore->v();

    Info::levelSemaphore->p();
    info->level = 1;
    Info::levelSemaphore->v();

    player->removeFromGame();
    player->insertInGame();

    Config::gameOver = false;

    enemies[0]->setPosition(Point(100, 100));
    enemies[0]->previousPosition= Point(100, 100);
    enemies[1]->setPosition(Point(Point(100, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE)));
    enemies[1]->previousPosition= Point(Point(100, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE));
    enemies[2]->setPosition(Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, 100));
    enemies[2]->previousPosition= Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, 100);
    enemies[3]->setPosition(Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE));
    enemies[3]->previousPosition= Point(Config::playableAreaWidth - 100 - Enemy::ENEMY_SIZE, Config::playableAreaHeight - 100 - 2*Enemy::ENEMY_SIZE);

    for (auto enemy : enemies)
        enemy->insertInGame();

    collisionHandler->restart();
    CollisionHandler::addPlayer(player);

    Enemy::ENEMY_SPEED = 25;

    Sounds::playRestartSound();
}

__END_API
