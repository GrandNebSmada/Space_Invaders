Space_Invaders: Setup
	./Space_Invaders

Setup:
	clear
	clang++ -o Space_Invaders Entities.cpp main.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17