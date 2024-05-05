#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,1000),"Game",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
    this->textureManager.loadTexture("Zero","Textures/ZERO.png");
    this->textureManager.loadTexture("ZeroHitted","Textures/ZEROhitted.png");
    this->textureManager.loadTexture("BF109","Textures/BF109.png");
    this->textureManager.loadTexture("BF109Hitted","Textures/BF109hitted.png");
    this->textureManager.loadTexture("BULLET","Textures/bullet.png");
    this->textureManager.loadTexture("BULLETtyp1","Textures/BulletTyp1.png");
    this->textureManager.loadTexture("BULLETtyp2","Textures/BulletTyp2.png");
    this->textureManager.loadTexture("FW190","Textures/FW190.png");
    this->textureManager.loadTexture("FW190Hitted","Textures/FW190hitted.png");
    this->textureManager.loadTexture("cloud","Textures/cloud.png");
    this->textureManager.loadTexture("cloud2","Textures/cloud2.png");
    this->textureManager.loadTexture("cloud3","Textures/cloud3.png");
    this->textureManager.loadTexture("BOSS","Textures/BOSS.png");
    this->textureManager.loadTexture("BOSSHitted","Textures/BOSSHitted.png");
    this->textureManager.loadTexture("BOSSBullet","Textures/BOSSBullet.png");
    this->textureManager.loadTexture("BOSSBullet2","Textures/BOSSBullet2.png");
    this->textureManager.loadTexture("BOSSBullet3","Textures/BOSSBullet3.png");
    this->textureManager.loadTexture("background","Textures/map.png");
    this->textureManager.loadTexture("ILSturm","Textures/IL.png");
    this->textureManager.loadTexture("ILSturmHitted","Textures/ILHitted.png");
    this->textureManager.loadTexture("Rocket","Textures/Rocket.png");
    this->textureManager.loadTexture("heart","Textures/heart.png");
    this->textureManager.loadTexture("twobullets","Textures/twobullets.png");
    this->textureManager.loadTexture("Explosion1","Textures/explosion1.png");
    this->textureManager.loadTexture("Explosion2","Textures/explosion2.png");
    this->textureManager.loadTexture("Explosion3","Textures/explosion3.png");
    this->textureManager.loadTexture("Explosion4","Textures/explosion4.png");
    this->textureManager.loadTexture("Explosion5","Textures/explosion5.png");
    this->textureManager.loadTexture("Explosion6","Textures/explosion6.png");
}

void Game::initPlayer()
{
    this->player = new Player();
}

void Game::initAudio()
{
    this->audio = new AudioManager();
    //this->audio->loadMusic("Music/price-of-freedom-33106.wav");
    this->audio->playMusic();
}


