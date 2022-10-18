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

		for(int x_ = 0; x_ < 15; ++x_){
			std::vector<std::shared_ptr<Alien>> temp;

			for (int y_ = 0; y_ < 5; ++y_){
				olc::vf2d InitPosition = {float((x_+1)*30), float((y_+1)*20)};
				temp.push_back(std::make_shared<Alien>(this, alienSpritePath, InitPosition, 1));
				
				temp[y_]->SetNum((y_*15+x_)+1);
			}
			aliens.push_back(temp);
		}

		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		std::cout << "\nx - aliens.size()    : " << aliens.size();
		std::cout << "\ny - aliens[0].size() : " << aliens[0].size();
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl;
		
		for(int y_ = 0; y_ < aliens[0].size(); ++y_){
			for (int x_ = 0; x_ < aliens.size(); ++x_){
				std::cout << aliens[x_][y_]->entityNumber << "{" << int(aliens[x_][y_]->GetX()) << "," << int(aliens[x_][y_]->GetY()) << "}, \t";
			}
			std::cout << std::endl;
		}

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {
		if (GetKey(olc::ESCAPE).bPressed) return false;

		aliveAliens = checkAliens();
		DrawString(10, 10, std::to_string(aliveAliens), olc::WHITE, 1);
		moveAliens(fElapsedTime);
        DrawGame(fElapsedTime);

		return true;
	}

	int checkAliens() {
		int count = 0;

		for(int y_ = 0; y_ < aliens[0].size(); ++y_){
			for (int x_ = 0; x_ < aliens.size(); ++x_){
				if(aliens[x_][y_]->IsAlive()) ++count;
				else continue;

			
				if(y_ + 1 < aliens[0].size()) {
					if(aliens[x_][y_]->GetY() < aliens[x_][y_+1]->GetY() && !aliens[x_][y_]->isTop) {
						aliens[x_][y_]->isTop = true;
					}else{
						aliens[x_][y_]->isTop = false;
					}
				}

				int yInv = aliens[x_].size() - y_;
				
				if(yInv - 1 >= 0 && yInv < aliens[x_].size()){
					if(!(aliens[x_][yInv]->IsAlive())) continue;

					if(aliens[x_][yInv]->GetY() > aliens[x_][yInv - 1]->GetY()) {
						aliens[x_][yInv]->isBottom = true;
					}else{
						aliens[x_][yInv]->isBottom = false;
					}
				}
			}
		}
		
		
		return count;
	}

	void moveAliens(float fElapsedTime){
		for(int y_ = 0; y_ < aliens[0].size(); ++y_){
			for (int x_ = 0; x_ < aliens.size(); ++x_){
				aliens[x_][y_]->SetX(aliens[x_][y_]->GetX()+5*fElapsedTime*(76-aliveAliens));
			}
		}
		return;
	}

	void DrawGame(float &fElapsedTime) {
		Clear(olc::BLANK);

		//ship->Draw(fElapsedTime);

		for(int y_ = 0; y_ < aliens[0].size(); ++y_){
			for (int x_ = 0; x_ < aliens.size(); ++x_){
			//std::cout << "Drawing alien: " << i*j << " " << i << ","  << std::endl;
				aliens[x_][y_]->Draw(fElapsedTime);
			}
		}
		
		//DrawString({10, 5}, std::to_string(aliveAliens));
	}
};



int main() {
	Space_Invaders game;
	if (game.Construct(640, 360, 2, 2))
		game.Start();
	return 0;
}