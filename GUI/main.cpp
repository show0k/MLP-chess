/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#include "Chess.hpp"

void api_thread() {
    string s ="";
    while(s != "exit"){
        s = getResult();
        parseAction(s);
    }
}


int main(int argc,char  **argv){

    sf::Thread thread(&api_thread);
    thread.launch(); 
    GUI() ;

	return EXIT_SUCCESS;
}

