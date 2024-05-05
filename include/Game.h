#ifndef GAME_H
#define GAME_H
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Menu.h"
#include "Bullet.h"
#include "Enemy.h"
#include "MitsuZero.h"
#include "TextureManager.h"
#include "BF109.h"
#include "FW190.h"
#include "Clouds.h"
#include "Scoreboard.h"
#include "BOSS.h"
#include "Map.h"
#include "AudioManager.h"
#include "ILSturm.h"
#include "Boost.h"
#include "Heal.h"
#include "TwoBullets.h"
#include "Explosion.h"
class Game
{
    private:
        sf::Clock shootingtimer;
        bool isTwoBullets = false;
        bool isMenuActive;
        bool isScoreboardActive;
        unsigned int maxInputLength;
        Menu* menu;
        Scoreboard* scoreboard;
        Map* world;
        AudioManager* audio;
        //Window
        sf::RenderWindow* window;
        //Resources
        std::map<std::string, sf::Texture*> textures;
        std::vector<Bullet*> bullets;
        std::vector<AudioManager*> audiovec;
        std::vector<Explosion*> explosions;
        std::vector<Clouds*> clouds;
        std::vector<Boost*> boosts;
        float spawnTimerBoost;
        float spawnTimerBoostMax;
        //Player
        Player* player;
        //Enemies
        std::vector<Enemy*> enemies;
        float spawnTimer;
        float spawnTimer2;
        float spawnTimerMax2;
        float spawnTimerMax;
        std::vector<Bullet*> enemyBullets;
        int checkpoint;
        bool bossSpawned;
        //GUI
        sf::Font font;
        sf::Text pointText;
        sf::Text playerNameText;
        sf::RectangleShape inputBox;
        sf::Text inputText;
        std::string playerName;

        sf::Text gameOverText;
        //Systems
        unsigned points;
        //PlayerGUI
        sf::RectangleShape playerHpBar;
        sf::RectangleShape playerHpBarBack;
        //World
        sf::Sprite worldBackground;
        sf::Texture worldBackgroundTex;


        void initGUI();
        void initWindow();
        void initTextures();
        void initPlayer();
        void initEnemies();
        void initWorld();
        void initSystems();
        void initMenu();
        void initScoreboard();
        void clearAllVectors();
        void initAudio();
    public:
        Game();
        virtual ~Game();
        TextureManager textureManager;
        void run();
        void updatePollEvents();
        void updateInput();
        void updateBullets();
        void updateGUI();
        void updateWorld();
        void updateCollision();
        void update();
        void updateEnemies();
        void updateCombat();
        void renderGUI();
        void renderWorld();
        void render();
        void menuLogic();
        void renderMenu();
        void updateEnemyBullets();
        void updateEnemiesBullets();
        void updateClouds();
        void gameOverLogic();
        void savePlayerStatsToFile();
        void renderScoreboard();
        void scoreboardLogic();
        void setPoints(int num);
        void resetStats();
        void updateBoosts();
        void updateExplosions();
    protected:

};

#endif // GAME_H
