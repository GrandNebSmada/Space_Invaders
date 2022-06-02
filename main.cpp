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

public:
	Space_Invaders() {
		sAppName = "Space Invaders";
	}

public:
	bool OnUserCreate() override {
		entity = new Entity(this);
		ship = new Entity(this);

		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

        Clear(olc::BLANK);
		
		entity->Draw();
		ship->Draw();

		ship->SetPosition({ship->GetX() + 1.0f * fElapsedTime, ship->GetY()});

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