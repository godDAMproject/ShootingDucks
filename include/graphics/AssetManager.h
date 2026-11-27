#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <stdexcept>

class AssetManager {
public:
    static AssetManager& instance();

    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    void preloadAll();

    bool loadTexture(const std::string& name, const std::string& filename);
    const sf::Texture& getTexture(const std::string& name) const;
    bool hasTexture(const std::string& name) const;

    bool loadFont(const std::string& name, const std::string& filename);
    const sf::Font& getFont(const std::string& name) const;

private:
    AssetManager() = default;

    template <typename T>
    const T& getResource(const std::map<std::string, T>& container, const std::string& name) const {
        auto it = container.find(name);
        if (it == container.end()) {
            throw std::runtime_error("Resource not found: " + name);
        }
        return it->second;
    }

    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
};
