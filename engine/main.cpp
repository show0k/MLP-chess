#include <string.h> 
#include <stdio.h> 
#include <iostream> 


#include "board.h"
#include "square.h"

using namespace std;

void testSquare (void){
        
        Square t = Square("b6");
        cout << "t = "<<t ;

}

int main()
{
        Board b = Board();
        b.newGame();
        b.display();


}