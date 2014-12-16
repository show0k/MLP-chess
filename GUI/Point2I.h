#ifndef includeIO
#define includeIO 1

#include <iostream>

using namespace std;

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
