#include "olcPixelGameEngine.h"
#include "Entities.hpp"


//////////////////////////////////////////////////////////////////////////
//Ship Class Declarations
//////////////////////////////////////////////////////////////////////////

Entity::Entity() { //Default Constructor
    pge = nullptr;
    position = {0.0f, 0.0f};
    lives = 1;
}

Entity::Entity(olc::PixelGameEngine* pge_, olc::vf2d pos, int l) {
    pge = pge_;
    position = pos;
    lives = l;
}

Entity::Entity(const Entity& actual) { //Copy Constructor
    pge = actual.pge;
    position = actual.position;
    lives = actual.lives;

}

void Entity::swap(Entity& rhs) {
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

Entity& Entity::operator=(Entity* rhs) {
    swap(*rhs);
    return *this;
}

void Entity::SetPosition(const olc::vf2d& input) {
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
//Alien Class Declarations
//////////////////////////////////////////////////////////////////////////

void Ship::Draw() const {
    pge->DrawRect(position, olc::vi2d(olc::vf2d{position.x, position.y}), olc::GREEN);
    pge->DrawLine(position, olc::vi2d(olc::vf2d{position.x + 10.0f, position.y + 10.0f}), olc::RED);
    pge->DrawLine(olc::vi2d(olc::vf2d{position.x, position.y + 10.0f}), olc::vi2d(olc::vf2d{position.x + 10.0f, position.y}), olc::RED);
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