void Game::initEnemies()
{
    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
    this->checkpoint = 1;
}
void Game :: initGUI()
{
    //Wczytaj font
    if(!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
        std:: cout << "ERROR::GAME::Failed to load font" << "\n";
    //Inicjalizacja pointText
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(20);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("test");
    //GameOver
    this->gameOverText;
    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(60);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setString("Game Over!");
    this->gameOverText.setPosition(this->window->getSize().x/2.f - this->gameOverText.getGlobalBounds().width/2.f,
                                   this->window->getSize().y/2.f - this->gameOverText.getGlobalBounds().height/2.f-200);


    this->playerNameText;
    this->playerNameText.setFont(font);
    this->playerNameText.setCharacterSize(30);
    this->playerNameText.setString("Wpisz swoje imie:");
    this->playerNameText.setPosition(this->window->getSize().x/2.f - this->playerNameText.getGlobalBounds().width/2.f,
                                   this->window->getSize().y/2.f - this->playerNameText.getGlobalBounds().height/2.f - 100);

    this->inputBox.setSize(sf::Vector2f(200, 40));
    this->inputBox.setFillColor(sf::Color::White);
    this->inputBox.setOutlineThickness(2);
    this->inputBox.setOutlineColor(sf::Color::Black);
    this->inputBox.setPosition(this->window->getSize().x/2.f - this->inputBox.getGlobalBounds().width/2.f,
                                this->window->getSize().y/2.f - this->inputBox.getGlobalBounds().height/2.f);

    this->inputText.setFont(font);
    this->inputText.setCharacterSize(30);
    this->inputText.setFillColor(sf::Color::Black);
    this->inputText.setPosition(this->window->getSize().x/2.f - this->inputBox.getGlobalBounds().width/2.f + 3,
                                this->window->getSize().y/2.f - this->inputBox.getGlobalBounds().height/2.f);

    //HPbar
    this->playerHpBar.setSize(sf::Vector2f(300.f,25.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBar.setPosition(sf::Vector2f(20.f,27.f));

    this->playerHpBarBack = this->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25,25,25,200));
}

void Game :: initWorld()
{
    if(!this->worldBackgroundTex.loadFromFile("Textures/map.png")){
    }
    this->world = new Map(&textureManager.getTexture("background"),1,0.5,1,window);
}

void Game :: initSystems()
{
    this->points = 0;
}

void Game :: initMenu()
{
    this->menu = new Menu(this->window);
}


void Game :: initScoreboard(){
    this->scoreboard = new Scoreboard(window);
}

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initGUI();
    this->initWorld();
    this->initSystems();
    this->initPlayer();
    this->initEnemies();
    this->initMenu();
    this->initAudio();
    this->spawnTimerBoost=0.f;
    this->spawnTimerBoostMax=2.f;
    this->spawnTimerMax2 = 5.f;
    bossSpawned = false;
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    for (auto &i : this->textures)
    {
        delete i.second;
    }

    for (auto *i : this->bullets)
    {
        delete i;
    }


    for (auto *i : this->enemies)
    {
        delete i;
    }
    delete audio;

    for (auto audio : audiovec)
    {
        delete audio;
    }
    audiovec.clear();

}

void Game::run()
{
    this->isMenuActive = true;
    this->isScoreboardActive = false;
    while(this->window->isOpen())
    {
        if (this->isMenuActive && this->isScoreboardActive) {this->scoreboardLogic();}
        else if (this->isMenuActive) this->menuLogic();
        else if(this->player->getHP()>0){
                this->updatePollEvents();
                this->update();
        }
        else {
                this->gameOverLogic();
        }
        this->render();
    }
}


void Game::scoreboardLogic(){
    sf::Event e;
    while(this->window->pollEvent(e))
    {
        if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::M)
        {
            if(audio->isMuted==false) audio->mute();
            else audio->unmute();
        }
        if (e.key.code == sf::Keyboard::Backspace)
        {
            this->isScoreboardActive = false;
        }
        if (e.key.code == sf::Keyboard::Escape)
        {
            this->window->close();
        }
        if(e.Event::type == sf::Event::Closed)
        {
            this->window->close();
        }
    }
}

void Game::gameOverLogic(){
    sf::Event e;
    maxInputLength = 10;
    audio->stopMusic();
    while(this->window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::Closed)
        {
            this->window->close();
        }
        if (e.type == sf::Event::TextEntered)
        {
            if (e.text.unicode < 128 && e.text.unicode != 13)
            {
                if (playerName=="" && e.text.unicode == 8) this->inputText.setFillColor(sf::Color::White);
                if (playerName.size() < maxInputLength)
                {
                    this->inputText.setFillColor(sf::Color::Black);
                    if (e.text.unicode == 8 && !playerName.empty())
                    {
                        playerName.pop_back();
                    }
                    else if (e.text.unicode != 8 && !playerName.empty() && e.text.unicode != 32)
                    {
                        playerName += static_cast<char>(e.text.unicode);
                    }
                    else if (e.text.unicode != 8 && playerName.empty() && e.text.unicode != 32)
                    {
                        playerName += static_cast<char>(e.text.unicode);
                    }
                    inputText.setString(playerName);
                }
                else if (e.text.unicode == 8 && !playerName.empty())
                {
                    playerName.pop_back();
                    inputText.setString(playerName);
                }
            }
            else if (e.text.unicode == 13 && !playerName.empty()) // Obsluga wcisku Entera
            {
                savePlayerStatsToFile();
                this->inputText.setFillColor(sf::Color::White);
                playerName="";
                this->isMenuActive = true;
                this->resetStats();
                this->clearAllVectors();
                audio->loadMusic("Music/price-of-freedom-33106.wav");
                audio->playMusic();
            }
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
        {
            this->window->close();
        }
    }
}

