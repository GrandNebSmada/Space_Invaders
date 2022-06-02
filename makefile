Space_Invaders: Space_Invaders.o
	./Space_Invaders

Space_Invaders.o:
	clear
	clang++ -o Space_Invaders Entities.cpp main.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17