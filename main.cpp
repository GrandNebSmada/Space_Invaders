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

std::string shipSpritePath = "./Sprites/Spaceship.png";
std::string alienSpritePath = "./Sprites/Alien.png";
std::string laserSpritePath = "";

class Space_Invaders : public olc::PixelGameEngine {
protected:
	Entity* ship;
	Entity* alien[];

public:
	Space_Invaders() {
		sAppName = "Space Invaders";
	}

public:
	bool OnUserCreate() override {
		ship   = new Ship(this, shipSpritePath,  {15.0f, 15.0f}, 3);
		alien  = new Alien[90];

		for(int j = 0; j < 15; ++j){
			for (int i = 0; i < 5; ++i){
				alien[i*j](this, alienSpritePath, {30.0f, 30.0f}, 1);
				alien[i*j]->SetPosition(i, j);
			}
		}
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

		ship->SetPosition({float(GetMouseX()), float(GetMouseY())});

        DrawGame(fElapsedTime);

		return true;
	}

	void DrawGame(float fET) {
		Clear(olc::BLANK);

		ship->Draw(fET);

		for(int j = 0; j < 15; ++j){
			for (int i = 0; i < 5; ++i){
				alien[i*l]->Draw(fET);
			}
		}
	}
};



int main() {
	Space_Invaders game;
	if (game.Construct(640, 360, 2, 2))
		game.Start();
	return 0;
}