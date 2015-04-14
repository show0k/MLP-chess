/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#ifndef includeIO
#define includeIO 1

#include <iostream>
#include <sstream>

using namespace std;
string intToString(int x);
class Point2I{
	private:
		int x;
		int y;
	
	public:
		Point2I(int, int);
		Point2I();
		~Point2I();
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		string toString();
		bool operator==(Point2I const& p);
};

#endif
