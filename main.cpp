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
#include <memory>

std::string shipSpritePath = "./Sprites/Spaceship.png";
std::string alienSpritePath = "./Sprites/Alien.png";
std::string laserSpritePath = "";

class Space_Invaders : public olc::PixelGameEngine {
protected:
	std::unique_ptr<Entity> ship;
	std::vector<std::vector<std::shared_ptr<Alien>>> aliens;

	int aliveAliens;

public:
	Space_Invaders() {
		sAppName = "Space Invaders";
	}

public:
	bool OnUserCreate() override {
		//ship  = new Ship(this, shipSpritePath,  {15.0f, 15.0f}, 3);

		for(int y_ = 0; y_ < 5; ++y_){
			std::vector<std::shared_ptr<Alien>> temp;

			for (int x_ = 0; x_ < 15; ++x_){
				olc::vf2d tempCoordinate = {float((x_+1)*30), float((y_+1)*20)};
				temp.push_back(std::make_shared<Alien>(this, alienSpritePath, tempCoordinate));
				//aliens.push_back(new Alien(this, alienSpritePath, {float((i+1)*30), float((j+1)*20)}, 1));
				//aliens[j*15+i]->SetNum((j*15+i)+1);
				//aliveAliens = checkAliens();
			}
			aliens.push_back(temp);
		}
		
		
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

		ship->SetPosition({float(GetMouseX()), float(GetMouseY())});

		//aliveAliens = checkAliens();
		//moveAliens(fElapsedTime);
        DrawGame(fElapsedTime);

		return true;
	}

	// int checkAliens() {
	// 	int count = 0;
	// 	for(int y_ = 0; y_ < 5; ++y_){
	// 		for (int x_ = 0; x_ < 15; ++x_){
	// 			count += aliens[x_][y_]->IsAlive();
	// 		}
	// 	}

	// 	return count;
	// }

	// void moveAliens(float fElapsedTime){
	// 	for(int y_ = 0; y_ < 5; ++y_){
	// 		for (int x_ = 0; x_ < 15; ++x_){
	// 			aliens[x_][y_]->SetX(aliens[x_][y_]->GetX()+5*fElapsedTime*(76-aliveAliens));
	// 		}
	// 	}
	// 	return;
	// }

	void DrawGame(float &fElapsedTime) {
		Clear(olc::BLANK);

		ship->Draw(fElapsedTime);

		// for(int y_ = 0; y_ < 5; ++y_){
		// 	for (int x_ = 0; x_ < 15; ++x_){
		// 	//std::cout << "Drawing alien: " << i*j << " " << i << ","  << std::endl;
		// 		aliens[x_][y_]->Draw(fElapsedTime);
		// 	}
		// }
		
		DrawString({10, 5}, std::to_string(aliveAliens));
	}
};



int main() {
	Space_Invaders game;
	if (game.Construct(640, 360, 2, 2))
		game.Start();
	return 0;
}