void Game::updatePollEvents()
{
    sf::Event e;
    while(this->window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::Closed)
        {
            this->window->close();
        }

        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
        {
            //this->isMenuActive = true;
            this->window->close();
        }
        if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::M)
        {
            if(audio->isMuted==false) audio->mute();
            else audio->unmute();
        }
    }
}

void Game::setPoints(int num){
    this->points = num;
}

void Game::resetStats(){
    this->setPoints(0);
    player->initVariables();
}

void Game::savePlayerStatsToFile(){
    std::ofstream file("wyniki.txt", std::ios::app);
    if (file.is_open())
    {
        file << playerName << " " << points << std::endl;
        file.close();
    }
}

void Game::menuLogic() {
    sf::Event e;
    while (this -> window -> pollEvent(e)) {
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
        {
            this->window->close();
        }
        if (e.type == sf::Event::KeyReleased && e.key.code == sf::Keyboard::M)
        {
            if(audio->isMuted==false) audio->mute();
            else audio->unmute();
        }
        switch (e.type) {
        case sf::Event::KeyReleased: {
            switch (e.key.code) {
            case sf::Keyboard::Up: {
                menu -> MoveUp();
                break;
            }
            case sf::Keyboard::Down: {
                menu -> MoveDown();
                break;
            }

            case sf::Keyboard::Space: {
                switch (menu -> GetPressedItem()) {
                case 0: { // guzik graj
                    this->isMenuActive=false;
                    audio->loadMusic("Music/ww2airplaneloop.wav");
                    audio->playMusic();
                    break;
                }
                case 1: { // guzik wyniki
                    this->initScoreboard();
                    this->isScoreboardActive=true;
                    break;
                }
                case 2: {
                    window -> close();
                    break;
                }
                }
            }

            break;
            }

            break;

            case sf::Event::Closed: {
                window -> close();
                break;
            }

        }
        }
    }
}

