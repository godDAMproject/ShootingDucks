#include "Animation.h"
#include <cmath>

Animation::Animation(const sf::Texture& texture, int frameWidth, int frameHeight, int frameCount, float frameTime)
    : m_frameTime(frameTime) {
    m_sprite.setTexture(texture);
    for (int i = 0; i < frameCount; ++i) {
        m_frames.emplace_back(i * frameWidth, 0, frameWidth, frameHeight);
    }
    if (!m_frames.empty()) {
        m_sprite.setTextureRect(m_frames[0]);
        m_sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
    }
}

void Animation::update(float dt) {
    if (m_frames.size() <= 1 || m_isFinished) {
        return;
    }
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_frameTime) {
        m_elapsedTime -= m_frameTime;
        if (m_currentFrame + 1 < m_frames.size()) {
            m_currentFrame++;
        } else if (m_isLooped) {
            m_currentFrame = 0;
        } else {
            m_isFinished = true;
        }
        m_sprite.setTextureRect(m_frames[m_currentFrame]);
    }
}

void Animation::setPosition(float x, float y) {
    m_sprite.setPosition(x, y);
}

void Animation::setFlipX(bool flip) {
    sf::Vector2f scale = m_sprite.getScale();
    float absX = std::abs(scale.x);
    m_sprite.setScale(flip ? -absX : absX, scale.y);
}

void Animation::restart() {
    m_currentFrame = 0;
    m_elapsedTime = 0.f;
    m_isFinished = false;
    if (!m_frames.empty()) {
        m_sprite.setTextureRect(m_frames[0]);
    }
}

void Animation::setLooped(bool looped) {
    m_isLooped = looped;
}

bool Animation::isFinished() const {
    return m_isFinished;
}

const sf::Sprite& Animation::getSprite() const {
    return m_sprite;
}

sf::FloatRect Animation::getBounds() const {
    return m_sprite.getGlobalBounds();
}
