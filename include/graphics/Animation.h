#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
public:
    Animation(const sf::Texture& texture, int frameWidth, int frameHeight, int frameCount, float frameTime);

    void update(float dt);
    void setPosition(float x, float y);
    void setFlipX(bool flip);
    
    // Новые методы для гибкого управления анимацией
    void restart();
    void setLooped(bool looped);
    bool isFinished() const;

    const sf::Sprite& getSprite() const;
    sf::FloatRect getBounds() const;

private:
    sf::Sprite m_sprite;
    std::vector<sf::IntRect> m_frames;
    float m_frameTime;
    float m_elapsedTime = 0.f;
    size_t m_currentFrame = 0;
    bool m_isLooped = true;
    bool m_isFinished = false;
};