void Game::updateInput()
{
    //Ruch Gracza
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->player->wasDKeyPressed=false;
        this->player->move(-1,0);
        if(!this->player->wasAKeyPressed)
        {
            this->player->wasAKeyPressed = true;
            this->player->clock.restart();
        }
        else if (this->player->clock.getElapsedTime().asSeconds()>= 0.25f)
        {
            this->player->sprite.setTexture(this->player->textureAM);
        }
        else
        {
            this->player->sprite.setTexture(this->player->textureA);
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->player->wasAKeyPressed=false;
        this->player->move(1,0);
        if(!this->player->wasDKeyPressed)
        {
            this->player->wasDKeyPressed = true;
            this->player->clock.restart();
        }
        else if (this->player->clock.getElapsedTime().asSeconds()>= 0.25f)
        {
            this->player->sprite.setTexture(this->player->textureDM);
        }
        else
        {
            this->player->sprite.setTexture(this->player->textureD);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->player->move(0,-1);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->player->move(0,1);
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        this->player->wasDKeyPressed=false;
        this->player->wasAKeyPressed=false;
        this->player->sprite.setTexture(this->player->texture);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
    {
        this->bullets.push_back(new Bullet(&textureManager.getTexture("BULLET"),
                                           this->player->getPos().x-2.f+this->player->getBounds().width/2.f,
                                           this->player->getPos().y- 10.f,
                                           0.f,
                                           -1.f,
                                           5.f)
                                );
        if (isTwoBullets and shootingtimer.getElapsedTime().asSeconds() <= 10.f){
            this->bullets.push_back(new Bullet(&textureManager.getTexture("BULLET"),
                                           this->player->getPos().x+this->player->getBounds().width/3.f,
                                           this->player->getPos().y+14.f,
                                           0.f,
                                           -1.f,
                                           5.f)
                                );
            this->bullets.push_back(new Bullet(&textureManager.getTexture("BULLET"),
                                           this->player->getPos().x+this->player->getBounds().width/3.f+45,
                                           this->player->getPos().y+ 16.f,
                                           0.f,
                                           -1.f,
                                           5.f)
                                );
        }

        AudioManager* shootaudio = new AudioManager();
        audiovec.push_back(shootaudio);

        if (!shootaudio->isShooting()) {
            shootaudio->playShootSound();
        }
        for (auto it = audiovec.begin(); it != audiovec.end();)
        {
            if ((*it)->isShooting())
            {
                ++it;
            }
            else
            {
                delete *it;
                it = audiovec.erase(it);
            }
        }
    }
}

void Game::updateBoosts(){
    this->spawnTimerBoost+=0.02f;
	if (this->spawnTimerBoost  >= this->spawnTimerMax)
    {
        this->spawnTimerBoost=0.f;
        bool randomBoost = rand()%2;
        if (randomBoost == 0)
        this->boosts.push_back(new Heal (rand() % this->window->getSize() .x-20.f, -100.f, this->textureManager));
        else
        this->boosts.push_back(new TwoBullets (rand() % this->window->getSize() .x-20.f, -100.f, this->textureManager));
    }
	//Update
	unsigned counter = 0;
	for (auto *boost : this->boosts)
	{
		boost->update();
		if (boost->getBounds().top > this->window->getSize().y)
		{
			delete this->boosts.at(counter);
			this->boosts.erase(this->boosts.begin() + counter);
		}
		else if(boost->getBounds().intersects(this->player->getBounds()))
		{
		    if(boost->type == 1)
            {
                if (this->player->getHPMax() == player->getHP()){}
                else if (this->player->getHP()+30 > player->getHPMax()) {
                    int HPtoheal = player->getHPMax() - player->getHP();
                    this->player->loseHp(-HPtoheal);
                }
                else {this->player->loseHp(-30);}
		    }
		    if (boost->type == 2)
            {
                this->isTwoBullets = true;
                shootingtimer.restart();
            }

			delete this->boosts.at(counter);
			this->boosts.erase(this->boosts.begin() + counter);
		}

		++counter;
	}
}

void Game::updateExplosions()
{
    unsigned counter = 0;
    for(auto* explosion : this->explosions)
    {
        explosion->update();
        if (explosion->deleteExplosion)
		{
			delete this->explosions.at(counter);
			this->explosions.erase(this->explosions.begin() + counter);
		}
		counter++;
    }
}

void Game::updateClouds()
{
    this->spawnTimer2 += 0.2f;
	if (this->spawnTimer2 >= this->spawnTimerMax2)
    {
        int randomCloud = rand()%3;
        if(randomCloud == 0) {
        this->clouds.push_back(new Clouds(&textureManager.getTexture("cloud"),
                                           rand() % this->window->getSize() .x-200.f,
                                           -360.f,
                                           rand()%3/2.f+1.5f,
                                           0.7f,
                                           rand()%2));

        }
        else if(randomCloud == 1) {
            this->clouds.push_back(new Clouds(&textureManager.getTexture("cloud2"),
                                           rand() % this->window->getSize() .x-200.f,
                                           -360.f,
                                           rand()%3/2.f+1.5f,
                                           0.7f,
                                           rand()%2));
        }
        else if(randomCloud == 2) {
            this->clouds.push_back(new Clouds(&textureManager.getTexture("cloud3"),
                                           rand() % this->window->getSize() .x-200.f,
                                           -360.f,
                                           rand()%3/2.f+1.5f,
                                           0.7f,
                                           rand()%2));
        }
        this->spawnTimer2 =0.0f;
        this->spawnTimerMax2 = rand()%45 +50.f;
	}
    unsigned counter = 0;
    for(auto cloud : this->clouds)
    {
        if (cloud->getBounds().top > this->window->getSize().y)
        {
            delete this->clouds.at(counter);
            this->clouds.erase(this->clouds.begin()+counter);
            --counter;
        }
        cloud->update();
        ++counter;
    }
}

void Game::updateBullets()
{
    unsigned counter = 0;
    for (auto *bullet : this->bullets)
    {
        bullet->update();
        if (bullet->getBounds().top + bullet->getBounds().height < 0)
        {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+ counter);
            --counter;
        }
        ++counter;
    }
    unsigned counter2 = 0;
    for (auto *bullet : this->enemyBullets)
    {
        bullet->update();
        if (bullet->getBounds().top > this->window->getSize().y)
        {
            delete this->enemyBullets.at(counter2);
            this->enemyBullets.erase(this->enemyBullets.begin()+ counter2);
            --counter2;
        }
        ++counter2;
    }
}

void Game::updateEnemies()
{
	this->spawnTimer += 0.25f;
	if (this->spawnTimer >= this->spawnTimerMax)
    {
    if(this->points <=200 * this->checkpoint && !this->bossSpawned)
    {
        int enemyToSpawn = rand()%4;
        if (enemyToSpawn == 0)
            this->enemies.push_back(new MitsuZero (rand() % this->window->getSize().x-50.f, -150.f, this->textureManager, this->enemyBullets));
        else if (enemyToSpawn == 1){
            this->enemies.push_back(new BF109 (rand() % this->window->getSize() .x-50.f, -150.f, this->textureManager,this->enemyBullets));
        }
        else if (enemyToSpawn == 2)
            this->enemies.push_back(new FW190 (rand()% this->window->getSize() .x-50.f, -100.f, this->textureManager,this->enemyBullets));
        else if (enemyToSpawn == 3)
            this->enemies.push_back(new ILSturm (rand()% this->window->getSize() .x-150.f, -230.f, this->textureManager,this->enemyBullets));
        this->spawnTimer = 0.f;
    }
        else if(!this->bossSpawned)
        {
            this->enemies.push_back(new BOSS (this->window->getSize().x/2.f - 350.f, -500.f, this->textureManager,this->enemyBullets));
            this->checkpoint+=2;
            this->bossSpawned=true;
        }

    }
    if(this->bossSpawned && this->enemies.size() == 0)
    {
        this->spawnTimerMax/=1.3;
        this->bossSpawned = false;
    }

	//Update
	unsigned counter = 0;
	for (auto *enemy : this->enemies)
	{
		enemy->update();

		if (enemy->getBounds().top > this->window->getSize().y)
		{
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//Kolizja z graczem
		else if(enemy->hitbox1.intersects(this->player->getBounds()) || enemy->hitbox2.intersects(this->player->getBounds()) || enemy->hitbox1.intersects(this->player->getBounds()) )
		{
		    this->explosions.push_back(new Explosion(enemy->getPos().x,enemy->getPos().y,this->textureManager,enemy->type));
			this->player->loseHp(this->enemies.at(counter)->getDamage()*3);
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}

		++counter;
	}
}
void Game::updateEnemiesBullets()
{
    for(auto enemy : this->enemies)
    {
        enemy->shoot();
    }
}


void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
    {
        bool enemy_deleted = false;
        for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
        {
            int hitboxHitted = 1;
            if (this->enemies[i]->hitbox1.intersects(this->bullets[k]->getBounds()) || this->enemies[i]->hitbox2.intersects(this->bullets[k]->getBounds()) || this->enemies[i]->hitbox3.intersects(this->bullets[k]->getBounds()))
            {
                if (this->enemies[i]->hitbox2.intersects(this->bullets[k]->getBounds()))
                    hitboxHitted=2;
                this->enemies[i]->loseHp(this->player->getDamage()*hitboxHitted);
                if(this->enemies[i]->hp <= 0)
                {
                    this->explosions.push_back(new Explosion(enemies[i]->getPos().x,
                                                             enemies[i]->getPos().y,
                                                             this->textureManager,
                                                             enemies[i]->type)
                                                );
                    this->points += this->enemies[i]->getPoints();
                    delete this->enemies[i];
                    this->enemies.erase(this->enemies.begin() + i);
                }

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);
                enemy_deleted = true;
            }
        }
    }

	for (int i = 0; i < this->enemyBullets.size(); i++)
    {
        if (this->enemyBullets[i]->getBounds().intersects(this->player->hitbox1) || this->enemyBullets[i]->getBounds().intersects(this->player->hitbox2) || this->enemyBullets[i]->getBounds().intersects(this->player->hitbox3))
        {
            this->player->loseHp(this->enemyBullets[i]->damage);
            delete this->enemyBullets[i];
            this->enemyBullets.erase(this->enemyBullets.begin() + i);
        }
    }
}

