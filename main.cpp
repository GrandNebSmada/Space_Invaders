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
#include <vector>

std::string shipSpritePath = "./Sprites/Spaceship.png";
std::string alienSpritePath = "./Sprites/Alien.png";
std::string laserSpritePath = "";

class Space_Invaders : public olc::PixelGameEngine {
protected:
	Entity* ship;
	std::vector<Entity*> aliens;

	int aliveAliens;

public:
	Space_Invaders() {
		sAppName = "Space Invaders";
	}

public:
	bool OnUserCreate() override {
		ship  = new Ship(this, shipSpritePath,  {15.0f, 15.0f}, 3);

		for(int j = 0; j < 5; ++j){
			for (int i = 0; i < 15; ++i){
				aliens.push_back(new Alien(this, alienSpritePath, {float((i+1)*30), float((j+1)*20)}, 1));
				//aliens[j*15+i]->SetNum((j*15+i)+1);
				//aliveAliens = checkAliens();
			}
		}
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

		ship->SetPosition({float(GetMouseX()), float(GetMouseY())});

		aliveAliens = checkAliens();
		moveAliens(fElapsedTime);
        DrawGame(fElapsedTime);

		return true;
	}

	int checkAliens() {
		int count = 0;
		for (int i = 0; i < 75; ++i){
			count += aliens[i]->IsAlive();
		}
		return count;
	}

	void moveAliens(float fElapsedTime){
		for (int i = 0; i < 75; ++i){
			//if ()
			aliens[i]->SetX(aliens[i]->GetX()+5*fElapsedTime*(76-aliveAliens));
		}
		return;
	}

	void DrawGame(float &fElapsedTime) {
		Clear(olc::BLANK);

		ship->Draw(fElapsedTime);

		for (int i = 0; i < 75; ++i){
			//std::cout << "Drawing alien: " << i*j << " " << i << ","  << std::endl;
			aliens[i]->Draw(fElapsedTime);
		}
		
		DrawString({10, 5}, std::to_string(aliveAliens));
	}
};



int main() {
	Space_Invaders game;
	if (game.Construct(640, 360, 2, 2))
		game.Start();
	return 0;
}