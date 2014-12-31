#include "Chess.hpp"

int main(int argc,char  **argv){
	bool check = true;
	sf::Thread thread(&GUI);
	thread.launch(); 
	string s ="";
	while(stringContains(s,"exit")){
		s = getResult();
		parseAction(s);
	}
	//cout<<"ici et la"<<endl;
	thread.wait ();
	return EXIT_SUCCESS;
}