void Game::updateGUI()
{
    std::stringstream ss;
    ss << "Points: " << this->points;
    this->pointText.setString(ss.str());
    float hpPercent = static_cast<float>(this->player->getHP()) / this->player->getHPMax();
    this->playerHpBar.setSize(sf::Vector2f(300.f*hpPercent,this->playerHpBar.getSize().y));
}

void Game::updateWorld()
{
    world->update();
}

void Game::updateCollision()
{
    //left
    if(this->player->getBounds().left < 0.f)
    {
        this->player->setPosition(0.f, this->player->getBounds().top);
    }
    //right
    else if(this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
    {
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
    }
    //top
    if(this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left, 0.f);
    }
    else if(this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
    {
        this->player->setPosition(this->player->getBounds().left, this->window->getSize().y-this->player->getBounds().height);
    }
}
void Game::update()
{
    this->updateInput();
    this->player->update();
    this->updateCollision();
    this->updateBullets();
    this->updateEnemiesBullets();
    this->updateEnemies();
    this->updateCombat();
    this->updateGUI();
    this->updateWorld();
    this->updateClouds();
    this->updateBoosts();
    this->updateExplosions();
}
void Game::renderGUI()
{
    this->window->draw(this->pointText);
    this->window->draw(this->playerHpBarBack);
    this->window->draw(this->playerHpBar);
}
void Game::renderWorld()
{
    world->render(this->window);
}

void Game::renderMenu(){
    this->menu->draw();
}

void Game::renderScoreboard(){
    this->scoreboard->draw();
}

void Game::clearAllVectors(){
    bullets.clear();
    enemies.clear();
    enemyBullets.clear();
    clouds.clear();
    boosts.clear();
}

void Game::render()
{
    this->window->clear();
    if (this->isMenuActive && this->isScoreboardActive) this->renderScoreboard();
    else if (this->isMenuActive) this->renderMenu();
    //Draw world
    else{
        this->renderWorld();


        for (auto *cloud : this->clouds)
        {
            cloud->render(this->window);
        }
        for (auto *explosion : this->explosions)
        {
            explosion->render(this->window);
        }

        for (auto *bullet : this->bullets)
        {
            bullet->render(this->window);
        }
        this->player->render(*this->window);
        for (auto *bullet : this->enemyBullets)
        {
            bullet->render(this->window);
        }
        for (auto *enemy : this->enemies)
        {
            enemy->render(this->window);
        }
        for (auto *boost : this->boosts)
        {
            boost->render(this->window);
        }


        //Game over ekran
        if(this->player->getHP() <= 0) {
            this->window->draw(this->gameOverText);
            this->window->draw(this->playerNameText);
            this->window->draw(this->inputBox);
            this->window->draw(this->inputText);
        }
        this->renderGUI();
    }
    this->window->display();
}
