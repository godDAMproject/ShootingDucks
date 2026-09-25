#include "AssetManager.h"
#include <iostream>

AssetManager& AssetManager::instance() {
    static AssetManager inst;
    return inst;
}

void AssetManager::preloadAll() {
    loadFont("default", "assets/fonts/arial.ttf");
    loadTexture("background", "assets/textures/background.png");
    loadTexture("duck", "assets/textures/duck.png");
    loadTexture("crosshair", "assets/textures/crosshair.png");
}

bool AssetManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture tex;
    if (tex.loadFromFile(filename)) {
        m_textures[name] = tex;
        return true;
    }
    std::cerr << "[AssetManager Error] Failed to load texture: " << filename << std::endl;
    return false;
}

const sf::Texture& AssetManager::getTexture(const std::string& name) const {
    return getResource(m_textures, name);
}

bool AssetManager::hasTexture(const std::string& name) const {
    return m_textures.find(name) != m_textures.end();
}

bool AssetManager::loadFont(const std::string& name, const std::string& filename) {
    sf::Font font;
    if (font.loadFromFile(filename)) {
        m_fonts[name] = font;
        return true;
    }
    std::cerr << "[AssetManager Error] Failed to load font: " << filename << std::endl;
    return false;
}

const sf::Font& AssetManager::getFont(const std::string& name) const {
    return getResource(m_fonts, name);
}
