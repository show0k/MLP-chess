#include "Chess.hpp"


int main(int argc,char  **argv){
	sf::Thread thread(&GUI);
	thread.launch();
	return EXIT_SUCCESS;
}


