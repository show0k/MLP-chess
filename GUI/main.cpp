#include "Chess.hpp"

int main(int argc,char  **argv){

	sf::Thread thread(&GUI);
	thread.launch(); 
	string s ="";
	while(s != "exit"){
		s = getResult();
		parseAction(s);
	}

	return EXIT_SUCCESS;
}


