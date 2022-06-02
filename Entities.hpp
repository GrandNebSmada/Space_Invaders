#ifndef ENTITIES_H
#define ENTITIES_H

#include "olcPixelGameEngine.h"


//////////////////////////////////////////////////////////////////////////

class Entity {
public:
    Entity(); //Default Constructor
    Entity(olc::PixelGameEngine*, const std::string& = "", olc::vf2d = {0.0f, 0.0f}, int = 0); //Constructor
    Entity(const Entity&); //Copy Constructor
    ~Entity() {}; //Destructor

    void     swap       (Entity&);
    Entity&  operator=  (Entity*);

    void      SetPosition(const olc::vf2d); 
	olc::vf2d GetPosition() const;
    float       GetX       () const { return position.x; };
    float       GetY       () const { return position.y; };
    virtual void      Draw       () const;
    virtual olc::vi2d GetSpriteSection(const int) const;

protected:
    olc::PixelGameEngine* pge;
    olc::vf2d position;
    int lives;
    
    std::unique_ptr<olc::Sprite> sprite;
    int frame;
};


//////////////////////////////////////////////////////////////////////////

class Ship : public Entity {
public:
    using Entity::Entity;

    using Entity::swap;
    using Entity::operator=;

    using Entity::GetSpriteSection;

    void Draw () const override;
    olc::vi2d GetSpriteSection(const int) const override;

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