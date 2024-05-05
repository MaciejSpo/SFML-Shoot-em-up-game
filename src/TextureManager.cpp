#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
    sf::Texture tex;
    tex.loadFromFile(filename);
    this->textures[name] = tex;
}

sf::Texture& TextureManager::getTexture(const std::string& name)
{
    return this->textures.at(name);
}
