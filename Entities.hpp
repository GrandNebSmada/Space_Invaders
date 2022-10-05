#ifndef ENTITIES_H
#define ENTITIES_H

#include "olcPixelGameEngine.h"


//////////////////////////////////////////////////////////////////////////

//namespace SI {

class Entity {
public:
    Entity (); //Default Constructor
    Entity (olc::PixelGameEngine* pge_,            //reference to pge
            const std::string& spritePath_= "",    //path to sprite
            olc::vf2d position_ = {0.0f, 0.0f},    //initial position
            int lives_ = 0); //Constructor         //initial lives
    Entity (const Entity&); //Copy Constructor
    ~Entity() {}; //Destructor

    void      swap       (Entity&);
    Entity&   operator=  (Entity*);

    void      SetPGE     (olc::PixelGameEngine*);
    void      SetSprite  (const std::string&);
    void      SetPosition(const olc::vf2d); 
    void      SetX       (const float);
    void      SetY       (const float);
	olc::vf2d GetPosition() const;
    float     GetX       () const { return position.x; };
    float     GetY       () const { return position.y; };

    bool IsAlive() const;
    virtual olc::vi2d GetSpriteSection(const int) const;
    virtual void      Draw(float);


    void SetNum(int a){entityNumber = a;};
    int entityNumber = 0;
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
    using Entity::SetPGE;

    using Entity::SetSprite;

    void Draw (float) override;

    bool isRight = false;
    bool isLeft = false;
    bool isTop = false;
    bool isBottom = false;
};
//}
#endif