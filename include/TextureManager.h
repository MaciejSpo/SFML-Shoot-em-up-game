#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    void loadTexture(const std::string& name, const std::string& filename);
    sf::Texture& getTexture(const std::string& name);

private:
    std::map<std::string, sf::Texture> textures;
};

#endif // TEXTUREMANAGER_H
