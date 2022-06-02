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

Entity::Entity(olc::PixelGameEngine* pge_, const std::string& sprite_, olc::vf2d pos, int l) { //Constructor
    pge = pge_;
    position = pos;
    lives = l;

    sprite = std::make_unique<olc::Sprite>(sprite_);
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


void Entity::Draw() const {
    pge->DrawRect(position, olc::vi2d(olc::vf2d{10.0f, 10.0f}), olc::RED);
    pge->DrawLine(position, olc::vi2d(olc::vf2d{position.x + 10.0f, position.y + 10.0f}), olc::RED);
    pge->DrawLine(olc::vi2d(olc::vf2d{position.x, position.y + 10.0f}), olc::vi2d(olc::vf2d{position.x + 10.0f, position.y}), olc::RED);
}


//////////////////////////////////////////////////////////////////////////
//Ship Class Declarations
//////////////////////////////////////////////////////////////////////////
olc::vi2d Entity::GetSpriteSection(const int f) const {}

olc::vi2d Ship::GetSpriteSection(const int f) const {
        switch (f) {
            case 0:
                return {5, 0};
            case 1:
                return {37, 0};
            case 2:
                return {5, 32};
            case 3:
                return {37, 32};
        }
    return {0, 0};
}

void Ship::Draw() const {
    pge->DrawPartialSprite({50, 50}, sprite.get(), GetSpriteSection(3), {25, 32});
}

//////////////////////////////////////////////////////////////////////////
//Alien Class Declarations
//////////////////////////////////////////////////////////////////////////

void Alien::Draw() const {
    pge->DrawCircle(olc::vi2d(olc::vf2d{position.x + 5.0f, position.y + 5.0f}), 5, olc::BLUE);
    olc::vi2d newPos = olc::vi2d(olc::vf2d{position.x + 2, position.y + 2});
    pge->DrawLine(newPos, olc::vi2d(olc::vf2d{position.x +8.0f, position.y + 8.0f}), olc::BLUE);
    pge->DrawLine(olc::vi2d(olc::vf2d{position.x, position.y + 9.0f}), olc::vi2d(olc::vf2d{position.x + 9.0f, position.y}), olc::BLUE);
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