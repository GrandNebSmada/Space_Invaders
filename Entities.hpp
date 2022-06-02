#ifndef ENTITIES_H
#define ENTITIES_H

#include "olcPixelGameEngine.h"


//////////////////////////////////////////////////////////////////////////

class Entity {
public:
    Entity();
    Entity(olc::PixelGameEngine*, olc::vf2d pos = {0.0f, 0.0f}, int l = 0);
    Entity(const Entity&);
    ~Entity() {};

    void     swap       (Entity&);
    Entity&  operator=  (Entity*);

    void      SetPosition(const olc::vf2d); 
	olc::vf2d GetPosition() const;
    float       GetX       () const { return position.x; };
    float       GetY       () const { return position.y; };
    virtual void      Draw       () const;

//protected:
    olc::PixelGameEngine* pge;
    olc::vf2d position;
    int lives;

};


//////////////////////////////////////////////////////////////////////////

class Ship : public Entity {
public:
    using Entity::Entity;

    using Entity::swap;
    using Entity::operator=;

    void Draw () const override;

};

////////////////////////////////////////////////////////////////////////// 

class Alien : public Entity {
public:
    using Entity::Entity;

    using Entity::swap;
    using Entity::operator=;

    void Draw () const override;

};

#endif