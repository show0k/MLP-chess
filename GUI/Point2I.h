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
};

#endif
