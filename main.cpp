//Space Invaders
//Ben Adams

/* Command to compile and run:

clear;
g++ -o Space_Invaders main.cpp Entities.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17;
./Space_Invaders

*/

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "Entities.hpp"



class Space_Invaders : public olc::PixelGameEngine {
protected:
	Entity* entity;
	Entity* ship;
	Entity* alien;

public:
	Space_Invaders() {
		sAppName = "Space Invaders";
	}

public:
	bool OnUserCreate() override {
		entity = new Entity(this);
		ship   = new Ship  (this, {15.0f, 15.0f});
		alien  = new Alien (this, {30.0f, 30.0f});

		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

        Clear(olc::BLANK);
		
		entity->Draw();
		ship->Draw();
		alien->Draw();

		// std::cout << "entity: " << entity->position.x << ", " << entity->position.y << std::endl
		//           << "ship:   " << ship->position.x << ", " << ship->position.y << std::endl
		// 		  << "alien:  " << alien->position.x << ", " << alien->position.y << std::endl << std::endl;

		//  ship->SetPosition({ ship->GetX() + 10.0f * fElapsedTime,  ship->GetY()                       });
		// alien->SetPosition({alien->GetX() + 10.0f * fElapsedTime, alien->GetY() + 10.0f * fElapsedTime});
        
		//void Clear();
		return true;
	}
};

int main() {
	Space_Invaders game;
	if (game.Construct(256, 256, 3, 3))
		game.Start();
	return 0;
}