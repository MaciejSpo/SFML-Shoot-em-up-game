#ifndef ENEMYBULLETS_H
#define ENEMYBULLETS_H


class EnemyBullets
{
    public:
        EnemyBullets();
        EnemyBullets(sf::Texture* texture, float pos_x, float pos_y, float dir_x,float dir_y,float movement_speed);
        virtual ~EnemyBullets();

        // Accessor
        const sf::FloatRect getBounds() const;

        void update();
        void render(sf::RenderTarget* target);

    protected:

    private:
        sf::Sprite shape;
        sf::Vector2f direction;
        float movementSpeed;
};

#endif // ENEMYBULLETS_H
