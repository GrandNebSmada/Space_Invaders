#include "olcPixelGameEngine.h"
#include "Entities.hpp"


//////////////////////////////////////////////////////////////////////////
//Entity Class Declarations
//////////////////////////////////////////////////////////////////////////

Entity::Entity() { //Default Constructor
    pge = nullptr;
    position = {0.0f, 0.0f};
    lives = 1;
}

Entity::Entity(olc::PixelGameEngine* pge_, const std::string& spritePath_, olc::vf2d position_, int lives_) { //Constructor
    pge = pge_;
    position = position_;
    lives = lives_;

    sprite = std::make_unique<olc::Sprite>(spritePath_);
    decal = std::make_unique<olc::Decal>(sprite.get());
}

Entity::Entity(const Entity& actual) { //Copy Constructor
    pge = actual.pge;
    position = actual.position;
    lives = actual.lives;

}

void Entity::swap(Entity& rhs) { //const time swap
    olc::PixelGameEngine *pgeTemp = pge;
    pge = rhs.pge;
    rhs.pge = pgeTemp;

    olc::vf2d posTemp = position;
    position = rhs.position;
    rhs.position = posTemp;

    int livesTemp = lives;
    lives = rhs.lives;
    rhs.lives = livesTemp;

}

Entity& Entity::operator=(Entity* rhs) { //copy assignment
    swap(*rhs);
    return *this;
}

void Entity::SetPosition(const olc::vf2d input) {
    position = input;
}

olc::vf2d Entity::GetPosition() const {
    return position;
}

olc::vi2d Entity::GetSpriteSection(const int f) const {
    return {0, 0};
}

void Entity::Draw(float fElapsedTime) {
    if (lives < 1) return;
    
    pge->DrawRect(position, olc::vi2d(olc::vf2d{10.0f, 10.0f}), olc::RED);
    pge->DrawLine(position, olc::vi2d(olc::vf2d{position.x + 10.0f, position.y + 10.0f}), olc::RED);
    pge->DrawLine(olc::vi2d(olc::vf2d{position.x, position.y + 10.0f}), olc::vi2d(olc::vf2d{position.x + 10.0f, position.y}), olc::RED);
}


//////////////////////////////////////////////////////////////////////////
//Ship Class Declarations
//////////////////////////////////////////////////////////////////////////


olc::vi2d Ship::GetSpriteSection(const int f) const {
    olc::vi2d output;

    switch (f) {
    case 0:
        output = {5, 0};
        break;
    case 1:
        output = {37, 0};
        break;
    case 2:
        output = {5, 32};
        break;
    case 3:
        output = {37, 32};
        break;
    }

    return output;
}

void Ship::Draw(float fElapsedTime) {
    if (lives < 1) return;
    
    pge->DrawPartialDecal(position, decal.get(), GetSpriteSection(int(frame)), {25, 32});

    frame += 30 * fElapsedTime;
    if (frame > 3) frame = 0;
}

//////////////////////////////////////////////////////////////////////////
//Alien Class Declarations
//////////////////////////////////////////////////////////////////////////

void Alien::Draw(float fElapsedTime) {
    if (lives < 1) return;

    pge->DrawCircle(olc::vi2d(olc::vf2d{position.x + 5.0f, position.y + 5.0f}), 5, olc::BLUE);
}

//////////////////////////////////////////////////////////////////////////
//Laser Class Declarations
//////////////////////////////////////////////////////////////////////////
/*
Laser::Laser(olc::PixelGameEngine* pge_) {
    pge = pge_;
}

Laser::Laser(olc::PixelGameEngine* pge_, olc::vf2d pos, int l) {
    pge = pge_;
    position = pos;
    lives = l;
}

void Laser::SetPosition(const olc::vf2d& input) {
    position = input;
}

olc::vf2d Laser::GetPosition() const {
    return position;
}

void Laser::Draw(olc::PixelGameEngine* pge) const {
    pge->DrawRect(position, {2, 5}, olc::RED);
}

*/