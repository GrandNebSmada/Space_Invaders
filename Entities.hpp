#ifndef ENTITIES_H
#define ENTITIES_H

#include "olcPixelGameEngine.h"


//////////////////////////////////////////////////////////////////////////

class Entity {
public:
    Entity(); //Default Constructor
    Entity(olc::PixelGameEngine* pge_, const std::string& spritePath_= "", olc::vf2d position_ = {0.0f, 0.0f}, int lives_ = 0); //Constructor
    Entity(const Entity&); //Copy Constructor
    ~Entity() {}; //Destructor

    void     swap       (Entity&);
    Entity&  operator=  (Entity*);

    void      SetPosition(const olc::vf2d); 
	olc::vf2d GetPosition() const;
    float     GetX       () const { return position.x; };
    float     GetY       () const { return position.y; };

    virtual olc::vi2d GetSpriteSection(const int) const;
    virtual void      Draw(float);

protected:
    olc::PixelGameEngine* pge;
    olc::vf2d position;
    int lives;
    
    std::unique_ptr<olc::Sprite> sprite;
    std::unique_ptr<olc::Decal> decal;
    float frame;
};


//////////////////////////////////////////////////////////////////////////

class Ship : public Entity {
public:
    using Entity::Entity;

    using Entity::swap;
    using Entity::operator=;

    using Entity::GetSpriteSection;

    olc::vi2d GetSpriteSection(const int) const override;
    void      Draw (float) override;

};

////////////////////////////////////////////////////////////////////////// 

class Alien : public Entity {
public:
    using Entity::Entity;

    using Entity::swap;
    using Entity::operator=;

    
    void Draw (float) override;

};

#endif